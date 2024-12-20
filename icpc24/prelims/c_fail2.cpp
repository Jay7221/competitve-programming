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

const ll INF = 1e9 + 7;
 
void solve() {
    int n;
    cin >> n;
    vector<ll> a(n), x(n);
    for(int i = 0; i < n; ++i){
        cin >> x[i];
    }
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

    vector<pair<ll, ll>> v;
    for(int i = 0; i < n; ++i){
        v.push_back({x[i], a[i]});
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < n; ++i){
        tie(x[i], a[i]) = v[i];
    }

    auto cost = [&](int i, int j){
        return min(a[i], a[j]) * abs(x[i] - x[j]);
    };

    ll res = 0;
    int minInd = 0;
    for(int i = 0; i < n; ++i){
        if(a[i] < a[minInd]){
            minInd = i;
        }
    }

    vector<int> st;
    st.push_back(minInd);
    for(int i = minInd + 1; i < n; ++i){
        while(st.size() > 1){
            int sz = st.size();
            if(cost(st[sz - 2], i) > cost(st[sz - 1], i)){
                break;
            }
            st.pop_back();
        }
        res += cost(st.back(), i);
        st.push_back(i);
    }

    st.clear();
    st.push_back(minInd);
    for(int i = minInd - 1; i >= 0; --i){
        while(st.size() > 1){
            int sz = st.size();
            if(cost(st[sz - 2], i) > cost(st[sz - 1], i)){
                break;
            }
            st.pop_back();
        }
        res += cost(st.back(), i);
        st.push_back(i);
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
 
