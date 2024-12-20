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

    vector<pair<int, int>> edges;
    for(int i = 0; i < m; ++i){
        int u, v;
        cin >> u >> v;
        --u, --v;
        edges.push_back({u, v});
    }

    vector<set<int>> adj(n);
    for(auto [u, v]: edges){
        if(u < v){
            swap(u, v);
        }
        if(u != v){
            adj[u].insert(v);
        }
    }

    auto flip = [&](int v){
        if(adj[n - 1].find(v) == adj[n - 1].end()){
            adj[n - 1].insert(v);
        }
        else{
            adj[n - 1].erase(v);
        }
    };

    vector<tuple<int, int, int>> operations;

    for(int i = 1; i < n - 1; ++i){
        for(int v: adj[i]){
            operations.push_back({v, i, n - 1});
            flip(v);
            flip(i);
        }
    }

    if(!adj[n - 1].empty()){
        int cur = *adj[n - 1].begin();
        for(int i = 0; i < n - 1; ++i){
            if(adj[n - 1].find(i) == adj[n - 1].end()){
                operations.push_back({cur, i, n - 1});
                cur = i;
            }
        }
    }

    cout << operations.size() << '\n';
    for(auto [a, b, c]: operations){
        ++a, ++b, ++c;
        cout << a << ' ' << b << ' ' << c << '\n';
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
 
