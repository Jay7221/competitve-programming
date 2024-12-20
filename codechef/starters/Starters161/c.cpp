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
    int n, k;
    cin >> n >> k;

    vector<vector<int>> adj(n);
    for(int i = 0; i < n - 1; ++i){
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> subtree_size(n, 1);
    vector<int> depth(n);
    vector<int> par(n);

    function<void(int, int)> dfs = [&](int u, int p){
        par[u] = p;
        for(int v: adj[u]){
            if(v != p){
                depth[v] = depth[u] + 1;
                dfs(v, u);
                subtree_size[u] += subtree_size[v];
            }
        }
    };

    dfs(0, -1);

    vector<int> blocking_subtrees;

    int cur = n - 1;
    while(par[cur] != -1){
        for(int v: adj[par[cur]]){
            if((v != cur) && (v != par[par[cur]])){
                blocking_subtrees.push_back(subtree_size[v]);
            }
        }
        cur = par[cur];
    }

    int res = depth[n - 1] + 1;


    sort(blocking_subtrees.rbegin(), blocking_subtrees.rend());

    for(int i = k - 1; i < (int)blocking_subtrees.size(); ++i){
        res += blocking_subtrees[i];
    }

    cout << res << '\n';
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
 
