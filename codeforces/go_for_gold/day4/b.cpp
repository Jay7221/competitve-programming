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
 
bool check(int x, int y, int w, int h){
    return {
        ((x <= w) && (y <= h)) ||
        ((y <= w) && (x <= h))
    };
}

vector<pair<tuple<int, int, int>, tuple<int, int, int>>> arrangements = {
    {{2, 0, 2}, {0, 1, 2}},
    {{0, 1, 1}, {3, 1, 1}},
    {{1, 1, 1}, {2, 1, 1}},
    {{1, 2, 1}, {2, 0, 1}}
};


bool check(int a, int b, int c, int w, int h){

    for(auto arrangement: arrangements){
        auto [dx, dy] = arrangement;
        int xa, xb, xc;
        tie(xa, xb, xc) = dx;
        int ya, yb, yc;
        tie(ya, yb, yc) = dy;
        if(check(a * xa + b * xb + c * xc, a * ya + b * yb + c * yc, w, h)){
            return true;
        }
    }

    return false;
}
 
bool solve() {
    int a, b, c;
    int w, h;

    cin >> a >> b >> c;
    cin >> w >> h;

    return (
        check(a, b, c, w, h) ||
        check(a, c, b, w, h) ||
        check(b, a, c, w, h) ||
        check(b, c, a, w, h) ||
        check(c, a, b, w, h) ||
        check(c, b, a, w, h)
    );
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    if(solve()){
        cout << "Yes";
    }
    else{
        cout << "No";
    }
    
    return 0;
}
 
