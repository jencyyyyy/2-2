#include <bits/stdc++.h>
using namespace std;

vector<int> graph[1000];
bool visited[1000];

void DFS(int x)
{
    if (visited[x])
        return;

    visited[x] = true;

    for (auto u : graph[x])
        DFS(u);
}

int main()
{
    graph[1].push_back(2);
    graph[2].push_back(3);
    graph[3].push_back(4);
    graph[4].push_back(5);
    graph[4].push_back(6);
    graph[4].push_back(7);
    graph[4].push_back(8);
    graph[4].push_back(9);
    graph[4].push_back(10);

    DFS(1);
}