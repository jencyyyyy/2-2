//DFS


void DFS(int x)
{
    if (visited[x])
        return;

    visited[x] = true;

    for (auto u : graph[x])
        DFS(u);
}
