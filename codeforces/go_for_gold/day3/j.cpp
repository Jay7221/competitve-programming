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
 
class Double{
public:
    ll x, y;
    Double(ll x, ll y){
        assert(y != 0);
        ll d = gcd(x, y);
        x /= d;
        y /= d;
        this -> x = x;
        this -> y = y;
    }
    ll upper_bound(){
        return (x + y - 1) / y;
    }
};

int operator<(Double a, Double b){
    return a.x * b.y < b.x * a.y;
}

Double operator+(Double a, Double b){
    return Double(a.x * b.y + b.x * a.y, a.y * b.y);
}

Double operator/(Double a, Double b){
    return Double(a.x * b.y, a.y * b.x);
}

Double operator*(Double a, Double b){
    return Double(a.x * b.x, a.y * b.y);
}

Double operator-(int x, Double a){
    return Double(x * a.y - a.x, a.y);
}
 
void solve() {
    int n;
    cin >> n;
    int m = 2 * n;
    vector<int> a(m + 1), h(m + 1);
    for(int i = 0; i < m; ++i){
        cin >> a[i];
    }
    int joon_x;
    cin >> joon_x;

    for(int i = 1; i < m; ++i){
        int diff = a[i] - a[i - 1];
        if(i & 1){
            h[i] = h[i - 1] + diff;
        }
        else{
            h[i] = max(0, h[i - 1] - diff);
        }
    }
    a[m] = a[m - 1] + h[m - 1];

    Double joon_y(0, 1);
    for(int i = m - 1; i >= 0; --i){
        if(a[i] <= joon_x){
            ll djx = joon_x - a[i];
            ll dx = a[i + 1] - a[i];
            ll dy = h[i + 1] - h[i];
            if(dx > 0){
                joon_y = Double(h[i] * dx + dy * djx, dx);
            }
            else{
                joon_y = Double(h[i], 1);
            }
            break;
        }
    }

    Double res(0, 1);
    for(int i = 1; i < m; i += 2){
        if(a[i] >= joon_x){
            break;
        }

        Double dy = h[i] - joon_y;
        ll dx = joon_x - a[i];
        assert(dx != 0);
        Double diff = dy * Double(joon_x, dx);

        res = max(res, joon_y + diff);
    }

    cout << res.upper_bound() << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    solve();
    
    return 0;
}
 
