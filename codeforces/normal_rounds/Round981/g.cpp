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
 
const int LOGMAX = 20;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> adj(n);

    for(int i = 0; i < n - 1; ++i){
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> depth(n);
    vector<int> max_depth_leaf(n);
    vector<vector<int>> par(n, vector<int>(LOGMAX));
    vector<vector<int>> max_dist_above(n, vector<int>(LOGMAX));
    // max_dist_above[u][s] = maximum dist of leaf node reachable from u by going above at most s times, that is with at most s stamina

    function<void(int, int)> dfs = [&](int u, int p){
        int max_depth = depth[u];
        int max_depth2 = depth[u];

        for(int v: adj[u]){
            if(v != p){
                depth[v] = depth[u] + 1;
                par[v][0] = u;

                dfs(v, u);

                if(max_depth_leaf[v] > max_depth){
                    max_depth2 = max_depth;
                    max_depth = max_depth_leaf[v];
                }
                else if(max_depth_leaf[v] > max_depth2){
                    max_depth2 = max_depth_leaf[v];
                }
            }
        }

        for(int v: adj[u]){
            if(v != p){
                if(max_depth_leaf[v] == max_depth){
                    max_dist_above[v][0] = 1 + (max_depth2 - depth[u]);
                }
                else{
                    max_dist_above[v][0] = 1 + (max_depth - depth[u]);
                }
            }
        }

        max_depth_leaf[u] = max_depth;
    };

    dfs(0, -1);

    for(int k = 1; k < LOGMAX; ++k){
        for(int u = 0; u < n; ++u){
            par[u][k] = par[par[u][k - 1]][k - 1];
            max_dist_above[u][k] = max(max_dist_above[u][k - 1], (1 << (k - 1)) + max_dist_above[par[u][k - 1]][k - 1]);
        }
    }

    int q;
    cin >> q;
    while(q--){
        int u, stamina;
        cin >> u >> stamina;
        --u;
        stamina = min(stamina, depth[u]);

        int res = max_depth_leaf[u] - depth[u];

        int curNode = u;
        int curDist = 0;

        for(int k = 0; k < LOGMAX; ++k){
            if(1 & (stamina >> k)){
                res = max(res, curDist + max_dist_above[curNode][k]);
                curDist += (1 << k);
                curNode = par[curNode][k];
            }
        }

        cout << res << ' ';
    }
    cout << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; ++t){
//        cout << "# Case " << i << " : ";
        solve();
    }
    
    return 0;
}
 
