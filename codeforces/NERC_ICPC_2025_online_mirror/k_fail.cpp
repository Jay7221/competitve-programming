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

    auto get = [&](int i, int j){
        return n * 1ll * i + j;
    };

    unordered_map<ll, ll> dp;

    for(int i = li; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            dp[get(i, j)] = INF;
        }
    }
    for(int i = 1; i <= n; ++i){
        for(int j = lj; j <= n; ++j){
            dp[get(i, j)] = INF;
        }
    }


    dp[get(1, lj)] = 0;
    for(int j = 1; j <= lj; ++j){
        dp[get(1, lj)] += 1 + gcd(j, b);
    }

    dp[get(li, 1)] = 0;
    for(int i = 1; i <= li; ++i){
        dp[get(li, 1)] += gcd(i, a) + 1;
    }

    for(int i = 1, j = lj + 1; j <= n; ++j){
        dp[get(i, j)] = min(dp[get(i, j)], gcd(i, a) + gcd(j, b) + dp[get(i, j - 1)]);

    }
    for(int i = li, j = 2; j <= n; ++j){
        dp[get(i, j)] = min(dp[get(i, j)], gcd(i, a) + gcd(j, b) + dp[get(i, j - 1)]);

    }


    for(int i = 2, j = lj; i <= n; ++i){
        dp[get(i, j)] = min(dp[get(i, j)], gcd(i, a) + gcd(j, b) + dp[get(i - 1, j)]);
    }
    for(int i = li + 1, j = 1; i <= n; ++i){
        dp[get(i, j)] = min(dp[get(i, j)], gcd(i, a) + gcd(j, b) + dp[get(i - 1, j)]);
    }

    for(int i = 2; i <= n; ++i){
        for(int j = lj + 1; j <= n; ++j){
            dp[get(i, j)] = gcd(i, a) + gcd(j, b) + min(dp[get(i - 1, j)], dp[get(i, j - 1)]);
        }
    }
    for(int i = li + 1; i <= n; ++i){
        for(int j = 2; j <= n; ++j){
            dp[get(i, j)] = gcd(i, a) + gcd(j, b) + min(dp[get(i - 1, j)], dp[get(i, j - 1)]);
        }
    }

    cout << dp[get(n, n)] << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    solve();
    
    return 0;
}
 
