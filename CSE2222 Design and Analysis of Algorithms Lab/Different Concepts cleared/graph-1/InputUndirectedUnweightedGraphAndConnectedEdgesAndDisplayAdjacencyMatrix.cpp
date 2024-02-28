//Input Undirected Unweighted Graph And Connected Edges And Display Adjacency Matrix

#include<iostream>
# define MAX 100

int adj[MAX][MAX];

using namespace std;


int main(){
    freopen("input.txt","r",stdin);

    int nodesNo, edgesNo;

    int n1,n2,i,j;

   // cout<<"Enter no of nodes: ";
    cin>>nodesNo;

   // cout<<"Enter no of edges: ";
    cin>>edgesNo;

    for(i=0;i<edgesNo;i++){
        cin>>n1>>n2;

        adj[n1][n2]=1;
        adj[n2][n1]=1;
    }

    for(i=0;i<nodesNo;i++){
        for(j=0;j<nodesNo;j++){
            cout<<adj[i][j] <<"  ";
        }
        cout<<endl;
    }


    return 0;
}

