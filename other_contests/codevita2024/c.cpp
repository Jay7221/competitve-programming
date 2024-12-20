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
 
 
const int dx[] = {0, 0, -1, 1};  // Directions: Right, Left, Up, Down
const int dy[] = {1, -1, 0, 0};  // Directions: Right, Left, Up, Down
// Directions:
// 0: Right -> (0, 1)
// 1: Left -> (0, -1)
// 2: Up -> (-1, 0)
// 3: Down -> (1, 0)

// Mirror effect: given a mirror and a current direction, return the new direction
int getNextDirection(char mirror, int dir) {
    if (mirror == '/') {
        if(dir == 0) return 2;  // Right -> Up
        if(dir == 1) return 3;  // Left -> Down
        if(dir == 2) return 0;  // Up -> Right
        if(dir == 3) return 1;  // Down -> Left
    } else if (mirror == '\\') {
        if(dir == 0) return 3;  // Right -> Down
        if(dir == 1) return 2;  // Left -> Up
        if(dir == 2) return 1;  // Up -> Left
        if(dir == 3) return 0;  // Down -> Right
    }
    return dir;
}

pair<int, int> getNextPoint(int x, int y, int dir){
    return make_pair(x + dx[dir], y + dy[dir]);
}

// Function to convert (x, y) coordinates to a unique node ID
int getNodeId(int x, int y, int dir) {
    return (x * 50 + y) * 4 + dir;
}

void printNode(int node){
    int x = node / 200;
    int y = (node % 200) / 4;
    int d = node % 4;
    cerr << x << ' ' << y << ' ' << d << '\n';
}

int findLargestCycle(vector<vector<char>>& grid, int M, int N) {
    
    int maxCycleLength = 0;
    
    for (int startX = 0; startX < M; ++startX) {
        for (int startY = 0; startY < N; ++startY) {
            for (int startDir = 0; startDir < 4; ++startDir) {
                vector<bool> visited(50 * 50 * 4);
                vector<bool> nodeToStep(50 * 50 * 4);

                int currentX = startX, currentY = startY, currentDir = startDir;
                vector<int> path;

                while (true) {
                    if (currentX < 0 || currentX >= M || currentY < 0 || currentY >= N) {
                        break;
                    }
                    
                    int currentNode = getNodeId(currentX, currentY, currentDir);
                    
                    if(visited[currentNode]){
                        int cycleLength = path.size() - nodeToStep[currentNode];
                        maxCycleLength = max(maxCycleLength, cycleLength);
                        break;
                    }

                    visited[currentNode] = true;
                    nodeToStep[currentNode] = path.size();
                    path.push_back(currentNode);
                    
                    currentDir = getNextDirection(grid[currentX][currentY], currentDir);
                    tie(currentX, currentY) = getNextPoint(currentX, currentY, currentDir);
                }
                
            }
        }
    }
    
    return maxCycleLength;
}

int main() {
    int M, N;
    cin >> M >> N;
    
    vector<vector<char>> grid(M, vector<char>(N));
    
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> grid[i][j];
        }
    }
    
    int result = findLargestCycle(grid, M, N);
    
    cout << result;
    
    return 0;
}
