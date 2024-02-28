#include <bits/stdc++.h>
using namespace std;

#define ll long long int

map<ll, ll> DP;

ll fib(ll N)
{
    if (N <= 2)
        return 1LL;

    if (DP.find(N) == DP.end())
    {
        ll F = fib(N - 1) + fib(N - 2);
        DP[N] = F;
        return F;
    }

    else
        return DP[N];
}

int main()
{
    ll N;
    cin >> N;
    cout << fib(N) << endl;

    for (auto x : DP)
    {
        cout << x.first << "th Fibonacci is : " << x.second << endl;
    }
}

//fib(50) = 12586269025