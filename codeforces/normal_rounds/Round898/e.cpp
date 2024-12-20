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
 
bool check(int n, int k){
    ll fact = 1;
    for(int i = 1; i <= n; ++i){
        fact *= i;
        if(fact >= k){
            break;
        }
    }
    if(fact < k){
        return false;
    }
    if(!(k & 1)){   // k is even
        return true;
    }
    if(!(n & 1)){   // k odd and n even
        return false;
    }
    // k odd and n odd
    return true;
}
 
void solve() {
    int n, k;
    cin >> n >> k;
    if(!check(n, k)){
        cout << "NO\n";
        return;
    }

    vector<int> p(n);
    for(int i = 0; i < n; ++i){
        p[i] = i + 1;
    }

    auto dual = [&](vector<int> p){
        int n = p.size();
        for(int i = 0; i < n; ++i){
            p[i] = n + 1 - p[i];
        }
        return p;
    };
    auto rotate = [&](vector<int> &p){
        int n = p.size();
        for(int i = 1; i < n; ++i){
            swap(p[i - 1], p[i]);
        }
    };

    set<vector<int>> st;
    if(!(k & 1)){
        while(st.size() < k){
            st.insert(p);
            st.insert(dual(p));
            next_permutation(p.begin(), p.end());
        }
    }
    else if(k < n){
        if(k == 1){
            cout << "NO\n";
            return;
        }
        int m = 1;
        while(m < n){
            m *= k;
        }
        if(m != n){
            cout << "NO\n";
            return;
        }

        auto expand_p = [&](vector<int> p, vector<int> q){
            int n = p.size();
            vector<int> res;
            for(int elemq: q){
                for(int elem: p){
                    res.push_back(n * elemq + elem);
                }
            }
            return res;
        };

        vector<int> q(k);
        for(int i = 0; i < k; ++i){
            q[i] = i;
        }

        for(int i = 0; i < k; ++i){
            vector<int> p = {1};
            for(int i = 1; i < n; i *= k){
                p = expand_p(p, q);
            }
            st.insert(p);
            rotate(q);
        }
    }
    else{
        k -= n;
        if(n < 11){
            ll fact = 1;
            for(int i = 1; i <= n; ++i){
                fact *= i;
            }
            if(2 * n + k > fact){
                cout << "NO\n";
                return;
            }
        }

        for(int i = 0; i < n; ++i){
            st.insert(p);
            rotate(p);
        }
        next_permutation(p.begin(), p.end());

        if(n < 11){
            while(st.size() < n + k){
                if((st.find(p) == st.end()) && (st.find(dual(p)) == st.end())){
                    st.insert(p);
                    st.insert(dual(p));
                }
                next_permutation(p.begin(), p.end());
            }
        }
        else{
            while(st.size() < n + k){
                st.insert(p);
                st.insert(dual(p));
                next_permutation(p.begin(), p.end());
            }
        }
    }

    cout << "YES\n";
    for(vector<int> p: st){
        for(int elem: p){
            cout << elem << ' ';
        }
        cout << '\n';
    }
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
 
