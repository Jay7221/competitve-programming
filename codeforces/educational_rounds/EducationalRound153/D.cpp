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
 
 
const int N = 101;
void solve() {
    string s;
    cin >> s;
    int n = s.size();
    int m = (n + 1) * (n + 1);
    vector<vector<int>> dp(n + 1, vector<int>(m));
    vector<vector<int>> prev(n + 1, vector<int>(m));
    for(int i = 0; i < n; ++i){

        for(int j = 0; j <= i + 1; ++j){
            for(int cnt = 0; cnt <= j * (i + 1 - j); ++cnt){
                dp[j][cnt] = n;
            }
        }

        for(int j = 0; j <= i; ++j){
            for(int cnt = 0; cnt <= j * (i - j); ++cnt){
                dp[j + 1][cnt] = min(dp[j + 1][cnt], prev[j][cnt] + (s[i] != '0'));
                dp[j][cnt + j] = min(dp[j][cnt + j], prev[j][cnt] + (s[i] != '1'));
            }
        }

        swap(dp, prev);
    }
    dp = prev;
    int cnt0 = count(s.begin(), s.end(), '0');
    int need = (cnt0 * (n - cnt0)) / 2;
    int ans = dp[cnt0][need] / 2;
    cout << ans << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    solve();
    
    return 0;
}
 

