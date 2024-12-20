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
    string s;
    cin >> s;
    int n = s.size();
    
    int l1, r1, l2, r2;
    l1 = 0;
    r1 = n - 1;
    l2 = 0;
    r2 = 0;

    vector<int> cand;
    for(int i = 0; i < n; ++i){
        cand.push_back(i);
    }

    auto is_greater = [&](int a, int b, int l, int r){
        int len1 = b - a + 1;
        int len2 = r - l + 1;
        if(len1 < len2){
            return false;
        }
        if(len1 > len2){
            return true;
        }
        int len = len1;
        for(int i = 0; i < len; ++i){
            int i1=  a + i;
            int i2 = l + i;
            int ind = n - len + i;
            if((s[i1] != s[ind]) && (s[i2] == s[ind])){
                return true;
            }
            if((s[i1] == s[ind]) && (s[i2] != s[ind])){
                return false;
            }
        }
        return true;
    };

    for(int i = 0; i < n; ++i){
        int l = i, r = i;
        for(int j = i; j >= 0; --j){
            if(s[j] != s[n - 1 - (i - j)]){
                l = j;
            }
        }
        if(is_greater(l, r, l2, r2)){
            l2 = l;
            r2 = r;
        }
    }

    ++l1, ++r1;
    ++l2, ++r2;

    cout << l1 << ' ' << r1 << ' ' << l2 << ' ' << r2 << '\n';

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
 
