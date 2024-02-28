#include <bits/stdc++.h>
using namespace std;

class Secant
{
public:
    double f(double x)
    {
        return -12 - 21 * x + 18 * x * x - 2.4 * x * x * x;
      //  return x * x * x + x * x - 1;
    }

    void Scent(double x, double x1, int it)
    {
        double next = x;
        for (int i = 0; i < it; i++)
        {
            if (f(x) == 0)
            {
                break;
            }
            next = x1 - ((f(x1) * (x - x1)) / (f(x) - f(x1)));
            x = x1;
            x1 = next;
        }
        printf("root = %0.4lf\n", x1);
        // cout << x1 << endl;
    }
};

int main()
{
    Secant *sc = new Secant();
    sc->Scent(1.0, 1.3, 3);
}