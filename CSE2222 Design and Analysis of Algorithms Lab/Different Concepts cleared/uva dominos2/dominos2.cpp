#include<iostream>
#include<vector>

#define SIZE 1004

using namespace std;


vector<int> v[SIZE];
bool vis[SIZE];

void dfsVisit(int n){
    vis[n]= true;
    for(int i=0;i< v[n].size();i++){
        int x = v[n][i];
        if(vis[x]==false){
            dfsVisit(x);
        }
    }
 }


int main(){
 //   freopen("input.txt","r",stdin);
    int t;

    cin>>t;

    for(int tt=0;tt<t;tt++){

        int n,m,l,n1,n2,x;
        cin>>n>>m>>l;

        for(int i=0;i<n+1;i++){
            vis[i]=false;
            v[i].clear();
        }

        for(int i=0;i<m;i++){
            cin>>n1>>n2;
            v[n1].push_back(n2);
        }

        for(int i=0;i<l;i++){
            cin>>x;
            dfsVisit(x);
        }

        int cnt=0;
        for(int i=0;i<n+1;i++){
            if(vis[i]) ++cnt;
        }
        cout<<cnt<<endl;
    }
    return 0;
}
