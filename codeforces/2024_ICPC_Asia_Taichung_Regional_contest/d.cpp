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
 
const int NUM_DIR = 4;
const int NUM_STEPS = 3;
// direction
// 0 -> up
// 1 -> down
// 2 -> left
// 3 -> right
vector<pair<int, int>> d = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1}
};
const int INF = 1e9 + 7;

void init_adj(int n, int m, vector<vector<int>> &adj, vector<string> &grid){
    auto get_node_num = [&](int x, int y, int dir, int steps){
        // you are at node (x, y) and have walked steps steps in direction dir
        return ((x * m + y) * NUM_DIR + dir) * NUM_STEPS + steps;
    };
    auto check = [&](int x, int y){
        return ((x >= 0) && (y >= 0) && (x < n) && (y < m)) && (grid[x][y] != '#');
    };
    for(int x = 0; x < n; ++x){
        for(int y = 0; y < m; ++y){
            if(!check(x, y)){
                continue;
            }
            for(int dir = 0; dir < NUM_DIR; ++dir){
                // Continue in the same direction
                int dx, dy;
                tie(dx, dy) = d[dir];
                if(check(x + dx, y + dy)){
                    for(int steps = 0; steps + 1 < NUM_STEPS; ++steps){
                        adj[get_node_num(x, y, dir, steps)].push_back(get_node_num(x + dx, y + dy, dir, steps + 1));
                    }
                }

                // Change direction
                for(int ndir = 0; ndir < NUM_DIR; ++ndir){
                    if(dir != ndir){
                        int dx, dy;
                        tie(dx, dy) = d[ndir];
                        if(check(x + dx, y + dy)){
                            for(int steps = 0; steps < NUM_STEPS; ++steps){
                                adj[get_node_num(x, y, dir, steps)].push_back(get_node_num(x + dx, y + dy, ndir, 0));
                            }
                        }
                    }
                }
            }
        }
    }
}
 
void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for(int i = 0; i < n; ++i){
        cin >> grid[i];
    }


    auto get_node_num = [&](int x, int y, int dir, int steps){
        // you are at node (x, y) and have walked steps steps in direction dir
        return ((x * m + y) * NUM_DIR + dir) * NUM_STEPS + steps;
    };


    int N = n * m * NUM_DIR * NUM_STEPS;
    vector<vector<int>> adj(N);
    vector<int> dp(N, INF);

    init_adj(n, m, adj, grid);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for(int x = 0; x < n; ++x){
        for(int y = 0; y < m; ++y){
            if(grid[x][y] == 'S'){
                for(int dir = 0; dir < NUM_DIR; ++dir){
                    for(int steps = 0; steps < NUM_STEPS; ++steps){
                        int u = get_node_num(x, y, dir, steps);
                        dp[u] = 0;
                        pq.push({dp[u], u});
                    }
                }
            }
        }
    }

    while(!pq.empty()){
        int dist, u;
        tie(dist, u) = pq.top();
        pq.pop();
        if(dist != dp[u]){
            continue;
        }
        for(int v: adj[u]){
            if(dp[v] > dp[u] + 1){
                dp[v] = dp[u] + 1;
                pq.push({dp[v], v});
            }
        }
    }

    int res = INF;
    for(int x = 0; x < n; ++x){
        for(int y = 0; y < m; ++y){
            if(grid[x][y] == 'T'){
                for(int dir = 0; dir < NUM_DIR; ++dir){
                    for(int steps = 0; steps < NUM_STEPS; ++steps){
                        int u = get_node_num(x, y, dir, steps);
                        res = min(res, dp[u]);
                    }
                }
            }
        }
    }
    if(res == INF){
        res = -1;
    }
    cout << res << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    solve();
    
    return 0;
}
 
