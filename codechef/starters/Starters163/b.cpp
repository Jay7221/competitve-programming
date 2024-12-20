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
const int ALPHABET = 26;
 
void solve() {
    int n;
    cin >> n;
    string s, p;
    cin >> s >> p;

    vector<int> mp(ALPHABET);
    for(int i = 0; i < ALPHABET; ++i){
        mp[p[i] - 'a'] = p[ALPHABET - i - 1] - 'a';
    }

    vector<int> dp(ALPHABET);
    // dp[k] = minimum number of operations to ensure that array upto current index is non-decreasing and every character <= i
    for(int i = 0; i < n; ++i){
        int ch = s[i] - 'a';
        int ch2 = mp[ch];
        int val = dp[ch];
        int val2 = dp[ch2] + 1;
        for(int j = 0; j < ALPHABET; ++j){
            dp[j] = INF;
            if(j >= ch){
                dp[j] = min(dp[j], val);
            }
            if(j >= ch2){
                dp[j] = min(dp[j], val2);
            }
            if(j > 0){
                dp[j] = min(dp[j], dp[j - 1]);
            }
        }
    }

    int res = *min_element(dp.begin(), dp.end());
    if(res == INF){
        cout << -1 << '\n';
    }
    else{
        cout << res << '\n';
    }
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
 
