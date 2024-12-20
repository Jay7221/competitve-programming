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
 
ll log_upper(ll n){
    ll res = 0;
    while(n > 1){
        n = (n + 1) / 2;
        ++res;
    }
    return res;
}

const int LOGMAX = 40;
 
void solve() {
    ll n, k;
    cin >> n >> k;
    if(log_upper(k) > n - 1){
        cout << -1 << '\n';
        return;
    }

    --k;
    vector<ll> p(n);
    ll l = 0, r = n - 1;
    for(ll i = 1; i < n; ++i){
        ll bit = n - 1 - i;
        if((bit < LOGMAX) && (1 & (k >> bit))){
            p[r] = i;
            --r;
        }
        else{
            p[l] = i;
            ++l;
        }
    }
    p[l] = n;

    for(ll elem: p){
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
//        cout << "# Case " << i << " : ";
        solve();
    }
    
    return 0;
}
 
