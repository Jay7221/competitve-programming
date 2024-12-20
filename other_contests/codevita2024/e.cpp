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
 
 

// Function to compute the initial angle between hour and minute hands
int computeInitialAngle(int hours, int minutes) {
    // Calculate the angles
    int hourAngle = hours * 30.0;  // Each hour represents 30 degrees
    int minuteAngle = minutes * 6.0;  // Each minute represents 6 degrees
    
    return (hourAngle - minuteAngle + 360) % 360;
}
const int INF = 1e9 + 7;

// Function to calculate the cost of forming the desired angle
int calculateCost(int &hourAngle, int &minuteAngle, int desiredAngle, int clockwiseCost, int counterClockwiseCost, int hourCost, int minuteCost) {
    int res = INF;

    int currentAngle, cost;
    int newHourAngle = hourAngle;
    int newMinuteAngle = minuteAngle;
    int curHourAngle;

    currentAngle = (minuteAngle - hourAngle + 360) % 360;
    curHourAngle = hourAngle;
    cost = 0;
    while(currentAngle >= desiredAngle){
        int curCost = cost + (currentAngle - desiredAngle) * minuteCost * counterClockwiseCost;
        if(res > curCost){
            res = curCost;
            newHourAngle = (curHourAngle + 360) % 360;
            newMinuteAngle = (desiredAngle + newHourAngle + 360) % 360;
        }

        currentAngle -= 30;
        curHourAngle += 30;
        cost += 30 * hourCost * clockwiseCost;
    }

    currentAngle = (minuteAngle - hourAngle + 360) % 360;
    curHourAngle = hourAngle;
    cost = 0;
    while(currentAngle <= desiredAngle){
        int curCost = cost + (desiredAngle - currentAngle) * minuteCost * clockwiseCost;
        if(res > curCost){
            res = curCost;
            newHourAngle = (curHourAngle + 360) % 360;
            newMinuteAngle = (desiredAngle + newHourAngle + 360) % 360;
        }
        currentAngle += 30;
        curHourAngle -= 30;
        cost += 30 * hourCost * counterClockwiseCost;
    }

    currentAngle = (hourAngle - minuteAngle + 360) % 360;
    curHourAngle = hourAngle;
    cost = 0;
    while(currentAngle >= desiredAngle){
        int curCost = cost + (currentAngle - desiredAngle) * minuteCost * clockwiseCost;
        if(res > curCost){
            res = curCost;
            newHourAngle = (curHourAngle + 360) % 360;
            newMinuteAngle = (newHourAngle - desiredAngle + 360) % 360;
        }
        currentAngle -= 30;
        curHourAngle -= 30;
        cost += 30 * hourCost * counterClockwiseCost;
    }

    currentAngle = (hourAngle - minuteAngle + 360) % 360;
    curHourAngle = hourAngle;
    cost = 0;
    while(currentAngle <= desiredAngle){
        int curCost = cost + (desiredAngle - currentAngle) * minuteCost * counterClockwiseCost;
        if(res > curCost){
            res = curCost;
            newHourAngle = (curHourAngle + 360) % 360;
            newMinuteAngle = (newHourAngle - desiredAngle + 360) % 360;
        }
        currentAngle += 30;
        curHourAngle += 30;
        cost += 30 * hourCost * clockwiseCost;
    }

    hourAngle = (newHourAngle + 360) % 360;
    minuteAngle = (newMinuteAngle + 360) % 360;

    return res;
}

int main() {
    string time;
    int Q, A, B, X, Y;
    cin >> time;
    cin >> Q;
    cin >> A >> B >> X >> Y;
    
    // Parse the time
    int hours = stoi(time.substr(0, 1));
    int minutes = stoi(time.substr(2, 2));

    int hourAngle = hours * 30;
    int minuteAngle = minutes * 6;

    int totalCost = 0;
    
    // For each query, calculate the cost
    for (int i = 0; i < Q; i++) {
        int angle;
        cin >> angle;
        totalCost += calculateCost(hourAngle, minuteAngle, angle, A, B, X, Y);
    }

    cout << totalCost;
    
    return 0;
}
