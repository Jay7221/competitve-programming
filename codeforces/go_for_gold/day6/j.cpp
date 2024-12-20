/*
Author: Prajwal Shah
Language: C++
Final Year BTech IT
Walchand College of Engineering, Sangli
*/

//_________________________________________________________//
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pajju             main
#define Prajwal           ios_base::sync_with_stdio(false);
#define Shah              cin.tie(NULL);
#define ll                long long
#define pb                push_back
#define mod               1000000007
#define ff                first
#define ss                second
#define pinf              1e16
#define ninf              -1e16
//_______________________________________________________//

using namespace std;
using namespace __gnu_pbds;
template<class T> using ordered_set =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;

/*----------------- Debugging Starts -------------------------------------------------*/

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

/*----------------- Debugging Ends -------------------------------------------------*/
/*----------------- Solution Starts Here -------------------------------------------------*/
template <int MOD=1000000007>
struct Modular {
  int value;
  static const int MOD_value = MOD;

  Modular(long long v = 0) { value = v % MOD; if (value < 0) value += MOD;}
  Modular(long long a, long long b) : value(0){ *this += a; *this /= b;}

  Modular& operator+=(Modular const& b) {value += b.value; if (value >= MOD) value -= MOD; return *this;}
  Modular& operator-=(Modular const& b) {value -= b.value; if (value < 0) value += MOD;return *this;}
  Modular& operator*=(Modular const& b) {value = (long long)value * b.value % MOD;return *this;}

  friend Modular mexp(Modular a, long long e) {
    Modular res = 1; while (e) { if (e&1) res *= a; a *= a; e >>= 1; }
    return res;
  }
  friend Modular inverse(Modular a) { return mexp(a, MOD - 2); }

  Modular& operator/=(Modular const& b) { return *this *= inverse(b); }
  friend Modular operator+(Modular a, Modular const b) { return a += b; }
  friend Modular operator-(Modular a, Modular const b) { return a -= b; }
  friend Modular operator-(Modular const a) { return 0 - a; }
  friend Modular operator*(Modular a, Modular const b) { return a *= b; }
  friend Modular operator/(Modular a, Modular const b) { return a /= b; }
  friend std::ostream& operator<<(std::ostream& os, Modular const& a) {return os << a.value;}
  friend bool operator==(Modular const& a, Modular const& b) {return a.value == b.value;}
  friend bool operator!=(Modular const& a, Modular const& b) {return a.value != b.value;}
};
using mint = Modular<1000000007>;
const int N = 2000010;
mint fact[N], invfact[N];
void init() {
  fact[0] = 1;
  for (int i = 1; i < N; i++) fact[i] = fact[i - 1] * i;
  invfact[N - 1] = inverse(fact[N - 1]);
  for (int i = N - 2; i >= 0; i--) invfact[i] = invfact[i + 1] * (i + 1);
}
mint catalan(int n) {
  return fact[2 * n] * invfact[n + 1] * invfact[n];
}
void solve(){
    int n; cin >> n;
    vector<int>a(n); for(int &i : a) cin >> i;
    int cnt = 0;
    mint ans = 1;

    if(n > 0){
        for(int i = 0; i < n; ++i){
            if(i == 0 or (a[i] == a[i - 1])){
                cnt++;
            }
            else{
                ans *= catalan(cnt);
                cnt = 1;
            }
        }
        ans *= catalan(cnt);

        stack<int> st;
        st.push(a[0]);
        for(int i = 1; i < n; ++i){
            while(!st.empty() && (st.top() > a[i])){
                st.pop();
            }
            if(a[i - 1] > a[i]){
                if(!st.empty() && (st.top() == a[i])){
                    ans *= 2;
                }
            }
        }
    }

    cout << ans << '\n';
}
int pajju()
{
    Prajwal Shah;
    init();
    solve();
    return 0;
}
