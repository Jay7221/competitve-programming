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
 
void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> edges;
    vector<vector<int>> adj(n);
    vector<vector<int>> rev_adj(n);

    for(int i = 0; i < m; ++i){
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(edges.size());
        rev_adj[v].push_back(edges.size());
        edges.push_back({u, v});
    }

    vector<bool> mark(m);
    vector<bool> vis(n);
    vector<int> path;

    function<void(int)> euler_dfs = [&](int u){
        vis[u] = true;
        for(int eu: adj[u]){
            int v = edges[eu][1];
            if(!vis[v]){
                mark[eu] = true;
                euler_dfs(v);
            }
        }
        path.push_back(u);
    };
    euler_dfs(0);

    function<void(int)> rev_dfs = [&](int u){
        vis[u] = true;
        for(int eu: rev_adj[u]){
            int v = edges[eu][0];
            if(!vis[v]){
                mark[eu] = true;
                rev_dfs(v);
            }
        }
        path.push_back(u);
    };
    vis.assign(n, false);
    rev_dfs(0);

    int cnt = 0;
    for(int i = 0; i < m; ++i){
        if(mark[i]){
            ++cnt;
        }
    }
    for(int i = 0; i < m; ++i){
        if((cnt < 2 * n) && !mark[i]){
            ++cnt;
            mark[i] = true;
        }
    }

    for(int i = 0; i < m; ++i){
        if(!mark[i]){
            cout << edges[i][0] + 1 << ' ' << edges[i][1] + 1 << '\n';
        }
    }

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
 
