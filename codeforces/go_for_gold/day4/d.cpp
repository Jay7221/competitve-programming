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
    int a, b, c;
    cin >> a >> b >> c;

    int mx = max({a, b, c});
    if(mx * mx > a * b * c){
        cout << -1 << '\n';
        return;
    }

    vector<tuple<int, int, int>> points;
    points.push_back({0, 0, 0});
    --a, --b, --c;

    int i = -1;
    mx = max({a, b, c});
    while(2 * mx < a + b + c){
        points.push_back({i, i, i});
        --i;
        --a, --b, --c;
        mx = max({a, b, c});
    }

    if(b + c <= a){
        for(int i = 1; i <= b; ++i){
            points.push_back({i, 0, 0});
        }
        for(int i = 1; i <= c; ++i){
            points.push_back({0, i, 0});
        }
        a -= b + c;
        for(int x = 1; (x <= b) && (a > 0); ++x){
            for(int y = 1; (y <= c) && (a > 0); ++y){
                --a;
                points.push_back({x, y, 0});
            }
        }
    }
    else if(a + c <= b){
        for(int i = 1; i <= a; ++i){
            points.push_back({i, 0, 0});
        }
        for(int i = 1; i <= c; ++i){
            points.push_back({0, 0, i});
        }
        b -= a + c;
        for(int x = 1; x <= a && b > 0; ++x){
            for(int z = 1; z <= c && b > 0; ++z){
                --b;
                points.push_back({x, 0, z});
            }
        }
    }
    else{
        for(int i = 1; i <= a; ++i){
            points.push_back({0, i, 0});
        }
        for(int i = 1; i <= b; ++i){
            points.push_back({0, 0, i});
        }
        c -= a + b;
        for(int y = 1; y <= a && c > 0; ++y){
            for(int z = 1; z <= b && c > 0; ++z){
                --c;
                points.push_back({0, y, z});
            }
        }
    }

    cout << points.size() << '\n';
    for(auto [x, y, z]: points){
        cout << x << ' ' << y << ' ' << z << '\n';
    }
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
    
    return 0;
}
 
