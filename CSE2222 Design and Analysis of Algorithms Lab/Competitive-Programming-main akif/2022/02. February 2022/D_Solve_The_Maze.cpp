// Date: 2022-02-17 02:37:28

//  1. If B & G exists, then block all side of B, then check path for G
//  2. If only G exists, Check path from G to (n,m)
//  3. If only B exists, Block mouth of (n,m) (Done)

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

int dx[] = {+1, -1, +0, -0};
int dy[] = {+0, -0, +1, -1};

ll n, m;
char graph[51][51];
vector<pair<ll, ll>> goodPeople;
bool visited[51][51];
ll no_of_G_visited = 0;
bool isbadgoodcouple = false;

void init()
{
    memset(visited, false, sizeof(visited));
    no_of_G_visited = 0;
    goodPeople.clear();
    isbadgoodcouple = false;
}
bool isValid(int x, int y)
{
    if (x >= 0 && x < n && y >= 0 && y < m && (graph[x][y] != '#'))
        return true;
    return false;
}
void DFS(int i, int j)
{
    if (visited[i][j])
        return;
    visited[i][j] = true;

    if (graph[i][j] == 'G')
        no_of_G_visited++;

    for (int k = 0; k < 4; k++)
    {
        int x = i + dx[k];
        int y = j + dy[k];

        if (isValid(x, y))
        {
            DFS(x, y);
        }
    }
}

bool isAvailableforBlock(int x, int y)
{
    if (x >= 0 && x < n && y >= 0 && y < m && (graph[x][y] == '.' || graph[x][y] == '#' || graph[x][y] == 'G'))
        return true;
    return false;
}

void printGraph()
{
    cout << "----" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << graph[i][j];
        }
        cout << endl;
    }
    cout << "----" << endl;
}

// G beside a B.

void blockAllB()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (graph[i][j] == 'B')
            {
                for (int k = 0; k < 4; k++)
                {
                    ll x = i + dx[k];
                    ll y = j + dy[k];

                    if (isAvailableforBlock(x, y))
                    {
                        if (graph[i][j] == 'G')
                        {
                            isbadgoodcouple = true; // Danger
                        }
                        else
                            graph[x][y] = '#';
                    }
                }
            }
        }
    }
}
void solve()
{
    init();

    cin >> n >> m;

    bool hasB = false;
    bool hasG = false;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> graph[i][j];
            if (graph[i][j] == 'B')
                hasB = true;
            else if (graph[i][j] == 'G')
            {
                hasG = true;
                goodPeople.push_back({i, j});
            }
        }
    }

    bool isPossible = true;
    // printGraph();
    blockAllB();
    // printGraph();
    if (isbadgoodcouple)
    {
        cout << "No" << endl;
        return;
    }

    if (graph[n - 1][m - 1] == '.')
        DFS(n - 1, m - 1);

    if (no_of_G_visited == goodPeople.size())
    {
        cout << "Yes" << endl;
    }
    else
        cout << "No" << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int test = 1;
    cin >> test;
    while (test--)
    {
        solve();
    }
    return 0;
}