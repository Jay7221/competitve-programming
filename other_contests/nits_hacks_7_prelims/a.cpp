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
 
 
ll solve() {
    ll n, m, r1, r2;
    cin >> n >> m >> r1 >> r2;
    if(n < m){
        swap(n, m);
    }
    if(r1 > r2){
        swap(r1, r2);
    }

    ll dist = 2 + r1 + r2;
    ll x1 = r1 + 1, y1 = r1 + 1;
    ll y2 = max(r2 + 1, x1 + y1 + dist - (n - r2));
    ll x2 = max(r2 + 1, x1 + y1 + dist - y2);

    /*
    cerr << dist << '\n';
    cerr << x1 << ' ' << y1 << '\n';
    cerr << x2 << ' ' << y2 << '\n';
    cerr << "---------\n";
    */

    if((x2 + r2 > n) || (y2 + r2 > m)){
        return -1;
    }
    return (x1 + y1) + (x2 + y2);
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; ++t){
        cout << solve() << '\n';
    }
    
    return 0;
}
 
