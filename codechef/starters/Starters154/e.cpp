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

  vector<int> a(n);
  for(int i = 0; i < n; ++i){
    cin >> a[i];
  }

  map<ll, ll> mp;
  mp[0] = 0;

  auto query = [&](ll l, ll r){
    auto it = mp.lower_bound(l);
    --it;

    ll lastVal = it -> second;
    ll sum = (r - l + 1) * 1ll * lastVal;

    while(true){
        auto it = mp.lower_bound(l);
        if(it == mp.end()){
            break;
        }
        ll ind = it -> first;
        if(ind > r + 1){
            break;
        }
        sum -= (r - ind + 1) * lastVal;
        lastVal = it -> second;
        sum += (r - ind + 1) * lastVal;
        mp.erase(it);
    }
    mp[l] = 1;
    mp[r + 1] = lastVal;

    ll res = (r - l + 1) - sum;

    return res;
  };

  set<int> st;
  st.insert(a[0]);

  vector<ll> res;
  ll cur = 0;

  for(int i = 1; i < n; ++i){
    auto it = st.lower_bound(a[i]);
    if(it != st.begin()){
      ll x = *(--it);
      ll l = max(1ll, a[i] - x + 1);
      ll r = max(1ll, a[i] + x - 1);
      cur += query(l, r);
    }
    it = st.lower_bound(a[i]);
    if(it != st.end()){
      ll y = *it;
      ll l = max(1ll, y - a[i] +1);
      ll r = max(1ll, y + a[i] - 1);
      cur += query(l, r);
    }
    st.insert(a[i]);
    res.push_back(cur);
  }

  for(ll elem: res){
    cout << elem << ' ';
  }
  cout << '\n';
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
 
