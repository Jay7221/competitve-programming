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
 
void build(int n, map<int, int> &ind, vector<pair<int, int>> &trees){
    if(ind.find(n) != ind.end()){
        return;
    }

    int left = (n + 1) / 2;
    int right = n / 2;
    build(left, ind, trees);
    build(right, ind, trees);

    ind[n] = trees.size();
    trees.push_back({ind[left], ind[right]});
}
 
void solve() {
    int n;
    cin >> n;

    queue<int> q;
    q.push(n);

    map<int, int> ind;
    vector<pair<int, int>> trees;

    trees.push_back({-1, -1});
    ind[1] = 0;

    build(n, ind, trees);

    cout << trees.size() << '\n';
    for(auto [u, v]: trees){
        cout << u << ' ' << v << '\n';
    }
    cout << ind[n] << '\n';
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
 
