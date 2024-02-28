#include<iostream>
#include<queue>

# define MAX 100
#define WHITE 1
#define GRAY 2
#define BLACK 3

int color[MAX];
int adj[MAX][MAX];
int parent[MAX];
int dis[MAX];

int nodesNo, edgesNo;

using namespace std;


void bfs(int startingNode){
     for(int i=0;i<nodesNo;i++){
       color[i]= WHITE;
       dis[i]= INT_MIN; //-2147483648
       parent[i]=-1;
    }
    dis[startingNode]=0;
    parent[startingNode]=-1;

    queue<int>q;
    q.push(startingNode);

    while(!q.empty()){
        int x;
        x= q.front();
        q.pop();
        color[x]= GRAY;
        cout<< x << " ";
        for(int i=0;i<nodesNo;i++){
            if(adj[x][i]==1){
                if(color[i]==WHITE){
                    //neighbor of x is i
                    dis[i]= dis[x]+1;
                    parent[i]=x;
                    q.push(i);

                }
            }
        }
        color[x]=BLACK;

    }
}


int main(){
    freopen("input.txt","r",stdin);

    int n1,n2;
    cin>>nodesNo>>edgesNo;

    for(int i=0;i<edgesNo;i++){
        cin>>n1>>n2;
        adj[n1][n2]=1;
        adj[n2][n1]=1;
    }

    bfs(0);
    cout<<endl<< "parent of "<<5 << ": "<< parent[5]<<endl;
    cout<< "Distance of "<< 5<< " from 0: "<< dis[5]<<endl;

    return 0;
}





