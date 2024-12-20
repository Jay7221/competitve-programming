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
 
template < int MOD = 1000000007, typename T = int > struct ModInt {

    T val;

    ModInt(T V = 0) : val(V) { val %= MOD; }

    ModInt& operator += (const ModInt& rhs) {
        if ((val += rhs.val) >= MOD) val -= MOD;
        return *this;
    }
    ModInt& operator += (const T rhs) {
        if ((val += rhs) >= MOD) val -= MOD;
        return *this;
    }

    ModInt& operator -= (const ModInt& rhs) { 
        if ((val += MOD - rhs.val) >= MOD) val -= MOD; 
        return *this; 
    }
    ModInt& operator -= (const T rhs) { 
        if ((val += MOD - rhs) >= MOD) val -= MOD; 
        return *this; 
    }

    ModInt& operator *= (const ModInt& rhs) { val = (1ll * val * rhs.val) % MOD; return *this; }
    ModInt& operator *= (const T rhs) { val = (1ll * val * rhs) % MOD; return *this; }

    ModInt& operator /= (const ModInt& rhs) { return *this *= rhs.inverse(); }
    ModInt& operator /= (const T rhs) { return *this *= ModInt(rhs).inverse(); }

    ModInt& operator %= (const ModInt& rhs) { val %= rhs.val; return *this; }
    ModInt& operator %= (const T rhs) { val %= rhs; return *this; }

    ModInt& operator ++() { return *this += 1; }
    ModInt& operator --() { return *this -= 1; }
 
    ModInt operator ++(T unused) { ModInt res(*this); ++*this; return res; }
    ModInt operator --(T unused) { ModInt res(*this); --*this; return res; }
    
    ModInt operator + (const ModInt& rhs) const { ModInt res(*this); return res += rhs; }
    ModInt operator + (const T rhs) const { ModInt res(*this); return res += rhs; }

    ModInt operator % (const ModInt& rhs) const { ModInt res(*this); return res %= rhs; }
    ModInt operator % (const T rhs) const { ModInt res(*this); return res %= rhs; }

    ModInt operator - (const ModInt& rhs) const { ModInt res(*this); return res -= rhs; }
    ModInt operator - (const T rhs) const { ModInt res(*this); return res -= rhs; }

    ModInt operator * (const ModInt& rhs) const { ModInt res(*this); return res *= rhs; }
    ModInt operator * (const T rhs) const { ModInt res(*this); return res *= rhs; }

    ModInt operator / (const ModInt& rhs) const { ModInt res(*this); return res /= rhs; }
    ModInt operator / (const T rhs) const { ModInt res(*this); return res /= rhs; }

    ModInt& operator = (const ModInt& rhs) { val = rhs.val; return *this; }
    ModInt& operator = (const T rhs) { val = rhs; return *this; }

    T operator ~ () { return ~val; }
    bool operator ! () { return !val; }

    bool operator == (const ModInt& rhs) const { return val == rhs.val; }
    bool operator == (const T rhs) const { return val == rhs; }

    bool operator != (const ModInt& rhs) const { return val != rhs.val; }
    bool operator != (const T rhs) const { return val != rhs; }

    bool operator < (const ModInt& rhs) const { return val < rhs.val; }
    bool operator < (const T rhs) const { return val < rhs; }

    bool operator <= (const ModInt& rhs) const { return val <= rhs.val; }
    bool operator <= (const T rhs) const { return val <= rhs; }

    bool operator > (const ModInt& rhs) const { return val > rhs.val; }
    bool operator > (const T rhs) const { return val > rhs; }

    bool operator >= (const ModInt& rhs) const { return val >= rhs.val; }
    bool operator >= (const T rhs) const { return val >= rhs; }

    T operator () () const { return val; }

    ModInt inverse() const { return power(MOD - 2); }

    ModInt power(T n) const {
        ModInt a = *this, res = 1;
        while (n > 0) {
            if (n & 1) res *= a;
            a *= a, n >>= 1;
        }
        return res;
    }

    ModInt power(ModInt n) const {
        ModInt a = *this, res = 1;
        T e = n();
        while (e > 0) {
            if (e & 1) res *= a;
            a *= a, e >>= 1;
        }
        return res;
    }

    friend ModInt operator ^ (ModInt rhs, T n) { return rhs.power(n); }
    friend ModInt operator ^ (ModInt rhs, ModInt n) { return rhs.power(n); }

    friend std::istream& operator>>(std::istream& is, ModInt& x) noexcept { return is >> x.val; }
    friend std::ostream& operator<<(std::ostream& os, const ModInt& x) noexcept { return os << x.val; }

};


const int MOD = 1e9 + 7;
typedef ModInt<MOD> modint;

void dfs(int u, vector<vector<int>> &adj, vector<bool> &vis){
    vis[u] = true;
    for(int v: adj[u]){
        if(!vis[v]){
            dfs(v, adj, vis);
        }
    }
}

vector<vector<int>> build_graph(int n, vector<pair<int, int>> &conditions){
    vector<vector<int>> adj(n);
    for(auto [u, v]: conditions){
        --u, --v;
        adj[u].push_back(v);
    }
    return adj;
}

modint solve(int n, int m, vector<pair<int, int>> &conditions) {
    vector<vector<int>> adj = build_graph(n, conditions);

    modint res = 1;
    for(int i = 1; i <= n; ++i){
        res *= i;
    }

    for(int i = 0; i < n; ++i){
        vector<bool> vis(n);
        dfs(i, adj, vis);
        int subtree_size = accumulate(vis.begin(), vis.end(), 0);
        res /= subtree_size;
    }

    return res;
}

void dfs_fail(int u, vector<vector<int>> &adj, vector<bool> &vis, vector<int> &dp){
    for(int v: adj[u]){
        dfs_fail(v, adj, vis, dp);
        dp[u] += dp[v];
    }
}

modint solve_fail_2(int n, int m, vector<pair<int, int>> &conditions){
    vector<int> numChildren(n, 1);

    for(auto [u, v]: conditions){
        ++numChildren[u];
    }

    modint res = 1;
    for(int i = 1; i <= n; ++i){
        res *= i;
    }
    for(int i = 0; i < n; ++i){
        res /= numChildren[i];
    }
    return res;
}

modint solve_fail(int n, int m, vector<pair<int, int>> &conditions){
    vector<vector<int>> adj = build_graph(n, conditions);

    vector<int> dp(n, 1);
    vector<bool> vis(n);
    for(int i = 0; i < n; ++i){
        if(!vis[i]){
            dfs_fail(i, adj, vis, dp);
        }
    }

    modint res = 1;
    for(int i = 1; i <= n; ++i){
        res *= i;
    }
    for(int i = 0; i < n; ++i){
        res /= dp[i];
    }
    return res;
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> conditions;

    for(int i = 0; i < m; ++i){
        int u, v;
        cin >> u >> v;
        conditions.push_back(make_pair(u, v));
    }

    if(solve(n, m, conditions) == solve_fail(n, m, conditions)){
        cerr << "Weak Testcase!\n";
    }
    else{
        cerr << "Good Testcase!\n";
    }

    assert(solve(n, m, conditions) == solve(n, m, conditions));
    cout << solve(n, m, conditions);

    return 0;
}
 
