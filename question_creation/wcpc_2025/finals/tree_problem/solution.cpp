#include <bits/stdc++.h>
 
using namespace std;

#define ll long long

const int MOD = 1e9 + 7;

ll power(ll n, int p){
    assert(p >= 0);
    ll res = 1;
    while(p){
        if(p & 1){
            res = (res * n) % MOD;
        }
        n = (n * n) % MOD;
        p >>= 1;
    }
    return res;
}
 
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }

    map<int, int> freq;
    for(int elem: a){
        ++freq[elem];
    }

    ll res = 1;
    vector<int> tree_sizes;
    for(auto [val, f]: freq){
        if(f > 1){
            res = (res * power(f, f - 2)) % MOD;
        }
        tree_sizes.push_back(f);
    }

    for(int i = 1; i < (int)tree_sizes.size(); ++i){
        res = ((res * ((tree_sizes[i - 1] * 1ll * tree_sizes[i]) % MOD)) % MOD);
    }

    cout << res << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    solve();
    
    return 0;
}
 
