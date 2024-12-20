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
 
vector<int> divisor(int n){
    vector<int> res;
    for(int d = 1; d * d <= n; ++d){
        if(n % d){
            continue;
        }
        res.push_back(d);
        if(d * d != n){
            res.push_back(n / d);
        }
    }
    return res;
}
 
void solve() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<int> a(n), b(m);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    for(int j = 0; j < m; ++j){
        cin >> b[j];
    }

    ll sa = accumulate(a.begin(), a.end(), 0ll);
    ll sb = accumulate(b.begin(), b.end(), 0ll);

    map<ll, bool> ina, inb;
    for(ll elem: a){
        ina[sa - elem] = true;
    }
    for(ll elem: b){
        inb[sb - elem] = true;
    }

    while(q--){
        ll x;
        cin >> x;
        bool neg = (x < 0);
        x = abs(x);
        bool possible = false;

        for(int d: divisor(x)){
            int d2 = x / d;
            if(neg){
                possible |= (ina[-d] && inb[d2]) || (ina[d] && inb[-d2]);
            }
            else{
                possible |= (ina[d] && inb[d2]) || (ina[-d] && inb[-d2]);
            }
        }
        if(possible){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    solve();
    
    return 0;
}
 
