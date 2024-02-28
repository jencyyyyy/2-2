#include<iostream>
#include<queue>
using namespace std;

int main()
{
    priority_queue<pair<int,string>>q;

    q.push({10,"a"});
    q.push({5,"b"});
    q.push({60,"c"});
    q.push({42,"d"});
    q.push({650,"e"});

    while(!q.empty()){
        int x;
        string str;

        x= q.top().first;
        str = q.top().second;

        cout<<x << " "<<str <<endl;

        q.pop();
    }

    return 0;
}
