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
    ll n;
    cin >> n;

    vector<ll> a(n + 1);
    for(ll i = 1; i <= n; ++i){
        cin >> a[i];
    }

    vector<ll> pre = a;
    for(ll i = 1; i <= n; ++i){
        pre[i] += pre[i - 1];
    }

    auto s = [&](ll l, ll r){
        return (pre[r] - pre[l - 1]);
    };

    vector<ll> prefs1(n + 1);   // prefs1[i] -> pref of s(1, i)
    for(ll i = 1; i <= n; ++i){
        prefs1[i] = prefs1[i - 1] + s(1, i);
    }

    function<ll(ll, ll)> prefs = [&](ll i, ll k){
        return prefs1[k] - prefs1[i - 1] - (k - i + 1) * s(1, i - 1);
    };

    vector<ll> prefacc(n + 1);
    for(ll i = 1; i <= n; ++i){
        prefacc[i] = prefacc[i - 1] + prefs(i, n);
    }


    vector<ll> num_elements(n + 1);
    for(ll i = 1; i <= n; ++i){
        num_elements[i] = num_elements[i - 1] + (n - i + 1);
    }

    auto prefsum = [&](ll x){
        ll i = lower_bound(num_elements.begin(), num_elements.end(), x) - num_elements.begin();
        ll j = x - num_elements[i - 1] + i - 1;
        ll res = prefacc[i - 1] + prefs(i, j);
        return res;
    };

    ll q;
    cin >> q;
    while(q--){
        ll l, r;
        cin >> l >> r;
        ll res = prefsum(r);
        if(l > 1){
            res -= prefsum(l - 1);
        }
        cout << res << '\n';
    }
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    solve();
    
    return 0;
}
 
