#include <bits/stdc++.h>
 
using namespace std;
 
//#pragma GCC optimize("Ofast,unroll-loops") 
//#pragma GCC target("avx,avx2,avx512,fma") 
 
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename A, typename B, typename C> ostream& operator<<(ostream &os, const tuple<A, B, C> &p) { A a; B b; C c; tie(a, b, c) = p; return os << '(' << a << ", " << b << ", " << c << ')'; }
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
 
int n, m;
vector<vector<bool>> isFree;

bool isPointValid(int x, int y){
    return (x >= 0) && (x < n) && (y >= 0) && (y < m) && isFree[x][y];
}

bool isStateValid(int x, int y, bool vertical){
    if(vertical){
        return isPointValid(x, y) && isPointValid(x + 1, y);
    }
    else{
        return isPointValid(x, y) && isPointValid(x, y + 1);
    }
}

tuple<int, int, bool> getState(int x1, int y1, int x2, int y2){
    return make_tuple(min(x1, x2), min(y1, y2), (y1 == y2));
}

vector<tuple<int, int, bool>> getRotations(tuple<int, int, bool> &state){
    int x, y, vertical;
    tie(x, y, vertical) = state;
    vector<tuple<int, int, bool>> rotations;

    if(vertical){
        if(isPointValid(x + 1, y - 1) && isPointValid(x, y - 1)){
            rotations.push_back({x, y - 1, false});
        }
        if(isPointValid(x + 1, y + 1) && isPointValid(x, y + 1)){
            rotations.push_back({x, y, false});
        }
        if(isPointValid(x, y + 1) && isPointValid(x + 1, y + 1)){
            rotations.push_back({x + 1, y, false});
        }
        if(isPointValid(x, y - 1) && isPointValid(x + 1, y - 1)){
            rotations.push_back({x + 1, y - 1, false});
        }
    }
    else{
        if(isPointValid(x - 1, y + 1) && isPointValid(x - 1, y)){
            rotations.push_back({x - 1, y, true});
        }
        if(isPointValid(x + 1, y + 1) && isPointValid(x + 1, y)){
            rotations.push_back({x, y, true});
        }
        if(isPointValid(x - 1, y) && isPointValid(x - 1, y + 1)){
            rotations.push_back({x - 1, y + 1, true});
        }
        if(isPointValid(x + 1, y) && isPointValid(x + 1, y + 1)){
            rotations.push_back({x, y + 1, true});
        }
    }

    return rotations;
}

vector<tuple<int, int, bool>> getMovements(tuple<int, int, bool> &state){
    int x, y, vertical;
    tie(x, y, vertical) = state;
    vector<tuple<int, int, bool>> states;

    if(vertical){
        if(isPointValid(x - 1, y)){
            states.push_back({x - 1, y, true});
        }
        if(isPointValid(x + 2, y)){
            states.push_back({x + 1, y, true});
        }

        if(isPointValid(x, y - 1) && isPointValid(x + 1, y - 1)){
            states.push_back({x, y - 1, true});
        }
        if(isPointValid(x, y + 1) && isPointValid(x + 1, y + 1)){
            states.push_back({x, y + 1, true});
        }
    }
    else{
        if(isPointValid(x, y - 1)){
            states.push_back({x, y - 1, false});
        }
        if(isPointValid(x, y + 2)){
            states.push_back({x, y + 1, false});
        }

        if(isPointValid(x - 1, y) && isPointValid(x - 1, y + 1)){
            states.push_back({x - 1, y, false});
        }
        if(isPointValid(x + 1, y) && isPointValid(x + 1, y + 1)){
            states.push_back({x + 1, y, false});
        }
    }

    return states;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;

    isFree = vector<vector<bool>>(n, vector<bool>(m));
    vector<vector<char>> house(n, vector<char>(m));

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cin >> house[i][j];
            isFree[i][j] = (house[i][j] != 'H');
        }
    }

    map<tuple<int, int, bool>, bool> vis;
    map<tuple<int, int, bool>, int> dist;

    tuple<int, int, bool> start;
    tuple<int, int, bool> finish;

    for(int x = 0; x < n; ++x){
        for(int y = 0; y < m; ++y){
            for(int dx = -1; dx <= 1; ++dx){
                for(int dy = -1; dy <= 1; ++dy){
                    if(abs(dx) + abs(dy) == 1){
                        int xx = x + dx, yy = y + dy;
                        if(isPointValid(x, y) && isPointValid(xx, yy)){
                            if((house[x][y] == 's') && (house[xx][yy] == 's')){
                                start = getState(x, y, xx, yy);
                            }
                            if((house[x][y] == 'S') && (house[xx][yy] == 'S')){
                                finish = getState(x, y, xx, yy);
                            }
                        }
                    }
                }
            }
        }
    }

    queue<tuple<int, int, bool>> q;
    q.push(start);
    vis[start] = true;
    dist[start] = 0;

    while(!q.empty()){
        tuple<int, int, bool> cur = q.front();
        q.pop();

        for(auto state: getRotations(cur)){
            if(!vis[state]){
                dist[state] = dist[cur] + 1;
                vis[state] = true;
                q.push(state);
            }
        }
        for(auto state: getMovements(cur)){
            if(!vis[state]){
                dist[state] = dist[cur] + 1;
                vis[state] = true;
                q.push(state);
            }
        }
    }



    if(!vis[finish]){
        cout << "Impossible";
    }
    else{
        cout << dist[finish];
    }

    return 0;
}
 
