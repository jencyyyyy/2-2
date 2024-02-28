//Akif Islam (__SHERLOCK__)
//Date: 2021-06-08 13:00:58

#include <bits/stdc++.h>

using namespace std;

char gap = 32;
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v)
{
    os << '{';
    for (const auto &x : v)
        os << gap << x;
    return os << '}';
}

#define ll long long
#define pb push_back
#define All(x) (x).begin(), (x).end()

void solve()
{
    string str;
    cin >> str;

    map<char, int> M;

    for (int i = 0; i < str.length(); i++)
    {
        M[str[i]]++;
    }

    int even = 0, odd = 0;

    string halfPalindrome = "";
    string weird = "";

    for (auto x : M)
    {
        // cout << x.first << " " << x.second << endl;
        if (x.second % 2 == 0)
        {
            even++;
            int n = x.second / 2;
            while (n--)
            {
                halfPalindrome.pb(x.first);
            }
        }
        else
        {
            odd++;
            int n = (x.second - 1) / 2;
            while (n--)
            {
                halfPalindrome.pb(x.first);
            }
            weird = x.first;
        }
    }
    if (odd > 1)
        cout << "NO SOLUTION" << endl;
    else
    {
        string firstHalf = halfPalindrome;

        reverse(All(halfPalindrome));

        string secondHalf = halfPalindrome;

        cout << firstHalf + weird + secondHalf << endl;
    }
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