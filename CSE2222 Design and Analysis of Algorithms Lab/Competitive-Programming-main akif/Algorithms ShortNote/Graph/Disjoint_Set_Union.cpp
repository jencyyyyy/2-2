#include <bits/stdc++.h>
using namespace std;

vector<int> p;
vector<int> r;

void DSU(int N)
{

    r.resize(N, 0);
    p.resize(N);

    for (int i = 0; i < N; i++)
    {
        p[i] = i;
    }
}
int findSet(int s)
{
    if (p[s] == s)
        return s;
    else
        return findSet(p[s]);
}

bool isSameSet(int a, int b)
{
    return findSet(a) == findSet(b);
}

bool unionSet(int a, int b)
{
    if (!isSameSet(a, b))
    {
        int x = findSet(a);
        int y = findSet(b);

        if (r[x] > r[y])
        {
            p[y] = x;
        }
        else
        {
            p[x] = y;
            if (r[x] == r[y])
                r[y]++;
        }
        return true;
    }
    else
        return false;
}

int main() {
    
}