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
 
ll power(int n, int k){
    ll res = 1;
    for(int i = 0; i < k; ++i){
        res *= n;
    }
    return res;
}
 
void solve() {
    string s;
    cin >> s;
    int n = s.size();
    ll res = (power(5, n + 1) - 5) / 4;
    for(int i = 0; i < n; ++i){
        int rem = n - 1 - i;
        int d = (s[i] - '0');
        int remD = 0;
        if((i + 1) & 1){    // odd indexed
            for(int nd = d + 1; nd < 10; ++nd){
                if(nd & 1){
                    ++remD;
                }
            }
        }
        else{               // even indexed
            for(int nd = d + 1; nd < 10; ++nd){
                if(!(nd & 1)){
                    ++remD;
                }
            }
        }
        res -= remD * power(5, rem);
        if((d & 1) != ((i + 1) & 1)){
            break;
        }
    }
    cout << res << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    solve();
    
    return 0;
}
 
