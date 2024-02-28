#include <bits/stdc++.h>
using namespace std;

vector<int> graph[1000];
bool visited[1000];

void BFS(int src)
{
    queue<int> Q;

    Q.push(src);
    visited[src] = true;

    while (!Q.empty())
    {
        int cur = Q.front();
        Q.pop();

        for (auto u : graph[cur])
        {
            if (!visited[u])
            {
                Q.push(u);
                visited[u] = true;
            }
        }
    }
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

    graph[1].push_back(11);
    graph[1].push_back(13);

    graph[2].push_back(12);
    graph[2].push_back(14);

    BFS(1);
}