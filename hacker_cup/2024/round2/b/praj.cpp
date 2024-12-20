/*
Author: Prajwal Shah
Language: C++
Final Year BTech IT
Walchand College of Engineering, Sangli
*/

//_________________________________________________________//
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define pajju             main
#define Prajwal           ios_base::sync_with_stdio(false);
#define Shah              cin.tie(NULL);
#define ll                long long
#define pb                push_back
#define mp                make_pair
#define mid(l, h)         (l + (h-l)/2)
#define fab(i, a, b)     for (auto i = a; i < b; ++i)
#define frab(i, a, b)    for (auto i = a; i >= b; --i)
#define mod               1000000007
#define ff                first
#define ss                second
#define pinf              1e16
#define ninf              -1e16
//_______________________________________________________//

using namespace std;
using namespace __gnu_pbds;
template<class T> using ordered_set =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;

/*----------------- Debugging Starts -------------------------------------------------*/

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

/*----------------- Debugging Ends -------------------------------------------------*/
/*----------------- Solution Starts Here -------------------------------------------------*/
static void run_with_stack_size(void (*func)(void), size_t stsize) {
    char *stack, *send;
    stack = (char *)malloc(stsize);
    send = stack + stsize - 16;
    send = (char *)((uintptr_t)send / 16 * 16);
    asm volatile(
        "mov %%rsp, (%0)\n"
        "mov %0, %%rsp\n"
        :
        : "r"(send));
    func();
    asm volatile("mov (%0), %%rsp\n" : : "r"(send));
    free(stack);
}

void solve(ll Case){
    int n = 6, m = 7;
    vector<string>v(n);
    for(string &s : v) cin >> s;
    reverse(v.begin(),v.end());
    set<string>st;
    bool cIsPossible = false, fIsPossible = false;
    auto check = [&](int i, int j){
        int ii = i, jj = j;
        int cnt = 0;
        while(cnt < 4 and jj >= 0){ // left
            if(v[ii][jj] != v[i][j]) break;
            cnt++;
            jj--;
        }
        if(cnt == 4){ 
            string s = "";
            for(int jj = j - 3; jj <= j; ++jj){
                s += to_string(jj);
            }
            if(st.find(s) == st.end()){
                st.insert(s);
                if(v[i][j] == 'C') cIsPossible = true;
                if(v[i][j] == 'F') fIsPossible = true;
            }
        }
        ii = i, jj = j;
        cnt = 0;
        while(cnt < 4 and jj < m){ // right
            if(v[ii][jj] != v[i][j]) break;
            cnt++;
            jj++;
        }
        if(cnt == 4){
            string s = "";
            for(int jj = j; jj <= j + 3; ++jj){
                s += to_string(jj);
            }
            if(st.find(s) == st.end()){
                st.insert(s);
                if(v[i][j] == 'C') cIsPossible = true;
                if(v[i][j] == 'F') fIsPossible = true;
            }
        }
        ii = i, jj = j;
        cnt = 0;
        while(cnt < 4 and ii < n){ // up 
            if(v[ii][jj] != v[i][j]) break;
            cnt++;
            ii++;
        }
        if(cnt == 4){
            string s = "";
            s += to_string(j);
            if(st.find(s) == st.end()){
                st.insert(s);
                if(v[i][j] == 'C') cIsPossible = true;
                if(v[i][j] == 'F') fIsPossible = true;
            }
        }
        ii = i, jj = j;
        cnt = 0;
        while(cnt < 4 and ii < n and jj < m){ // 
            if(v[ii][jj] != v[i][j]) break;
            cnt++;
            ii++;
            jj++;
        }
        if(cnt == 4){
            string s = "";
            for(int jj = j; jj <= j + 3; ++jj){
                s += to_string(jj);
            }
            if(st.find(s) == st.end()){
                st.insert(s);
                if(v[i][j] == 'C') cIsPossible = true;
                if(v[i][j] == 'F') fIsPossible = true;
            }
        }
        ii = i, jj = j;
        cnt = 0;
        while(cnt < 4 and ii < n and jj >= 0){
            if(v[ii][jj] != v[i][j]) break;
            cnt++;
            ii++;
            jj--;
        }
        if(cnt == 4){
            string s = "";
            for(int jj = j - 3; jj <= j; ++jj){
                s += to_string(jj);
            }
            if(st.find(s) == st.end()){
                st.insert(s);
                if(v[i][j] == 'C') cIsPossible = true;
                if(v[i][j] == 'F') fIsPossible = true;
            }
        }

    };
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            check(i,j);
            // debug(vis);
        }
    }
    if(!cIsPossible and !fIsPossible){
        cout << "Case #" << Case << ": 0\n";
    }else if(cIsPossible and fIsPossible){
        cout << "Case #" << Case << ": ?\n";
    }else if(cIsPossible){
        cout << "Case #" << Case << ": C\n";
    }else{
        cout << "Case #" << Case << ": F\n";
    }
}
void _main(){
    ll t; cin >> t;
    ll Case = 1;
    while(t--){
        solve(Case++);
    }
}
int pajju()
{
    #ifndef ONLINE_JUDGE
    freopen("four_in_a_burrow_input.txt", "r", stdin);
    freopen("four_in_a_burrow_output.txt", "w", stdout);
    freopen("Error.txt", "w", stderr);
    #endif
    run_with_stack_size(_main,1024 * 1024 * 1024);
    return 0;
}

