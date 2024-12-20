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

class LiChaoTree {
public:
    struct Line {
        long long m, c;
        Line(long long slope = 0, long long intercept = std::numeric_limits<long long>::max())
            : m(slope), c(intercept) {}
        
        long long get_value(long long x) const {
            return m * x + c;
        }
    };

    LiChaoTree(long long minX, long long maxX)
        : minX(minX), maxX(maxX) {
        root = new Node();
    }

    void add_line(long long m, long long c) {
        Line newLine(m, c);
        add_line(root, minX, maxX, newLine);
    }

    long long query(long long x) {
        return query(root, minX, maxX, x);
    }

private:
    struct Node {
        Line line;
        Node* left = nullptr;
        Node* right = nullptr;
    };

    Node* root;
    long long minX, maxX;

    void add_line(Node* node, long long l, long long r, Line newLine) {
        if (!node) return;

        long long mid = (l + r) / 2;

        bool left = newLine.get_value(l) < node->line.get_value(l);
        bool middle = newLine.get_value(mid) < node->line.get_value(mid);

        if (middle) {
            std::swap(node->line, newLine);
        }

        if (l == r) return;

        if (left != middle) {
            if (!node->left) node->left = new Node();
            add_line(node->left, l, mid, newLine);
        } else {
            if (!node->right) node->right = new Node();
            add_line(node->right, mid + 1, r, newLine);
        }
    }

    long long query(Node* node, long long l, long long r, long long x) const {
        if (!node) return std::numeric_limits<long long>::max();

        long long mid = (l + r) / 2;
        long long result = node->line.get_value(x);

        if (x <= mid) {
            if (node->left) {
                result = std::min(result, query(node->left, l, mid, x));
            }
        } else {
            if (node->right) {
                result = std::min(result, query(node->right, mid + 1, r, x));
            }
        }

        return result;
    }
};

const ll INF = 1e9 + 7;
 
void solve() {
    int n;
    cin >> n;
    vector<ll> a(n), x(n);
    for(int i = 0; i < n; ++i){
        cin >> x[i];
    }
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

    vector<pair<ll, ll>> v;
    for(int i = 0; i < n; ++i){
        v.push_back({x[i], a[i]});
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < n; ++i){
        tie(x[i], a[i]) = v[i];
    }

    ll res = 0;
    int minInd = 0;
    for(int i = 0; i < n; ++i){
        if(a[i] < a[minInd]){
            minInd = i;
        }
    }


    LiChaoTree hull(0, INF);

    hull.add_line(a[minInd], -x[minInd] * a[minInd]);
    for(int i = minInd + 1; i < n; ++i){
        ll m = a[i];
        ll c = -x[i] * a[i];
        res += hull.query(x[i]);
        hull.add_line(m, c);
    }

    LiChaoTree hull2(0, INF);

    hull2.add_line(-a[minInd], x[minInd] * a[minInd]);
    for(int i = minInd - 1; i >= 0; --i){
        ll m = -a[i];
        ll c = x[i] * a[i];
        res += hull2.query(x[i]);
        hull2.add_line(m, c);
    }

    cout << res << '\n';
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
 
