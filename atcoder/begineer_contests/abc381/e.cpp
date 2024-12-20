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
 
const int INF = 1e9 + 7;
struct SegmentTree{
    int f(int a, int b){
        return min(a, b);
    }
    vector<int> tree;
    int n;
    void init(int sz){
        n = 1;
        while(n < sz){
            n <<= 1;
        }
        tree = vector<int>(2 * n, INF);
    }
    SegmentTree(){
    }
    SegmentTree(int sz){
        init(sz);
    }
    SegmentTree(vector<int> &arr){
        int sz = arr.size();
        init(sz);
        for(int i = 0; i < sz; ++i){
            tree[i + n] = arr[i];
        }
        for(int i = n - 1; i > 0; --i){
            tree[i] = f(tree[2 * i], tree[2 * i + 1]);
        }
    }
    void set(int ind, int val){
        ind += n;
        tree[ind] = val;
        ind >>= 1;
        while(ind > 0){
            tree[ind] = f(tree[2 * ind], tree[2 * ind + 1]);
            ind >>= 1;
        }
    }
    int get(int l, int r){
        l += n;
        r += n;
        int res = INF;
        while(l <= r){
            if((l & 1) == 1){
                res = f(res, tree[l]);
                ++l;
            }
            if((r & 1) == 0){
                res =  f(res, tree[r]);
                --r;
            }
            l >>= 1;
            r >>= 1;
        }
        return res;
    }
};
 
void solve() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<int> pre1(n + 2), pre2(n + 2);
    for(int i = 1; i <= n; ++i){
        pre1[i] = pre1[i - 1] + (s[i - 1] == '1');
        pre2[i] = pre2[i - 1] + (s[i - 1] == '2');
    }

    vector<int> val(n + 2, INF);
    for(int i = 1; i <= n; ++i){
        if(s[i - 1] == '/'){
            val[i] = pre2[i];
        }
    }

    SegmentTree segtree(val);

    auto check = [&](int l, int r, int x){
        int L = l, R = r;
        while(L < R){
            int mid = (L + R) / 2;
            if(pre1[mid] - pre1[l - 1] < x){
                L = mid + 1;
            }
            else{
                R = mid;
            }
        }
        return (pre2[r] - segtree.get(L, r) >= x);
    };

    auto query = [&](int l, int r){
        if(segtree.get(l, r) == INF){
            return 0;
        }
        int resL = 0, resR = (r - l + 1) / 2;
        while(resL < resR){
            int mid = (resR + resL + 1) / 2;
            if(check(l, r, mid)){
                resL = mid;
            }
            else{
                resR = mid - 1;
            }
        }
        return 1 + 2 * resL;
    };

    while(q--){
        int l, r;
        cin >> l >> r;
        cout << query(l, r) << '\n';
    }
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    int tc = 1;
    for(int t = 1; t <= tc; ++t){
//        cout << "# Case " << i << " : ";
        solve();
    }
    
    return 0;
}
 
