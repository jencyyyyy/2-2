#include <bits/stdc++.h>
using namespace std;

long long int fib(long long int N)
{
    if (N <= 2)
        return 1LL;
    return fib(N - 1) + fib(N - 2);
}

int main()
{
    long long int N;
    cin >> N;
    cout << fib(N) << endl;
}