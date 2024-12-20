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
 
class DSU{
    ll n;
    vector<ll> par; // compid[u] = id of the component u belongs to
    vector<ll> dist;   // dist[u] = distance of u from the component leader of compid[u]
    vector<vector<ll>> comp;   // comp[u] = set of all elements in component whose leader is u
public:
    DSU(ll n){
        this -> n = n;

        par = vector<ll>(n);
        dist = vector<ll>(n);
        comp = vector<vector<ll>>(n);

        for(ll i = 0; i < n; ++i){
            par[i] = i;
            dist[i] = 0;
            comp[i].push_back(i);
        }
    }

    void add(ll u, ll v, ll w){
        if(par[u] == par[v]){
            return;
        }

        w += dist[u] - dist[v];
        u = par[u], v = par[v];

        if(comp[u].size() < comp[v].size()){
            swap(u, v);
            w = -w;
        }

        for(ll i: comp[v]){
            dist[i] += w;
            par[i] = u;
            comp[u].push_back(i);
        }

    }

    ll get(ll u, ll v){
        if(par[u] != par[v]){
            return -1;
        }
        return (dist[v] - dist[u]);
    }


};
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    ll n, q;
    cin >> n >> q;
    DSU dsu(2 * n + 7);

    for(ll i = 0; i < q; ++i){
        ll type;
        cin >> type;
        if(type == 1){
            ll u, v, w;
            cin >> u >> v >> w;
            dsu.add(n - u, n + v, w);
            dsu.add(n - v, n + u, w);
        }
        else{
            ll u, v;
            cin >> u >> v;

            cout << max(dsu.get(n - u, n + v), dsu.get(n - v, n + u)) << '\n';
        }
    }

    
    return 0;
}
 
