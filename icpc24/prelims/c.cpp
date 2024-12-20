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

const ll INF = 1e9 + 7;
 
class DSU{
    public:
        vector<int> par;
        vector<int> rank;
        int n;
        DSU(){
            n = 0;
        }
        DSU(int n){
            this -> n = n;
            par = vector<int>(n);
            for(int i = 0; i < n; ++i){
                par[i] = i;
            }
            rank = vector<int>(n, 1);
        }
        int get_par(int u){
            if(par[u] == u){
                return u;
            }
            return par[u] = get_par(par[u]);
        }
        int get(int u){
            return get_par(u);
        }
        void merge(int u, int v){
            u = get_par(u);
            v = get_par(v);
            if(u == v){
                return;
            }
            if(rank[u] < rank[v]){
                swap(u, v);
            }
            par[v] = u;
            rank[u] += rank[v];
            --n;
        }
        int size(){
            return n;
        }
};

ll solve(ll n, vector<ll> x, vector<ll> a) {
    vector<pair<ll, ll>> v;
    for(ll i = 0; i < n; ++i){
        v.push_back({x[i], a[i]});
    }
    sort(v.begin(), v.end());
    for(ll i = 0; i < n; ++i){
        tie(x[i], a[i]) = v[i];
    }

    auto cost = [&](ll i, ll j){
        return min(a[i], a[j]) * abs(x[i] - x[j]);
    };

    auto check = [&](int i){
        return (i >= 0) && (i < n);
    };

    ll res = 0;
    priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll>>, greater<tuple<ll, ll, ll>>> pq;
    for(ll i = 1; i < n; ++i){
        pq.push({cost(i - 1, i), i - 1, i});
    }

    vector<int> path;
    for(int i = 0; i < n; ++i){
        while(path.size() > 1){
            int sz = path.size();
            if(cost(path[sz - 2], i) <= cost(path[sz - 1], i)){
                path.pop_back();
            }
            else{
                break;
            }
        }
        if(!path.empty()){
            int j = path.back();
            pq.push({cost(i, j), i, j});
        }
        path.push_back(i);
    }
    path.clear();
    for(int i = n - 1; i >= 0; --i){
        while(path.size() > 1){
            int sz = path.size();
            if(cost(path[sz - 2], i) <= cost(path[sz - 1], i)){
                path.pop_back();
            }
            else{
                break;
            }
        }
        if(!path.empty()){
            int j = path.back();
            pq.push({cost(i, j), i, j});
        }
        path.push_back(i);
    }


    DSU dsu(n);
    while(!pq.empty()){
        ll c, i, j;
        tie(c, i, j) = pq.top();
        pq.pop();

        if(dsu.get(i) == dsu.get(j)){
            continue;
        }
        res += c;
        dsu.merge(i, j);

        if(check(i - 1) && (dsu.get(i - 1) != dsu.get(j))){
            pq.push({cost(i - 1, j), i - 1, j});
        }
        if(check(j + 1) && (dsu.get(i) != dsu.get(j + 1))){
            pq.push({cost(i, j + 1), i, j + 1});
        }
    }
    return res;
}

ll solve_brute(ll n, vector<ll> x, vector<ll> a){
    auto cost = [&](int i, int j){
        return min(a[i], a[j]) * abs(x[i] - x[j]);
    };
    vector<tuple<ll, int, int>> v;
    for(int i = 0; i < n; ++i){
        for(int j = i + 1; j < n; ++j){
            v.push_back({cost(i, j), i, j});
        }
    }
    DSU dsu(n);
    sort(v.begin(), v.end());
    ll res = 0;

    for(auto [c, i, j]: v){
        if(dsu.get(i) != dsu.get(j)){
            dsu.merge(i, j);
            res += c;
        }
    }

    return res;
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; ++t){
        ll n;
        cin >> n;
        vector<ll> a(n), x(n);
        for(int i = 0; i < n; ++i){
            cin >> x[i];
        }
        for(int i = 0; i < n; ++i){
            cin >> a[i];
        }
        cout << solve(n, x, a) << '\n';
        cerr << solve_brute(n, x, a) << '\n';
    }
    
    return 0;
}
 
