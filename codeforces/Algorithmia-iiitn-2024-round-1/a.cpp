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
 
const ll INF = 1e18 + 7;

#define ti tuple<ll, int, int>
 
void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> adj(n);

    for(int i = 0; i < m; ++i){
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        adj[u].push_back(make_pair(v, w));
    }

    vector<vector<ll>> dp(n, vector<ll>(3, INF));

    priority_queue<ti, vector<ti>, greater<ti>> pq;
    pq.push({0, 0, 0});
    dp[0][0] = 0;

    while(!pq.empty()){
        ll dist;
        int u, state;
        tie(dist, u, state) = pq.top();
        pq.pop();

        if(dp[u][state] < dist){
            continue;
        }

        if(u == n - 1){
            break;
        }

        for(auto [v, w]: adj[u]){
            if(state == 0){ // nothing used
                if(dp[v][0] > dist + w){
                    dp[v][0] = dist + w;
                    pq.push({dp[v][0], v, 0});
                }
                if(dp[v][1] > dist + w / 2){
                    dp[v][1] = dist + w / 2;
                    pq.push({dp[v][1], v, 1});
                }
            }
            else if(state == 1){
                if(dp[v][2] > dist + w / 2){
                    dp[v][2] = dist + w / 2;
                    pq.push({dp[v][2], v, 2});
                }
            }
            else{
                if(dp[v][2] > dist + w){
                    dp[v][2] = dist + w;
                    pq.push({dp[v][2], v, 2});
                }
            }
        }
    }

    cout << *min_element(dp[n - 1].begin(), dp[n - 1].end()) << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    solve();
    
    return 0;
}
 
