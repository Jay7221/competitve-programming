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
 
 
struct Node{
    Node* next[2];
};
struct Trie{
    Node* root;
    Trie(){
        root = new Node();
    }
    void insert(int num){
        Node* cur = root;
        for(int k = 30; k >= 0; --k){
            int bit = (1 & (num >> k));
            if(cur -> next[bit] == NULL){
                cur -> next[bit] = new Node();
            }
            cur = cur -> next[bit];
        }
    }
    int getMaxXor(int num){
        Node* cur = root;
        int ans = 0;
        for(int k = 30; k >= 0; --k){
            int bit = (1 & (num >> k));
            int req_bit = 1 - bit;
            if(cur -> next[req_bit] == NULL){
                req_bit = 1 - req_bit;
            }
            cur = cur -> next[req_bit];
            if(bit ^ req_bit){
                ans += (1 << k);
            }
        }
        return ans;
    }
};
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    Trie trie;
    for(int i = 1; i < n; ++i){
        cin >> a[i];
        a[i] ^= a[i - 1];
        trie.insert(a[i]);
    }
    for(int val = 0; val < n; ++val){
        if(trie.getMaxXor(val) < n){
            a[0] = val;
            for(int i = 1; i < n; ++i){
                a[i] ^= a[0];
            }
            break;
        }
    }
    for(int i = 0; i < n; ++i){
        cout << a[i] << ' ';
    }
    cout << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    solve();
    
    return 0;
}
 
