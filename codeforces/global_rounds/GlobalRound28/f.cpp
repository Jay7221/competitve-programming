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

    vector<ll> a(n), b(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    for(int i = 0; i < n; ++i){
        cin >> b[i];
    }

    ll mx = 1;
    ll num_ops = 0;
    vector<ll> operations;

    auto apply = [&](ll a, ll b){
        return (a + b - 1) / b;
    };

    auto next_state = [&](int ind, ll mx, vector<ll> ops, ll ind_arr, int num_ops){
        for(int i = 0; i < ind; ++i){
            mx = apply(mx, ops[i]);
        }
        mx = max(mx, a[ind_arr]);
        ll n_mx = mx;

        vector<ll> new_ops;
        for(int i = ind; i < (int)ops.size(); ++i){
            ops[i] = min(ops[i], b[ind_arr]);
            new_ops.push_back(ops[i]);
            mx = apply(mx, ops[i]);
        }

        while(mx > 1){
            ++num_ops;
            mx = apply(mx, b[ind_arr]);
            new_ops.push_back(b[ind_arr]);
        }

        return (tuple<ll, vector<ll>, int>){n_mx, new_ops, num_ops};
    };

    for(int i = 0; i < n; ++i){
        auto [new_mx, new_ops, new_num_ops] = next_state(operations.size(), mx, operations, i, num_ops);
        for(int j = 0; j < (int)operations.size(); ++j){
            auto [n_mx, n_ops, n_num_ops] = next_state(j, mx, operations, i, num_ops);
            if(new_num_ops >= n_num_ops){
                new_num_ops = n_num_ops;
                new_ops = n_ops;
                new_mx = n_mx;
            }
        }

        mx = new_mx;
        operations = new_ops;
        num_ops = new_num_ops;
        cerr << mx << ' ' << operations << ' ' << num_ops << '\n';
    }

    cout << num_ops << '\n';
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
 
