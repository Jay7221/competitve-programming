#include <bits/stdc++.h>
 
using namespace std;
 
//#pragma GCC optimize("Ofast,unroll-loops") 
//#pragma GCC target("avx,avx2,avx512,fma") 
 
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif
 
#define ll long long
#define ld long double
 
#define PI 3.1415926535897932384626433832795l 

// -------------------------<rng>------------------------- 
// RANDOM NUMBER GENERATOR
mt19937 RNG(chrono::steady_clock::now().time_since_epoch().count());  
#define SHUF(v) shuffle(all(v), RNG); 
// Use mt19937_64 for 64 bit random numbers.
 

// Helper function to convert time to minutes since midnight
int timeToMinutes(const string& timeStr) {
    int hour, minute;
    char meridian[3]; // AM/PM
    stringstream ss(timeStr);
    ss >> hour;
    ss.ignore(1); // ignore ':'
    ss >> minute;
    ss >> meridian;
    
    if (meridian[0] == 'P' && hour != 12) {
        hour += 12; // Convert PM hours to 24-hour format
    } else if (meridian[0] == 'A' && hour == 12) {
        hour = 0; // Convert 12 AM to 00:00
    }
    return hour * 60 + minute;
}

int main() {
    int N;
    cin >> N;
    
    vector<string> from(N), to(N);
    vector<int> takeOff(N), landing(N), cost(N);
    
    // Reading flight details
    for (int i = 0; i < N; ++i) {
        string takeOffTime, landingTime;
        cin >> from[i] >> to[i] >> takeOffTime >> landingTime >> cost[i];
        takeOff[i] = timeToMinutes(takeOffTime);
        landing[i] = timeToMinutes(landingTime);
    }
    
    string startCity, endCity, startTimeStr, endTimeStr;
    cin >> startCity >> endCity >> startTimeStr >> endTimeStr;
    
    int startTime = timeToMinutes(startTimeStr);
    int endTime = timeToMinutes(endTimeStr);
    
    // Graph adjacency list: map city -> list of flights departing from that city
    unordered_map<string, vector<int>> adj;
    for (int i = 0; i < N; ++i) {
        adj[from[i]].push_back(i); // Store index of flight
    }

    // Dijkstra's algorithm using priority queue
    priority_queue<tuple<int, int, string>, vector<tuple<int, int, string>>, greater<tuple<int, int, string>>> pq;
    unordered_map<string, int> minCost;
    
    pq.push({0, startTime, startCity}); // (cost, time) -> start with 0 cost and start time
    minCost[startCity] = 0;
    
    while (!pq.empty()) {
        auto [currentCost, currentTime, currentCity] = pq.top();
        pq.pop();
        
        // If we reached the destination city, return the cost
        if (minCost.find(endCity) != minCost.end() && currentCost > minCost[endCity]) {
            break;
        }
        
        // Explore all flights from the current city
        for (int i : adj[currentCity]) {
            // Check if the flight is within time constraints
            if (takeOff[i] >= currentTime && landing[i] <= endTime) {
                int newCost = currentCost + cost[i];
                if(minCost.find(to[i]) == minCost.end() || newCost < minCost[to[i]]){
                    minCost[to[i]] = newCost;
                    pq.push({newCost, landing[i], to[i]});
                }
            }
        }
    }

    if (minCost.find(endCity) != minCost.end()) {
        cout << minCost[endCity];
    } else {
        cout << "Impossible";
    }
    
    return 0;
}
