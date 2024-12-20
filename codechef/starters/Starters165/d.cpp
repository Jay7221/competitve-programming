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
 
 
ll solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

    ll tot = accumulate(a.begin(), a.end(), 0ll);
    if(tot < 0){
        tot = -tot;
        for(int i = 0; i < n; ++i){
            a[i] = -a[i];
        }
    }

    if(tot == 0){
        if(*max_element(a.begin(), a.end()) == 0){
            return 0;
        }
        return -1;
    }

    ll res = 0;
    auto add = [&](int ind, ll val){
        res += abs(val);
        a[ind] += val;
        tot += val;
    };

    for(int i = 0; i < n; ++i){
        if(a[i] < 0){
            if(tot < i + 1){
                add(0, i + 1 - tot);
            }

            add(i, -a[i]);
        }
    }

    for(int i = n - 1; i >= 0; --i){
        if(a[i] > 0){
            if(tot < i + 1){
                add(0, i + 1 - tot);
            }

            add(i, -min(a[i], tot - i));
            add(0, a[i]);
            add(i, -a[i]);
        }
    }

    return res;
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
 
