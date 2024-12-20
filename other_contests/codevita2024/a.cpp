#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    int balance;
    cin >> balance;
    int numTran;
    cin >> numTran;

    vector<int> commits;
    vector<int> transactions;
    int curTransaction = 0;

    vector<int> res;

    for(int tran = 0; tran < numTran; ++tran){
        string type;
        cin >> type;
        int num;
        if((type == "credit") || (type == "debit") || (type == "abort") || (type == "rollback")){
            cin >> num;
        }

        if(type == "read"){
            res.push_back(balance);
        }
        else if(type == "credit"){
            balance += num;
            transactions.push_back(num);
        }
        else if(type == "debit"){
            balance -= num;
            transactions.push_back(-num);
        }
        else if(type == "abort"){
            --num;
            if(num >= curTransaction){
                balance -= transactions[num];
                transactions[num] = 0;
            }
        }
        else if(type == "rollback"){
            --num;
            balance = commits[num];
            curTransaction = transactions.size();
        }
        else if(type == "commit"){
            commits.push_back(balance);
            curTransaction = transactions.size();
        }
    }

    for(int i = 0; i < (int)res.size() - 1; ++i){
        cout << res[i] << "\n\n";
    }
    cout << res.back() << '\n';
    
    return 0;
}
 
