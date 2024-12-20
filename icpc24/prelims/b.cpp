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
    int n, d, l;
    cin >> n >> d >> l;

    if(n == 2){
        if((l != 2) || (d != 1)){
            cout << -1 << '\n';
        }
        else{
            cout << 1 << ' ' << 2 << '\n';
        }
        return;
    }

    if(d > n - l + 1){
        cout << -1 << '\n';
        return;
    }

    if(d < 2){
        cout << -1 << '\n';
        return;
    }

    vector<int> lengths(l);
    lengths[0] = (d + 1) / 2;
    lengths[1] = d / 2;

    int rem = n - 1 - d;
    for(int i = 2; i < l; ++i){
        --rem;
        lengths[i] = 1;
    }

    if(rem < 0){
        cout << -1 << '\n';
        return;
    }
    for(int i = 2; i < l; ++i){
        int diff = min(rem, d / 2 - lengths[i]);
        lengths[i] += diff;
        rem -= diff;
    }

    if(rem > 0){
        cout << -1 << '\n';
        return;
    }

    vector<pair<int, int>> edges;
    int cur = 2;
    for(int i = 0; i < l; ++i){
        int prev = 1;
        for(int j = 0; j < lengths[i]; ++j){
            edges.push_back({prev, cur});
            prev = cur;
            ++cur;
        }
    }


    for(auto [u, v]: edges){
        cout << u << ' ' << v << '\n';
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
 
