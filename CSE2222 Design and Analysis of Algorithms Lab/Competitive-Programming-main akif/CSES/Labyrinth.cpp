//Akif Islam (__SHERLOCK__)
//Date: 2021-06-03 13:24:20

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

// int dx[] = {-1, 1, 0, 0};
// int dy[] = {0, 0, -1, 1};

int dx[] = {+1, -1, +0, -0};
int dy[] = {+0, -0, +1, -1};

char graph[1005][1005];
bool visited[1005][1005];
int dist[1005][1005];
int m, n;
int src_x, src_y;
string shortest_Path;

void finding_shortest_path(int x, int y)
{
  if (x == src_x && y == src_y)
    return;

  for (int i = 0; i < 4; i++)
  {
    int new_x = x + dx[i];
    int new_y = y + dy[i];

    if (dist[new_x][new_y] == dist[x][y] - 1)
    {
      char move;
      // cout << "Here" << endl;
      if (dx[i] == 0 && dy[i] == 1)
        move = 'L';
      if (dx[i] == 0 && dy[i] == -1)
        move = 'R';
      if (dx[i] == -1 && dy[i] == 0)
        move = 'D';
      if (dx[i] == 1 && dy[i] == 0)
        move = 'U';
      shortest_Path.pb(move);
      finding_shortest_path(new_x, new_y);
      break;
    }
  }
}

bool isValid(int i, int j)
{
  if ((i > 0 && i <= m) && (j > 0 && j <= n) && (!visited[i][j] && graph[i][j] != '#'))
    return true;

  return false;
}

void BFS(int src_x, int src_y)
{

  queue<pair<int, int>> Q;

  visited[src_x][src_y] = true;
  Q.push({src_x, src_y});
  dist[src_x][src_y] = 0;

  while (!Q.empty())
  {

    int cur_x = Q.front().first;
    int cur_y = Q.front().second;
    Q.pop();

    for (int i = 0; i < 4; i++)
    {
      if (isValid(cur_x + dx[i], cur_y + dy[i]))
      {
        Q.push({cur_x + dx[i], cur_y + dy[i]});
        visited[cur_x + dx[i]][cur_y + dy[i]] = true;
        dist[cur_x + dx[i]][cur_y + dy[i]] = dist[cur_x][cur_y] + 1;
      }
    }
  }
}

void solve()
{
  memset(dist, -1, sizeof(dist));
  cin >> m >> n;

  int des_x, des_y;

  for (int i = 1; i <= m; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      cin >> graph[i][j];
      if (graph[i][j] == 'A')
      {
        src_x = i;
        src_y = j;
      }
      else if (graph[i][j] == 'B')
      {
        des_x = i;
        des_y = j;
      }
    }
  }

  BFS(src_x, src_y);

  if (dist[des_x][des_y] == -1)
  {
    cout << "NO" << endl;
    return;
  }
  cout<<"YES"<<endl;

  // for (int i = 1; i <= m; i++)
  // {
  //   for (int j = 1; j <= n; j++)
  //   {
  //     cout << dist[i][j] << " ";
  //   }
  //   cout << endl;
  // }
  finding_shortest_path(des_x, des_y);

  reverse(All(shortest_Path));
  cout << shortest_Path.size() << endl;

  cout << shortest_Path << endl;
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