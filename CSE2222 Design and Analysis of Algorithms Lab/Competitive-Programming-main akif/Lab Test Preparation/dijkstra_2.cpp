#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> graph[1000];
int dist[1000];
bool visited[1000];

#define INF 5000000;
int no_of_nodes, no_of_edges;

void Dijkstra(int src)
{

    for (int i = 0; i < 1000; i++)
        dist[i] = INF;
    dist[src] = 0;

    priority_queue<pair<int, int>> Q;

    Q.push({0, src});

    while (!Q.empty())
    {
        int cur_node = Q.top().second;
        Q.pop();

        if (visited[cur_node])
            continue;
        visited[cur_node] = true;

        for (auto x : graph[cur_node])
        {
            int u = x.first;  // node
            int w = x.second; // weight

            if (dist[u] > dist[cur_node] + w)
            {
                dist[u] = dist[cur_node] + w;
                Q.push({-dist[u], u});
            }
        }
    }
}

int main()
{
    cin >> no_of_nodes >> no_of_edges;

    for (int i = 0; i < no_of_edges; i++)
    {
        int from, to, weight;
        cin >> from >> to >> weight;

        graph[from].push_back({to, weight});
        graph[to].push_back({from, weight});
    }

    int callingfrom;
    cin >> callingfrom;

    Dijkstra(callingfrom);

    for (int i = 1; i <= no_of_nodes; i++)
    {
        cout << dist[i] << " ";
    }
    cout << endl;
}