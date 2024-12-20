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
    int n;
    cin >> n;

    vector<vector<int>> adj(n);
    vector<int> deg(n);
    vector<pair<int, int>> edges;

    for(int i = 0; i < n - 1; ++i){
        int u, v;
        cin >> u >> v;
        --u, --v;

        adj[u].push_back(v);
        adj[v].push_back(u);

        edges.push_back({u,v});

        ++deg[u], ++deg[v];
    }

    int num_operations = *max_element(deg.begin(), deg.end());

    vector<vector<int>> operations;

    while(!edges.empty()){
        vector<int> color(n);
        for(int i = 0; i < n; ++i){
            color[i] = i + 1;
        }

        vector<vector<int>> adj(n);
        for(auto [u, v]: edges){
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int mx = *max_element(deg.begin(), deg.end());

        vector<bool> vis(n);
        function<void(int, int)> dfs = [&](int u, int p){
            vis[u] = true;
            if(deg[u] == mx){
                for(int v: adj[u]){
                    if(v != p){
                        --deg[u], --deg[v];
                        color[v] = color[u];
                        break;
                    }
                }
            }
            for(int v: adj[u]){
                if(v != p){
                    dfs(v, u);
                }
            }
        };

        for(int i = 0; i < n; ++i){
            if(!vis[i]){
                dfs(i, -1);
            }
        }

        vector<pair<int, int>> rem_edges;
        for(auto [u, v]: edges){
            if(color[u] != color[v]){
                rem_edges.push_back({u, v});
            }
        }

        edges = rem_edges;
        operations.push_back(color);
    }

    assert(num_operations == operations.size());

    cout << operations.size() << '\n';
    for(vector<int> &coloring: operations){
        for(int elem: coloring){
            assert((1 <= elem) && (elem <= n));
            cout << elem << ' ';
        }
        cout << '\n';
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
 
