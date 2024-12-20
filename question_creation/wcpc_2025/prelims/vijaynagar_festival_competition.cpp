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

int maxSum(std::vector<int>& A, std::vector<int>& B, int a, int b) {
    int N = A.size();
    
    std::vector<std::pair<int, int>> sortedA, sortedB;
    for (int i = 0; i < N; ++i) {
        sortedA.emplace_back(A[i], i);
        sortedB.emplace_back(B[i], i);
    }

    std::sort(sortedA.rbegin(), sortedA.rend());
    std::sort(sortedB.rbegin(), sortedB.rend());

    std::set<int> chosenIndices;
    int maxSumA = 0;
    int maxSumB = 0;

    for (int i = 0; i < a && i < N; ++i) {
        chosenIndices.insert(sortedA[i].second);
        maxSumA += sortedA[i].first;
    }

    int countB = 0;
    for (int i = 0; i < N && countB < b; ++i) {
        if (chosenIndices.find(sortedB[i].second) == chosenIndices.end()) {
            maxSumB += sortedB[i].first;
            chosenIndices.insert(sortedB[i].second);
            countB++;
        }
    }

    return maxSumA + maxSumB;
}
 
void solve() {
    int a, b, n;
    cin >> a >> b >> n;
    vector<int> A(n), B(n);
    for(int i = 0; i < n; ++i){
        cin >> A[i] >> B[i];
    }
    cout << maxSum(A, B, a, b) << '\n';
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    solve();
    
    return 0;
}
 
