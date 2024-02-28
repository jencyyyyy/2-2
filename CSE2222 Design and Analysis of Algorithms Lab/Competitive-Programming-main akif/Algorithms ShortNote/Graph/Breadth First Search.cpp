//Breadth First Search (BFS)
// Normal loop
vector<int> graph[100];
bool visited[100];

void BFS(int src)
{
    visited[src] = true;
    queue<int> Q;
    Q.push(src);

    while (!Q.empty())
    {
        int cur_node = Q.front();
        Q.pop();

        for (int i = 0; i< graph[cur_node].size() ; i++)
        {
            Q.push(graph[cur_node][i]);
            visited[graph[cur_node][i]];
        }
    }
}

