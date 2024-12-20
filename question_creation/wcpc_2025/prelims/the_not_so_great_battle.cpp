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
 
char solve() {
    int n, k;
    char ch;
    cin >> n >> k >> ch;
    vector<int> queen(k);
    for(int i = 0; i < k; ++i){
        cin >> queen[i];
    }
    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

    char other_ch = 'V';

    if(ch == 'V'){
        other_ch = 'K';
    }

    int tot_xor = 0;
    for(int elem: a){
        tot_xor ^= elem;
    }

    if(tot_xor == 0){
        return other_ch;
    }

    if((tot_xor & (tot_xor - 1)) == 0){
        return ch;
    }

    for(int qk: queen){
        for(int elem: a){
            if((elem >= qk) && (elem ^ (elem - qk) ^ tot_xor == 0)){
                cerr << elem << ' ' << qk << '\n';
                return ch;
            }
        }
    }
    return other_ch;
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; ++t){
        cout << solve() << '\n';
    }
    
    return 0;
}
 
