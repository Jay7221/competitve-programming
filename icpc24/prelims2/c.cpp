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
 
const int MAX = 2e6 + 1;
vector<int> primes;
vector<bool> isPrime(MAX, true);

void pre(){
    for(int p = 2; p < MAX; ++p){
        if(isPrime[p]){
            primes.push_back(p);
            for(int j = 2; j * p < MAX; ++j){
                isPrime[j * p] = false;
            }
        }
    }
}
 
void solve() {
    ll n, k;
    cin >> n >> k;
    if(((n * (n - 1)) / 2) < k){
        cout << -1 << '\n';
        return;
    }
    vector<int> a(n, 2);

    for(int i = n - 1; i > 0; --i){
        a[i] = primes[n - i];
        if(k <= i){
            for(int j = k; j < i; ++j){
                a[j] *= a[i];
            }
            break;
        }
        else{
            k -= i;
        }
    }

    for(int elem: a){
        cout << elem << ' ';
    }
    cout << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    pre();
 
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; ++t){
//        cout << "# Case " << i << " : ";
        solve();
    }
    
    return 0;
}
 
