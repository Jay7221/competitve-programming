#include <bits/stdc++.h>
using namespace std;


long long pow3(long long num)
{
    long long int ans = 1;
    long long int mult = 3;
    while(num)
    {
        if(num%2 == 1)
        {
            ans = ans * mult;
            num--;
        }
        else
        {
            num = num/2;
            mult = mult*mult;
        }
    }
    return ans;
}

int main()
{

    long long n;
    cin >> n;
    long long a;
    cin >> a;
    int num = 0;
    if (n == 1)
    {
        cout << 1;
    }
    else if (n % 2 == 0)
    {
        while (2 * pow3(num) <= n)
        {
            num++;
        }
        int gp = --num;
        long long alive =  (3 * ((n - 2 * pow3(gp)) / 2));
        long long ans = alive+a;
        if (ans <= n)
        {
            cout << ans;
        }
        else
        {
            cout << ans - n;
        }
    }
    else
    {
        while (3 * pow3(num) <= n)
        {
            num++;
        }
        int gp = --num;
        long long alive = 3 * ((n - 3 * pow3(gp)) / 2);
        long long ans = alive + a;
        if (ans <= n)
        {
            cout << ans;
        }
        else
        {
            cout << ans - n;
        }
    }
}

