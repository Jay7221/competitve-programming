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
 
// left_half[size][digit]
vector<vector<vector<ll>>> left_half(9, vector<vector<ll>>(10)), right_half(9, vector<vector<ll>>(10));
vector<ll> mountains;

void pre(){
    vector<ll> increasing_numbers;
    for(ll d = 1; d <= 8; ++d){
        increasing_numbers.push_back(d);
    }

    ll i = 0;
    for(ll dcount = 2; dcount <= 8; ++dcount){
        ll sz = increasing_numbers.size();
        while(i < sz){
            ll num = increasing_numbers[i];
            ++i;

            for(ll d = (num % 10); d <= 8; ++d){
                increasing_numbers.push_back(10 * num + d);
            }
        }
    }

    increasing_numbers.push_back(0);

    for(ll num: increasing_numbers){
        ll mult = 1;
        ll sz = 0;
        assert(sz <= 8);
        while(mult <= num){
            mult *= 10;
            ++sz;
        }
        for(ll d = (num % 10) + 1; d <= 9; ++d){
            left_half[sz][d].push_back((10 * num + d) * mult);
        }
    }

    right_half[0][0].push_back(0);
    for(ll d = 1; d <= 8; ++d){
        right_half[1][d].push_back(d);

        for(ll sz = 2; sz <= 8; ++sz){
            for(ll elem: right_half[sz - 1][d]){
                for(ll nd = (elem % 10); nd >= 1; --nd){
                    right_half[sz][d].push_back(10 * elem + nd);
                }
            }
        }
    }

    ll tot = 0;
    for(ll sz = 0; sz <= 8; ++sz){
        for(ll d = 1; d <= 9; ++d){
            for(ll d2 = d - 1; d2 >= 0; --d2){
                tot += left_half[sz][d].size() * right_half[sz][d2].size();
            }
        }

        for(auto vec: left_half){
            sort(vec.begin(), vec.end());
        }
        for(auto vec: right_half){
            sort(vec.begin(), vec.end());
        }
    }
}

vector<ll> arr1, arr2;

ll get(ll n, ll m){
    ll res = 0;

    for(ll sz = 0; sz <= 8; ++sz){
        map<ll, vector<ll>> right;
        for(ll d = 0; d <= 9; ++d){

            for(ll elem: left_half[sz][d]){
                if(elem > n){
                    break;
                }

                ll req = (m - (elem % m)) % m;
                res += upper_bound(right[req].begin(), right[req].end(), n - elem) - right[req].begin();
            }

            set<ll> st;
            for(ll elem: right_half[sz][d]){
                if(elem > n){
                    break;
                }
                right[elem % m].push_back(elem);
                st.insert(elem % m);
            }
            for(ll elem: st){
                sort(right[elem].begin(), right[elem].end());
            }

        }
    }

    return res;
}

bool check(ll n){
    vector<ll> digits;
    while(n > 0){
        digits.push_back(n % 10);
        n /= 10;
    }

    ll sz = digits.size();
    if(!(sz & 1)){
        return false;
    }
    if(*min_element(digits.begin(), digits.end()) == 0){
        return false;
    }

    for(ll i = 1; i < (sz / 2); ++i){
        if(digits[i - 1] > digits[i]){
            return false;
        }
    }
    reverse(digits.begin(), digits.end());
    for(ll i = 1; i < (sz / 2); ++i){
        if(digits[i - 1] > digits[i]){
            return false;
        }
    }
    ll mid = sz / 2;
    if(mid > 0){
        if((digits[mid - 1] >= digits[mid]) || (digits[mid + 1] >= digits[mid])){
            return false;
        }
    }
    return true;
}

ll brute(ll a, ll b, ll m){
    ll res = 0;
    for(ll i = a; i <= b; ++i){
        if((i % m == 0) && check(i)){
            ++res;
        }
    }
    return res;
}
 
void solve() {
    ll a, b;
    ll m;
    cin >> a >> b >> m;
    cout << get(b, m) - get(a - 1, m) << '\n';
    //cout << brute(a, b, m) << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    pre();

    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; ++t){
        cout << "Case #" << t << ": ";

        solve();
    }
    
    return 0;
}
 
