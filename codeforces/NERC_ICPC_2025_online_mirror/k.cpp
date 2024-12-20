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

ll getMinCostFrom(int x, int y, ll start, int n, int a, int b){
    ll nx = n - x + 1;
    ll ny = n - y + 1;
    vector<vector<ll>> dp(nx, vector<ll>(ny, INF));
    dp[0][0] = start;
    for(int i = 0; i < nx; ++i){
        for(int j = 0; j < ny; ++j){
            if(i > 0){
                dp[i][j] = min(dp[i][j], gcd(i + x, a) + gcd(j + y, b) + dp[i - 1][j]);
            }
            if(j > 0){
                dp[i][j] = min(dp[i][j], gcd(i + x, a) + gcd(j + y, b) + dp[i][j - 1]);
            }
        }
    }
    return dp[nx - 1][ny - 1];
}
 
void solve() {
    int n, a, b;
    cin >> n >> a >> b;
 
    int li = 1, lj = 1;
    for(int i = 1; i <= n; ++i){
        if(gcd(a, i) == 1){
            li = i;
        }
    }
    for(int j = 1; j <= n; ++j){
        if(gcd(b, j) == 1){
            lj = j;
        }
    }
 
    ll res = 0;
    for(int i = 1; i <= li; ++i){
        res += gcd(a, i) + 1;
    }
    for(int j = 2; j <= lj; ++j){
        res += 1 + gcd(b, j);
    }


    cout << getMinCostFrom(li, lj, res, n, a, b) << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    solve();
    
    return 0;
}
 
