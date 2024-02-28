/*
      & bitwise and
      | bitwise or
      ^ bitwise xor
      ~ 1s complement
      << Shift Left
      >> Shift Right

  */

#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int a = 5;
    /* 
    Left Shift Operator <<
    a = 5 means 101 in binary
    Now left shift 1 space, a becomes 1010 in binary which is 10.
    Now left shift 2 space, a becomes 10100 which is 20.

    So left shifting is actually multiplying it with 2^x. where a<<x;
    */
    cout <<"Left shifting : "<< (a << 3) << endl;

    /* 
    Similarly,
    Right Shift Operator >>
    b = 34 means 100010 in binary
    Now right shift 1 space, b becomes 10001 in binary which is 17.
    Now right shift 2 space, b becomes 1000 which is 8.

    So left shifting is actually dividing it with 2^x. where b>>x;
    */

    int b = 34;
    cout <<"Right Shifting : "<< (b >> 1) << endl;
    

}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int test = 1;
    // cin>>test;
    while (test--)
    {
        solve();
    }
    return 0;
}