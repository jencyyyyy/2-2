// Original Dijkstra Algorithm

void dijkstra(ll src)
{
    // Weight, Node
    priority_queue<pair<int, int>> Q;
    Q.push({0, src});

    // INT MAXing for Min Operation
    for (int i = 0; i < n; i++)
        dist[i] = INT_MAX;

    dist[src] = 0; //initializd

    while (!Q.empty())
    {
        auto x = Q.top();
        ll u = x.second; // Node Value
        ll p = -x.first; // Node's Weight
        Q.pop();

        if (p > dist[u])
            continue;
        for (int i = 0; i < graph[u].size(); i++)
        {
            ll v = graph[u][i];  // Node Value
            ll w = weight[u][i]; // Node Weight

            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[v] + w;
                Q.push({-dist[v], v});
            }
        }
    }
}