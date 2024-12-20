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
 
void dfs(int u, vector<vector<int>> &adj, vector<bool> &vis, string &s, vector<int> &freq){
    vis[u] = true;
    ++freq[s[u] - 'a'];

    for(int v: adj[u]){
        if(!vis[v]){
            dfs(v, adj, vis, s, freq);
        }
    }
}
 
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<vector<int>> adj(n);

    auto add_edge = [&](int u, int v){
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    };

    vector<bool> isprime(n + 1, true);
    for(int p = 2; p <= n; ++p){
        if(isprime[p]){
            for(int j = 2; j * p <= n; ++j){
                isprime[j * p] = false;
                add_edge(p, j * p);
            }
        }
    }

    vector<bool> vis(n);

    int res = 0;

    for(int i = 0; i < n; ++i){
        if(vis[i]){
            continue;
        }
        vector<int> freq(26);

        dfs(i, adj, vis, s, freq);

        res += accumulate(freq.begin(), freq.end(), 0) - *max_element(freq.begin(), freq.end());
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
 
