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
    cout << fixed;
    cout << setprecision(10);

    int n;
    cin >> n;
    string s;
    cin >> s;

    int m = count(s.begin(), s.end(), '?');

    vector<vector<double>> dp(m + 1, vector<double>(m + 1));

    dp[0][0] = 5;

    for(int i = 1; i <= m; ++i){
        dp[i][0] = .5 * dp[i - 1][0];
        for(int j = 1; j <= m; ++j){
            dp[i][j] = dp[i - 1][j] * .5 + dp[i - 1][j - 1] * .5;
        }
    }

    int cur = 1;
    for(int i = 0; i < n; ++i){
        double digit;
        if(s[i] == '?'){
            digit = 2;
            for(int j = cur; j <= m; ++j){
                digit += dp[m][j];
            }
            ++cur;
        }
        else{
            digit = (s[i] - '0');
        }
        cout << digit << ' ';
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
 
