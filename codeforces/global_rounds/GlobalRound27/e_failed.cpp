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
 
void solve() {
    ll x, y, z, k;
    cin >> x >> y >> z >> k;

    auto cost = [&](ll d){
        if(d <= 0){
            return INF;
        }

        ll p2 = d / (k + 1);
        ll res = x * d + y * p2;

        ll rem_z = z - k * ((p2 * (p2 + 1)) / 2);

        if(rem_z > 0){
            res += y * ((rem_z + d - 1) / d);
        }

        return res;
    };

    auto is_decreasing = [&](ll x){
        if((cost(x - 1) < cost(x)) || (cost(x) < cost(x + 1))){
            return false;
        }
        return ((cost(x - 1) > cost(x)) || (cost(x) > cost(x + 1)));
    };

    auto is_increasing = [&](ll x){
        if((cost(x - 1) > cost(x)) || (cost(x) > cost(x + 1))){
            return false;
        }
        return ((cost(x - 1) < cost(x)) || (cost(x) < cost(x + 1)));
    };

    for(int i = 1; i <= y; ++i){
        cerr << i << " : " << cost(i) << '\n';
    }
    cerr << '\n';

    ll res = cost(1);
    ll l = 1, r = z;
    while(l < r){
        ll m = (l + r) / 2;
        res = min(res, cost(m));
        if(is_decreasing(m)){
            l = m + 1;
        }
        else if(is_increasing(m)){
            r = m - 1;
        }
        else{
            cerr << m << " : " << cost(m) << '\n';
            cerr << cost(m - 1) << ' ' << cost(m) << ' ' << cost(m + 1) << '\n';
            break;
        }
    }
    res = min(res, cost(l));


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
 
