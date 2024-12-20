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
 
bool check(vector<int> &p, int n, int l, int r){
    int sum = 0;
    for(int i = l; i <= r; ++i){
        sum = (sum + p[i]) % (n + 1);
    }
    return (sum != 0);
}

bool check(vector<int> &p){
    int n = p.size();
    for(int i = 0; i < n; ++i){
        for(int j = i; j < n; ++j){
            if(!check(p, n, i, j)){
                return false;
            }
        }
    }
    return true;
}

bool check_fast(vector<int> &p){
    int n = p.size();
    map<int, bool> vis;
    int pre = 0;
    vis[0] = true;
    for(int elem: p){
        pre = (pre + elem) % (n + 1);
        if(vis[pre]){
            return false;
        }
        vis[pre] = true;
    }
    return true;
}

void brute(int n){
    vector<int> p(n);
    for(int i = 0; i < n; ++i){
        p[i] = i + 1;
    }
    do{
        if(check(p)){
            cerr << p << '\n';
        }
    }while(next_permutation(p.begin(), p.end()));
    cerr << "-------------\n";

}
 
vector<int> solve(int n) {
    if(!(n & 1)){
        return {-1};
    }
    vector<int> p(n);

    for(int i = 0; i < n; ++i){
        p[i] = i + 1;
    }

    for(int i = 1, j = n - 2; i < j; i += 2, j -= 2){
        swap(p[i], p[j]);
    }

    return p;
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; ++t){
        int n;
        cin >> n;
        for(int elem: solve(n)){
            cout << elem << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}
 
