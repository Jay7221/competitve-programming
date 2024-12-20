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

    vector<ll> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

    ll res = 0;
    for(int i = 0; i < n; ++i){
        ll mask = a[i];
        ll len = 1;

        res = max(res, len - __builtin_popcount(mask));

        vector<bool> vis(n);
        vis[i] = true;

        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;

        for(int j = 0; j < n; ++j){
            if(!vis[j]){
                pq.push(make_pair(__builtin_popcount(a[j] ^ (a[j] & mask)), j));
            }
        }

        while(!pq.empty()){
            int val, ind;
            tie(val, ind) = pq.top();
            pq.pop();

            if(vis[ind]){
                continue;
            }

            vis[ind] = true;
            mask |= a[ind];
            ++len;
            res = max(res, len - __builtin_popcount(mask));

            for(int j = 0; j < n; ++j){
                if(!vis[j]){
                    pq.push(make_pair(__builtin_popcount(a[j] ^ (a[j] & mask)), j));
                }
            }
        }
    }

    cout << res << '\n';
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
 
