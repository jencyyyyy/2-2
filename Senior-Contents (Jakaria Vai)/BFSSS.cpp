#include<bits/stdc++.h>
#define sz 100005
using namespace std;
vector<int> adj[sz];
bool visit[sz];
int label[sz];

int bfs(int s,int num)
{
    queue<int> q;
    q.push(s);
    visit[s]=true ;
    label[s] = 1;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int a=0;a<adj[u].size();a++)
        {
            int b=adj[u][a];
            if(visit[b]==false)
            {
                q.push(b);
                visit[b]=true;
                label[b]=label[u]+1;
            }
        }
    }
}
int main()
{
    int a,b,s,num,n,v1,v2;
    cin>>n;
    for(a=1;a<n;a++)
    {
        cin>>v1>>v2;
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }
    cin>>num;

    cout<<bfs(1,num)<<endl;
    return 0;
}
