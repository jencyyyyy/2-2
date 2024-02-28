//Find the adjacent nodes
#include<iostream>
# define MAX 100

int adj[MAX][MAX];

using namespace std;


int main(){
    freopen("input.txt","r",stdin);

    int nodesNo, edgesNo;

    int n1,n2,i,j;

    cin>>nodesNo;
    cin>>edgesNo;

    for(i=0;i<edgesNo;i++){
        cin>>n1>>n2;
        adj[n1][n2]=1;
        adj[n2][n1]=1;
    }

    for(i=0;i<=nodesNo;i++){
        if(adj[4][i]==1){
            cout<< i<< " ";
        }
    }




    return 0;
}

