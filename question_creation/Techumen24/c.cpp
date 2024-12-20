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
 
 
int solve() {
    int n;
    cin >> n;
    vector<int> arr(n);

    map<int, int> freq;
    for(int i = 0; i < n; ++i){
        cin >> arr[i];
        ++freq[arr[i]];
    }

    int duplicates = 0;
    for(auto [u, f]: freq){
        duplicates += (f > 1);
    }

    if(duplicates == 0){
        return 0;
    }

    int res = n;
    for(int l = 0, r = 0; r < n; ++r){
        --freq[arr[r]];
        if(freq[arr[r]] == 1){
            --duplicates;
        }
        while(freq[arr[l]] == 0){
            ++freq[arr[l]];
            ++l;
        }
        if(duplicates == 0){
            res = min(res, r - l + 1);
        }
    }
    return res;
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    cout << solve() << '\n';
    
    return 0;
}
 
