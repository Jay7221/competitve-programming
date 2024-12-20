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
 
 
bool solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    queue<pair<int, int>> q;
    int cnt = 0;
    char prev = '#';
    int ind = -1;
    for(int i = 0; i < n; ++i){
        if(s[i] != prev){
            if(ind != -1){
                q.push({ind, cnt});
            }
            ind = i;
            cnt = 0;
            prev = s[i];
        }
        ++cnt;
    }
    q.push({ind, cnt});

    vector<int> operations;
    char cur = '0';
    bool prevOdd = false;
    while(!q.empty()){
        int ind, val;
        tie(ind, val) = q.front();
        q.pop();

        if(val & 1){
            if(prevOdd){
                if(s[ind] == cur){
                    operations.push_back(ind);
                    cur = s[ind - 1];
                }
                else{
                    operations.push_back(ind - 1);
                    cur = s[ind];
                }
                prevOdd = false;
            }
            else{
                prevOdd = true;
            }
        }
        else if(prevOdd){
            return false;
        }
    }

    if(prevOdd){
        return false;
    }

    cout << operations.size() << '\n';
    for(int ind: operations){
        cout << ind << ' ';
    }
    cout << '\n';

    return true;
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; ++t){
        if(!solve()){
            cout << -1 << '\n';
        }
    }
    
    return 0;
}
 
