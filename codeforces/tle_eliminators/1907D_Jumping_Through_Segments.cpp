#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long 

void solve() {
    int n;
    cin >> n;

    vector<ll> l(n), r(n);
    for(int i = 0; i < n; ++i){
        cin >> l[i] >> r[i];
    }

    auto check = [&](int k){
        // is it possible to maintain [l, r] in k
        ll min_x = 0, max_x = 0;
        for(int i = 0; i < n; ++i){
            min_x = max(0ll, min_x - k);
            max_x += k;
            if((max_x < l[i]) || (r[i] < min_x)){
                // none of the possible x lie in [l, r]
                return false;
            }
            min_x = max(min_x, l[i]);
            max_x = min(max_x, r[i]);
        }
        return true;
    };

    ll resL = 0, resR = 1e9 + 7;
    while(resL < resR){
        ll resMid = (resL + resR) / 2;
        if(check(resMid)){
            resR = resMid;
        }
        else{
            resL = resMid + 1;
        }
    }
    cout << resL << '\n';
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
 
