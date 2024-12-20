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
    vector<pair<int, int>> operations;
    int cnt0 = count(a.begin(), a.end(), 0);
    int cnt1 = count(a.begin(), a.end(), 1);
    int cnt2 = count(a.begin(), a.end(), 2);

    for(int i = 0, j = cnt0; i < cnt0; ++i){
        if(a[i] == 1){
            while(a[j] != 0){
                ++j;
            }
            operations.push_back({i, j});
            swap(a[i], a[j]);
        }
    }

    int ind1 = n - 1;
    while(a[ind1] != 1){
        --ind1;
    }

    for(int i = 0, j = n - 1; i < cnt0; ++i){
        if(a[i] == 2){
            while(a[j] != 0){
                --j;
            }
            operations.push_back({i, ind1});
            operations.push_back({i, j});
            swap(a[i], a[ind1]);
            swap(a[i], a[j]);
            ind1 = j;
        }
    }
    for(int i = 0, j = cnt0 + cnt1; i < cnt0 + cnt1; ++i){
        if(a[i] == 2){
            while(a[j] != 1){
                ++j;
            }
            operations.push_back({i, j});
            swap(a[i], a[j]);
        }
    }

    cout << operations.size() << '\n';
    for(auto [i, j]: operations){
        cout << (i + 1) << ' ' << (j + 1) << '\n';
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
 
