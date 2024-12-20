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
 
void dfs(int u, int p, vector<vector<int>> &adj, vector<int> &par, vector<int> &nodes){
  par[u] = p;
  for(auto child: adj[u]){
    if(child != p){
      dfs(child, u, adj, par, nodes);
    }
  }
  nodes.push_back(u);
}
 
void solve() {
  int n;
  cin >> n;
  vector<vector<int>> adj(n);

  for(int i = 0; i < n - 1; ++i){
    int u, v;
    cin >> u >> v;
    --u, --v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  if(n == 2){
    cout << 1 << '\n';
    cout << 1 << ' ' << 2 << ' ' << 1 << '\n';
    return;
  }

  vector<int> nodes;
  vector<int> par(n);

  dfs(0, -1, adj, par, nodes);

  cout << 0 << '\n';

  vector<tuple<int, int, int>> operations;

  if(n & 1){
    for(int u: nodes){
      if(par[u] == -1){
        break;
      }
      operations.push_back(make_tuple(u, par[u], u));
    }
  }
  else{
    int sz = n - 1;
    for(int u: nodes){
      if(par[u] == -1){
        break;
      }
      if((sz == 3) || (sz == 2)){
        operations.push_back(make_tuple(u, par[u], par[u]));
      }
      else{
        operations.push_back(make_tuple(u, par[u], u));
      }
      --sz;
    }
  }

  for(auto [u, v, x]: operations){
    cout << (u + 1) << ' ' << (v + 1) << ' ' << (x + 1) << '\n';
  }

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
 
