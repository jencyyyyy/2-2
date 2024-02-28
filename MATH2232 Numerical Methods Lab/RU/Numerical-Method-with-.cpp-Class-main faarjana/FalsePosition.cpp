#include <bits/stdc++.h>
#define max_cnt 10000000
using namespace std;

class falsePosition
{
public:
    double f(double x)
    {
        return x * x * x - 2 * x - 5;
    }

    void falsepos(double a, double b)
    {

        double c;
        // double error = 0.0005;

        for (int i = 0; i < max_cnt; i++)
        {
            c = ((a * f(b)) - (b * f(a))) / (f(b) - f(a));

            if (f(c) == 0)
            {
                break;
            }
            else if ((f(a) * f(c)) < 0)
            {
                b = c;
            }
            else
            {
                a = c;
            }
        }

        cout << "root = " << c << endl;
    }
};

int main()
{
    falsePosition *fp = new falsePosition();
    fp->falsepos(-500, 500);
}