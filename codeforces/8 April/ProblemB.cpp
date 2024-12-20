#include<bits/stdc++.h>
using namespace std;
#define ll long long 
void solve(){
	int n;
	cin >> n;
	map<int, int> freq;
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		freq[a]++;
	}
	int mx = 0;
	for(auto c : freq){
		mx = max(mx, c.second);
	}
	int ans = 0;
	while(mx < n){
		int d = min(mx, n - mx);
		ans += 1 + d;
		mx += d;
	}
	cout << ans << '\n';
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}