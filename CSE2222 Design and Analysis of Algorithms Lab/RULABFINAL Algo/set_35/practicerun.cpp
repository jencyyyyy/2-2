#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("mice.txt","r",stdin);

    int tt, tc;

    cin>>tt;//test cases

    for(int tc = 0; tc< tt; tc++){

        int n, e , t, m;

        cin >>n>>e>>t>>m;//n = number of cell/ node in graph
                        // e = value of exit cell
        e--;                //t = maximum time to travel
                        //m = connection lines
        vector<pair<int, int>>graph[n];


        for(int i = 0; i<m; i++){
                int a,b, time;// v= nr= index of a city connected to str (start with 1) but aitai 0 diye start koreche
                cin>>a>>b>>time;//  d= cost of transportation
                a--;
                b--;// amra to code a index 0 diye korachi, r input a 1 diye hocche tai input a index ta -- kore diyechi
                graph[a].push_back({b, time});
        }


        int dist[n]; // for storing the distance


        fill(dist, dist+n, INT_MAX); // set value to all array space

        dist[e] = 0; //distance of traveling starting from source set to 0

      //  bool visited[n]; // set if the vertex is visited

      //  fill(visited, visited+n, 0);// fill with 0
        int cnt=0;

        for(int i=0;i<n;i++){
            queue<pair<int, int>> q; //store the distance and index of that vertex

            q.push({-dist[i], i});// distance, index

          //  while(!q.empty()){

            pair<int, int> p = q.front();

            int x = -p.first,y = p.second;//x= distance from that index, y = node index

              //  visited[y] = true;

               // if(y == e) break;// destination

            for(int j = 0; j<graph[y].size();j++){

                    int k = graph[y][j].first;

                 //   if(visited[k]) continue;

                    int cost = x + graph[y][j].second;

                    if(cost>dist[k]){

                        dist[k] = cost;
                       // q.push({-cost, k});
                    }
                }
            }



            for(int i=0;i<n;i++){
                cout<< dist[i]<< " ";
                if(dist[i]<=t){
                    cnt++;
                }

            }
            }
            //cout<<cnt<<endl;

    return 0;
}





/*
            map<string,int>::iterator it;

            for( it = city.begin();it != city.end();it++){
                cout<< it->first << " " << it->second <<endl;

            }


*/
