
// function to find parent of a disjoint set
int Find(int u){
    if (u==parent[u]) return u;
    return parent[u] = Find(parent[u]);
}

// Kruskal's algorithm wit
long long MinST(){
    // reset parent table [0-n]
    for (int i = 0; i <= n; i++)
        parent[i] = i;

    long long cost = 0;
    // forward iteration for minimum cost first
    for (int i = 0; i < G.size(); i++){
        int u = G[i].u;
        int v = G[i].v;
        int w = G[i].w;

        int p = Find(u);
        int q = Find(v);
        if (p!=q){
            cost += w;
            parent[q] = p;
        }
    }
    return cost;
}