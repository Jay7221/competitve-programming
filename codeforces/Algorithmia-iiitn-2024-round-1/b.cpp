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
 
 
string solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> freq(26);
    for(char ch: s){
        ++freq[ch - 'a'];
    }

    int noPairs = 0;
    for(int i = 0; i < 26; ++i){
        noPairs += freq[i] / 2;
    }


    for(int m = 2; m < n; ++m){
        if(n % m){
            continue;
        }

        if(noPairs < ((m / 2) * (n / m))){
            continue;
        }

        int cur = 0;

        for(int i = 0; i < n; i += m){
            int l = i, r = i + m - 1;

            while(l < r){
                while(freq[cur] < 2){
                    ++cur;
                }
                s[l] = s[r] = ('a' + cur);
                freq[cur] -= 2;
                ++l, --r;
            }
        }

        if(m & 1){
            cur = 0;
            for(int i = m / 2; i < n; i += m){
                while(freq[cur] < 1){
                    ++cur;
                }
                s[i] = cur + 'a';
            }
        }
        cout << m << '\n';
        return s;
    }
    return "-1";
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
 
