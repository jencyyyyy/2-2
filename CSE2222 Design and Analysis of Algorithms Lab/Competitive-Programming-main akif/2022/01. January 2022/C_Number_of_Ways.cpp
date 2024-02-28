// Date: 2022-01-22 19:47:14
// I dont know perfectly why this solution works.

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

#define int long long int
#define pb push_back
#define All(x) (x).begin(), (x).end()

void solve()
{
    int N;
    cin >> N;
    vector<int> vec(N);
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> vec[i];
        sum += vec[i];
    }

    if (sum % 3 != 0)
    {
        cout << 0 << endl;
        return;
    }

    sum = sum / 3;

    int tempSum = 0;
    int answer = 0;
    int cnt = 0;

    for (int i = 0; i < N - 1; i++)
    {
        tempSum += vec[i];

        if (tempSum == sum * 2)
        {
            answer += cnt;
        }

        if (tempSum == sum)
            cnt++;
    }
    cout << answer << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int test = 1;
    // cin >> test;
    while (test--)
    {
        solve();
    }
    return 0;
}