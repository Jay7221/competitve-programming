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

    vector<int> a(n), b(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    for(int i = 0; i < n; ++i){
        cin >> b[i];
    }

    int LOGMAX = 30;
    vector<int> mx(LOGMAX, -1), mx2(LOGMAX, -1);

    mx[0] = max(a[0], b[0]);
    mx2[0] = max(a[1], b[1]);
    if(mx2[0] > mx[0]){
        swap(mx[0], mx2[0]);
    }

    for(int i = 2; i < n; ++i){
        for(int j = LOGMAX - 2; j >= 0; --j){
            if(mx[j] == -1){
                continue;
            }
            if(mx[j] + mx2[j] < max(a[i], b[i])){
                mx[j + 1] = mx[j];
                mx2[j + 1] = mx2[j];
                mx2[j + 1] = max(mx2[j + 1], max(a[i], b[i]));
                if(mx[j + 1] < mx2[j + 1]){
                    swap(mx[j + 1], mx2[j + 1]);
                }
            }
            if(mx[j] + mx2[j] < min(a[i], b[i])){
                mx[j] = mx2[j] = -1;
            }
        }
    }

    int res = 0;
    for(int j = LOGMAX - 1; j >= 0; --j){
        if(mx[j] != -1){
            res = n - 2 - j;
        }
    }
    cout << res << '\n';
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
 
