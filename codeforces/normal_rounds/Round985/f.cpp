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
 
bool isPal(string s){
    int l = 0;
    int r = s.size() - 1;
    while(l < r){
        if(s[l] != s[r]){
            return false;
        }
        ++l;
        --r;
    }
    return true;
}
 
bool solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    if(count(s.begin(), s.end(), s[0]) == n){
        return true;
    }

    string ns;

    int i = 1;
    while(s[i] == s[i - 1]){
        ++i;
    }

    int cnt = 0;
    while(cnt < n){
        int cur = 0;
        char ch = s[i];
        while(s[i] == ch){
            i = (i + 1) % n;
            ++cur;
            ++cnt;
        }
        if(cur & 1){
            ns.push_back(ch);
        }
    }



    cerr << s << " : " << ns << '\n';

    return isPal(ns);
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; ++t){
        if(solve()){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
    
    return 0;
}
 
