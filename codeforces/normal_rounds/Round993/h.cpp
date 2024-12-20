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
    int n, q;
    cin >> n >> q;
    vector<vector<ll>> mat(n + 2, vector<ll>(n + 2));

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            cin >> mat[i][j];
        }
    }

    vector<vector<ll>> suf = mat;
    for(int i = 1; i <= n; ++i){
        for(int j = n; j >= 1; --j){
            suf[i][j] += suf[i][j + 1];
        }
    }

    vector<vector<ll>> supsuf = suf;
    for(int i = 1; i <= n; ++i){
        for(int j = n; j >= 1; --j){
            supsuf[i][j] += supsuf[i][j + 1];
        }
    }

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            suf[i][j] += suf[i - 1][j];
            supsuf[i][j] += supsuf[i - 1][j];
        }
    }

    vector<vector<ll>> sufy = mat;
    for(int j = 1; j <= n; ++j){
        for(int i = n; i >= 1; --i){
            sufy[i][j] += sufy[i + 1][j];
        }
    }

    vector<vector<ll>> supsufy = sufy;
    for(int j = 1; j <= n; ++j){
        for(int i = n; i >= 1; --i){
            supsufy[i][j] += supsufy[i + 1][j];
        }
    }

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            sufy[i][j] += sufy[i][j - 1];
            supsufy[i][j] += supsufy[i][j - 1];
        }
    }

    while(q--){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        ll pre2 = (supsuf[x2][y1] - supsuf[x2][y2 + 1] - (y2 - y1 + 1) * suf[x2][y2 + 1]);
        ll pre1 = (supsuf[x1 - 1][y1] - supsuf[x1 - 1][y2 + 1] - (y2 - y1 + 1) * suf[x1 - 1][y2 + 1]);

        ll pre2y = (supsufy[x1 + 1][y2] - supsufy[x2 + 1][y2] - (x2 - x1) * sufy[x2 + 1][y2]);
        ll pre1y = (supsufy[x1 + 1][y1 - 1] - supsufy[x2 + 1][y1 - 1] - (x2 - x1) * sufy[x2 + 1][y1 - 1]);

        ll res = (pre2 - pre1) + (y2 - y1 + 1) * (pre2y - pre1y);
        cout << res << ' ';
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
 
