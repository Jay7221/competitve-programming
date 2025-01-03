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
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

    vector<bool> vis(n + 1);

    int res = 0;
    for(int l = 0, i = 0; i + 1 < n; i += 2){
        if(a[i] != a[i + 1]){
            while(l < i + 2){
                vis[a[l]] = false;
                l += 2;
            }
        }
        else{
            while(vis[a[i]]){
                vis[a[l]] = false;
                l += 2;
            }
            res = max(res, i - l + 2);
            vis[a[i]] = true;
        }
    }
    vis.assign(n + 1, false);
    for(int l = 1, i = 1; i + 1 < n; i += 2){
        if(a[i] != a[i + 1]){
            while(l < i + 2){
                vis[a[l]] = false;
                l += 2;
            }
        }
        else{
            while(vis[a[i]]){
                vis[a[l]] = false;
                l += 2;
            }
            res = max(res, i - l + 2);
            vis[a[i]] = true;
        }
    }

    cout << res;
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    int tc = 1;
    for(int t = 1; t <= tc; ++t){
        solve();
    }
    
    return 0;
}
 
