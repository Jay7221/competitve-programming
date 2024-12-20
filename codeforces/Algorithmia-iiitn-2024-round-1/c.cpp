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
 
bool isPrime(ll n){
    if(n < 2){
        return false;
    }
    for(ll p = 2; p * p <= n; ++p){
        if(n % p == 0){
            return false;
        }
    }
    return true;
}
const int N = 1000000;
vector<int> gurdy(N);
void pre(){
    gurdy[0] = 1;
    for(int i = 1; i < N; ++i){
        vector<int> arr;
        arr.push_back(gurdy[i - 1]);
        vector<int> divs;
        int maxDiv = i;
        while(!(maxDiv & 1)){
            maxDiv >>= 1;
        }
        for(int d = 1; d * d <= maxDiv; d += 2){
            if(i % d == 0){
                if(d > 1){
                    arr.push_back(gurdy[i / d]);
                    divs.push_back(d);
                }
                if(d * d != maxDiv){
                    int d2 = maxDiv / d;
                    arr.push_back(gurdy[i / d2]);
                    divs.push_back(d2);
                }
            }
        }
        sort(arr.begin(), arr.end());
        for(int elem: arr){
            if(gurdy[i] == elem){
                ++gurdy[i];
            }
        }
    }
}

bool wins(ll n){
    if(n == 1){
        return false;
    }
    if(n == 2){
        return true;
    }
    if(n & 1){
        return true;
    }
    if(n % 4 != 0){
        if(isPrime(n / 2)){
            return false;
        }
    }
    if((n & (n - 1)) == 0){
        return false;
    }
    return true;
}
 
bool solve() {
    int len;
    cin >> len;
    string s;
    cin >> s;

    reverse(s.begin(), s.end());

    ll n = 0;
    for(char ch: s){
        n <<= 1;
        n += ch - '0';
    }

    return wins(n);
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; ++t){
        if(solve()){
            cout << "BOB\n";
        }
        else{
            cout << "ALICE\n";
        }
    }
    
    return 0;
}
 
