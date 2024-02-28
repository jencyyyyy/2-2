#include <bits/stdc++.h>
using namespace std;

vector<int> graph[1000];
bool visited[1000];
int no_of_nodes,no_of_edges;

void DFS(int x)
{
    if (visited[x])
        return;
    cout << "Visting :" << x << endl;
    visited[x] = true;

    for (auto u : graph[x])
        DFS(u);
    cout << "Backtracking from :" << x << endl;
}

int main()
{
      cin >> no_of_nodes >> no_of_edges;

    for (int i = 0; i < no_of_edges; i++)
    {
        int from, to;
        cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    DFS(1);
}
