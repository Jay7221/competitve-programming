#include <bits/stdc++.h>
using namespace std;


int main() 
{
    int n;
    cin >> n;
    int arr[n];
    map<int,int> freq;
    int huhu = 0;
    for(int i = 0;i < n;i++)
    {
        cin >> arr[i];
        freq[arr[i]]++;
    }    
    for(auto it:freq)
    {
        if(it.second > 1)
        {
            huhu++;
        }
    }
    map<int,int> currfreq;
    int i = 0;
    int j = 0;
    int ans = n+1;
    int khekhe = 0;
    map<int,bool> huihui;
    while((i <= j) and (j < n))
    {
        currfreq[arr[j]]++;
        if((freq[arr[j]] > 1) and (huihui[arr[j]] == false) and ((freq[arr[j]]-1 == currfreq[arr[j]]) or (freq[arr[j]] == currfreq[arr[j]])))
        {
            huihui[arr[j]] = true;
            khekhe++;
        }
        while(currfreq[arr[i]] == freq[arr[i]])
        {
            currfreq[arr[i]]--;
            i++;
        }
        if(khekhe == huhu)
        {
            ans = min(ans,j-i+1);
            i++;   
            khekhe = 0;
        }
        j++;
    }
    cout << ans <<endl;
    return 0;
}
