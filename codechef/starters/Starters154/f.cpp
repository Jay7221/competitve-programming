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
 
vector<vector<int>> adj;
vector<int> dpmin, dpmax;

void dfs(int u, int p){
  for(int child: adj[u]){
    if(child != p){
      dpmin[child] = min(dpmin[child], dpmin[u]);
      dpmax[child] = max(dpmax[child], dpmax[u]);
      dfs(child, u);
    }
  }
}

void solve() {
  int n, s;
  cin >> n >> s;

  adj = vector<vector<int>>(n + 1);
  for(int i = 0; i < n - 1; ++i){
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dpmin = vector<int>(n + 1);
  dpmax = vector<int>(n + 1);
  for(int i = 1; i <= n; ++i){
    dpmin[i] = dpmax[i] = i;
  }

  dfs(s, -1);

  vector<ll> cost(n + 1);
  for(int i = 1; i <= n; ++i){
    cost[i] = dpmin[i] * 1ll * dpmax[i];
  }
  cost[s] = 0;

  for(int i = 1; i <= n; ++i){
    for(int j = 1; j <= n; ++j){
      ll cost_to_j = dpmin[j] * 1ll * dpmax[j];
      ll cost_i_to_j = min(dpmin[i], dpmin[j]) * 1ll * max(dpmax[i], dpmax[j]);
      if(j == 1){
        cerr << i << " : " << cost_to_j << ' ' << cost_i_to_j << '\n';
      }
      cost[i] = min(cost[i], cost_to_j + cost_i_to_j);
    }
  }

  for(int i = 1; i <= n; ++i){
    cout << cost[i] << ' ';
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
 
