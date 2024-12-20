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

ll sqrt(ll n){
    ll res = 1;
    while(res * res < n){
        ++res;
    }
    return res;
}
 
void solve() {
    ll x, y, z, k;
    cin >> x >> y >> z >> k;

    auto damage = [&](ll a, ll b){
        ll c = min(a / k, b);
        return (k * c * (c + 1)) / 2 + a * (b - c);
    };

    auto cost = [&](ll a, ll b){
        return a * x + b * y;
    };

    ll res = cost(1, z);

    ll max_min = sqrt(2 * z) + 1;

    for(ll a = 1; a <= max_min; ++a){
        ll l = 1, r = z;
        while(l < r){
            ll m = (l + r) / 2;
            if(damage(a, m) >= z){
                r = m;
            }
            else{
                l = m + 1;
            }
        }
        assert(damage(a, l) >= z);
        res = min(res, cost(a, l));
    }

    for(ll b = 1; b <= max_min; ++b){
        ll l = 1, r = z;
        if(damage(r, b) < z){
            continue;
        }
        while(l < r){
            ll m = (l + r) / 2;
            if(damage(m, b) >= z){
                r = m;
            }
            else{
                l = m + 1;
            }
        }
        res = min(res, cost(l, b));
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
 
