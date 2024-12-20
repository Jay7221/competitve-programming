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
 
void solve() {
    int n;
    cin >> n;

    vector<int> cx, cy, id;
    set<pair<int, int>> st, st2;

    auto hit = [&](int x, int y, int ind){
        ll dx = abs(x - cx[ind]);
        ll dy = abs(y - cy[ind]);
        ll r2 = cy[ind] * 1ll * cy[ind];
        ll d = dx * dx + dy * dy;
        return d < r2;
    };

    auto shoot = [&](int x, int y){
        auto it = st.lower_bound({x, 0});
        while(it != st.end()){
            auto [r, i] = *it;
            int l = cx[i] - cy[i];
            if(x < l){
                break;
            }
            if(hit(x, y, i)){
                st.erase(it);
                st2.erase({l, i});
                return id[i];
            }
            ++it;
        }

        auto it2 = st2.upper_bound({x, 0});
        if(it2 != st2.begin()){
            --it2;
        }
        while(it2 != st2.begin()){
            auto [l, i] = *it;
            int r = cx[i] + cy[i];
            if(r < x){
                break;
            }
            if(hit(x, y, i)){
                st.erase({r, i});
                st2.erase(it2);
                return id[i];
            }
            --it2;
        }


        return -1;
    };

    for(int i = 0; i < n; ++i){
        int type, x, y;
        cin >> type >> x >> y;

        if(type == 1){
            st.insert({x + y, id.size()});
            st2.insert({x - y, id.size()});
            cx.push_back(x);
            cy.push_back(y);
            id.push_back(i + 1);
        }
        else{
            cout << shoot(x, y) << '\n';
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    solve();
    
    return 0;
}
 
