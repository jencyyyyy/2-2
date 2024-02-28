#include<iostream>
#include<vector>
#include<map>
#include<queue>
using namespace std;

int main(){
    int totalTest, testCases;
    cin>>totalTest;//test cases
    for(int testCases = 0; testCases< totalTest; testCases++){
        int n, m , p, s, t, i, j, k;
        cin >>n;//number of cities
        vector<pair<int, int>>graph[n];
        map<string, int>city;

        string str;

        for(i = 0; i<n; i++){
            cin >> str;// name of city
            city.insert({str, i});
            cin>>m;  // number of neighbors of Name str
            for(j = 0; j<m; j++){
                int v, d;     // v= nr= index of a city connected to str
                cin>>v>>d;    //  d= cost of transportation
                v--;         // reduce index by 1
                graph[i].push_back({v, d});
            }}
        cin>>p; //no of paths to find
        while(p--){
            cin>>str; //start city
            s = city[str];
            cin>>str;  //end city
            t = city[str];
            int dist[n]; // for storing the distance
            fill(dist, dist+n, INT_MAX); // set value to all array space
            dist[s] = 0; //distance of traveling starting from source set to 0
            bool visited[n]; // set if the vertex is visited
            fill(visited, visited+n, 0);// fill with 0
            priority_queue<pair<int, int>> q; //store the distance and index of that vertex
            q.push({-dist[s], s});// distance, index

            while(!q.empty()){
                pair<int, int>p = q.top();
                int x = -p.first,y = p.second;//x= distance from that index, y = city index
                q.pop();
                visited[y] = 1;
                if(y == t) break;// destination
                for(j = 0;j<graph[y].size();j++){
                    int k = graph[y][j].first;

                    if(visited[k]) continue;

                    int cost = x+graph[y][j].second;

                    if(cost<dist[k]){
                        dist[k] = cost;
                        q.push({-cost, k});
                    }
                }
            }
            cout<<dist[t]<<endl;
        }}}
