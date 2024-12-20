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
 
const int N = 6, M = 7;
vector<vector<vector<pair<int, int>>>> coords(13);
vector<vector<pair<int, int>>> lines;

int cost(vector<pair<int, int>> &line){
    vector<int> height(M);
    for(auto [x, y]: line){
        height[y] = max(height[y], x + 1);
    }
    return accumulate(height.begin(), height.end(), 0);
}

void pre(){
    for(int y = 0; y < M; ++y){
        for(int x = 0; x + 3 < N; ++x){
            vector<pair<int, int>> line;
            for(int j = 0; j < 4; ++j){
                line.push_back({x + j, y});
            }
            lines.push_back(line);
        }
    }
    for(int x = 0; x < N; ++x){
        for(int y = 0; y + 3 < M; ++y){
            vector<pair<int, int>> line;
            for(int j = 0; j < 4; ++j){
                line.push_back({x, y + j});
            }
            lines.push_back(line);
        }
    }
    for(int x = 0; x + 3 < N; ++x){
        for(int y = 0; y + 3 < M; ++y){
            vector<pair<int, int>> line;
            for(int j = 0; j < 4; ++j){
                line.push_back({x + j, y + j});
            }
            lines.push_back(line);
        }
    }

    for(int x = 3; x < N; ++x){
        for(int y = 0; y + 3 < M; ++y){
            vector<pair<int, int>> line;
            for(int j = 0; j < 4; ++j){
                line.push_back({x - j, y + j});
            }
            lines.push_back(line);
        }
    }

    for(auto line: lines){
        coords[cost(line)].push_back(line);
    }
}

bool win(vector<string> &matrix, vector<pair<int, int>> &line, char ch){
    for(auto [x, y]: line){
        if(matrix[x][y] != ch){
            return false;
        }
    }
    return true;
}

bool comes_after(vector<pair<int, int>> &line1, vector<pair<int, int>> &line2){
    // does line1 come after line2 ?
    // that will happend only if every height of line2 >= line1
    vector<int> h1(M), h2(M);
    for(auto [x, y]: line1){
        h1[y] = max(h1[y], x + 1);
    }
    for(auto [x, y]: line2){
        h2[y] = max(h2[y], x + 1);
    }
    for(int i = 0; i < M; ++i){
        if(h1[i] == 0 && h2[i] == 0){
            continue;
        }
        if(h1[i] == 0){
            return false;
        }
        if(h2[i] == 0){
            continue;
        }
        if(h1[i] < h2[i]){
            return false;
        }
    }
    return true;
}
 
char solve() {
    vector<string> matrix(N);
    for(int i = 0; i < N; ++i){
        cin >> matrix[i];
    }
    reverse(matrix.begin(), matrix.end());

    vector<vector<pair<int, int>>> linesc, linesf;

    char res = '0';
    for(auto line: lines){
        if(win(matrix, line, 'C')){
            res = '?';
            linesc.push_back(line);
        }
        if(win(matrix, line, 'F')){
            res = '?';
            linesf.push_back(line);
        }
    }
    if(res == '0'){
        return res;
    }
    bool winc = true;
    for(auto line: linesf){
        bool notwin = true;
        for(auto line2: linesc){
            if(comes_after(line, line2)){
                notwin = false;
            }
        }
        if(notwin){
            winc = false;
        }
    }
    if(winc){
        return 'C';
    }

    bool winf = true;
    for(auto line: linesc){
        bool notwin = true;
        for(auto line2: linesf){
            if(comes_after(line, line2)){
                notwin = false;
            }
        }
        if(notwin){
            winf = false;
        }
    }
    if(winf){
        return 'F';
    }
    return res;
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    pre();
 
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; ++t){
        cout << "Case #" << t << ": ";
        cout << solve() << '\n';
    }
    
    return 0;
}
 
