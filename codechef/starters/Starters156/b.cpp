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

bool check(ll cost, vector<ll> &a, ll x){
    ll cur = a[0] + cost;
    for(int i = 1; i < (int)a.size(); ++i){
        cur = min(cur + x, a[i] + cost);
        if(cur < (a[i] - cost)){
            return false;
        }
    }
    return true;
}
 
void solve() {
    int n;
    ll x;
    cin >> n >> x;
    vector<ll> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

    ll l = 0, r = INF;

    while(l < r){
        ll mid = (l + r) / 2;
        if(check(mid, a, x)){
            r = mid;
        }
        else{
            l = mid + 1;
        }
    }

    ll res = l;

    vector<ll> b = a;

    b[0] += res;
    for(int i = 1; i < n; ++i){
        b[i] = min(b[i - 1] + x, a[i] + res);
    }

    cout << res << '\n';
    for(ll elem: b){
        cout << elem << ' ';
    }
    cout << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; ++t){
        solve();
    }
    
    return 0;
}
 
