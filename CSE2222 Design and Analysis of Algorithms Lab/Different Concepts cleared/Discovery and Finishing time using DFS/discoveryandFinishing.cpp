#include<iostream>
# define MAX 100
#define WHITE 1
#define GRAY 2
#define BLACK 3

int color[MAX];
int adj[MAX][MAX];

int Time=1;
int stime[MAX];
int fTime[MAX];
int nodesNo, edgesNo;

using namespace std;


void dfsVisit(int x){
    color[x]=GRAY;
    stime[x]=Time;
    ++Time;

    for(int i=0;i<nodesNo;++i){

        if(adj[x][i]==1){

            if(color[i]==WHITE){
                dfsVisit(i);
            }
        }
    }
    color[x]=BLACK;

    fTime[x]= Time;
    ++Time;
}

void dfs(){
    for(int i=0;i<nodesNo;i++){
       color[i]=WHITE;
    }


    for(int i=2;i<nodesNo;i++){
        if(color[i]== WHITE){
            dfsVisit(i);
        }
    }

}


int main(){
    freopen("input.txt","r",stdin);

    int n1,n2;
    cin>>nodesNo>>edgesNo;

    for(int i=0;i<edgesNo;i++){
        cin>>n1>>n2;
        adj[n1][n2]=1;
    }

    dfs();

    cout<<endl;

    for(int i=0;i<nodesNo;i++){
        cout<<"Node: "<< (char) ('A'+i) << " " << stime[i]<< " " << fTime[i] <<endl;
    }
    return 0;
}




