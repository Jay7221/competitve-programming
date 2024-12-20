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
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for(int i = 0; i < n; ++i){
        cin >> grid[i];
    }

    auto check = [&](int x, int y){
        return ((x >= 0) && (y >= 0) && (x < n) && (y < m));
    };

    auto neighbours = [&](int x, int y){
        map<char, vector<pair<int, int>>> d = {
            {'L', {{0, -1}}},
            {'R', {{0, 1}}},
            {'U', {{-1, 0}}},
            {'D', {{1, 0}}},
            {'?', {{0, -1}, {0, 1}, {-1, 0}, {1, 0}}}
        };
        vector<pair<int, int>> res;
        for(auto [dx, dy]: d[grid[x][y]]){
            if(check(x + dx, y + dy)){
                res.push_back({x + dx, y + dy});
            }
        }
        return res;
    };

    vector<vector<int>> vis(n, vector<int>(m));

    function<void(int, int)> dfs = [&](int x, int y){
        vis[x][y] = 1;
        for(auto [nx, ny]: neighbours(x, y)){
            if(vis[nx][ny] == 0){
                dfs(nx, ny);
            }
            if(vis[nx][ny] == 1){
                return;
            }
        }
        vis[x][y] = 2;
    };

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(vis[i][j] == 0){
                dfs(i, j);
            }
        }
    }

    int res = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            res += (vis[i][j] == 1);
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
 
