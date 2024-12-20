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
 
const int INF = 1e9 + 7;
 
void solve() {
    int n;
    cin >> n;

    vector<ll> c(n);
    for(ll i = 0; i < n; ++i){
        cin >> c[i];
    }

    vector<vector<ll>> pos(n);
    for(ll i = 0; i < n; ++i){
        pos[i] = vector<ll>(c[i]);
        for(ll j = 0; j < c[i]; ++j){
            cin >> pos[i][j];
        }
    }

    auto collisions = [&](ll i, ll j){
        // number of collisions in i and j
        ll res = 0;
        for(ll k = 0; k < min(c[i], c[j]); ++k){
            res += (pos[i][k] == pos[j][k]);
        }
        return res;
    };

    // 0 -> left
    // 1 -> right
    vector<vector<vector<ll>>> dp(n, vector<vector<ll>>(2, vector<ll>(2, INF)));
    ll left = 0, right = 1;
    dp[1][right][right] = 0;
    dp[1][right][left] = collisions(0, 1);

    for(ll i = 2; i < n; ++i){
        dp[i][left][right] = min(dp[i - 1][left][left], dp[i - 1][right][left]);
        dp[i][right][right] = min(dp[i - 1][left][right], dp[i - 1][right][right]);

        dp[i][left][left] = min(
            dp[i - 1][left][left],
            dp[i - 1][right][left] + collisions(i - 2, i)
        );

        dp[i][right][left] = min(
            dp[i - 1][left][right] + collisions(i - 1, i),
            dp[i - 1][right][right] + collisions(i - 2, i) + collisions(i - 1, i)
        );
    }


    cout << min(dp[n - 1][left][left], dp[n - 1][right][left]) << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    solve();
    
    return 0;
}
 
