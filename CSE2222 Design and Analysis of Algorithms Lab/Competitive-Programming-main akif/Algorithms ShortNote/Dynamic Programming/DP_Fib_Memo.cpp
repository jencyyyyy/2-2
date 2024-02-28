#include <bits/stdc++.h>
using namespace std;

#define ll long long int

ll fibonacci[1000];

ll fib(ll N)
{
    if (N <= 2)
        return 1LL;

    if (fibonacci[N] == -1)
    {
        ll F = fib(N - 1) + fib(N - 2);
        fibonacci[N] = F;
        return F;
    }

    else
        return fibonacci[N];
}

int main()
{
    memset(fibonacci, -1, sizeof(fibonacci));
    ll N;
    cin >> N;
    cout << fib(N) << endl;
}

//fib(50) = 12586269025