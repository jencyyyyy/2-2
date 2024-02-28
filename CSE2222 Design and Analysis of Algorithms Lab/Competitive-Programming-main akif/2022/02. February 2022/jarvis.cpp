#include <bits/stdc++.h>
using namespace std;

struct Point
{
    int x, y;
};
//Checking Left or Right
int orientation(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);

    if (val == 0)
        return 0;
    else if (val > 0)
        return 1;
    else if(val< 0)
        return 2;
}

void JarvisMarch(Point points[], int n)
{
    if (n < 3)
        return;

    vector<Point> results;

    int l = 0;

    for (int i = 1; i < n; i++)
    {
        if (points[i].x < points[l].x)
            l = i;
    }

    int p = l, q;

    do
    {

        results.push_back(points[p]);

        q = (p + 1) % n;
        for (int i = 0; i < n; i++)
        {

            if (orientation(points[p], points[i], points[q]) == 2)
                q = i;
        }

        p = q;

    } while (p != l);

    //Print
    for (int i = 0; i < results.size(); i++)
        cout << "(" << results[i].x << ", " << results[i].y << ")\n";
}

int main()
{
    Point points[] = {{0, 3}, {2, 2}, {1, 1}, {2, 1}, {3, 0}, {0, 0}, {3, 3}, {0, 2}};
    int n = 8;
    JarvisMarch(points, n);
    return 0;
}