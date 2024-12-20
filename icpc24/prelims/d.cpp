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


const int MOD = 998244353;
typedef ModInt<MOD> modint;

const int MAX = 4e6 + 7;
vector<int> coins;
vector<modint> dp(MAX);

void pre(){
    for(int i = 4, j = 1; i < MAX; i *= 2, ++j){
        coins.push_back(i * j);
    }
    dp[0] = 1;
    for(int coin: coins){
        for(int i = 0; i < MAX; ++i){
            if(i + coin < MAX){
                dp[i + coin] += dp[i];
            }
        }
    }
}
 
void solve() {
    int n;
    cin >> n;
    cout << dp[n] << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    pre();
 
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; ++t){
//        cout << "# Case " << i << " : ";
        solve();
    }
    
    return 0;
}
 
