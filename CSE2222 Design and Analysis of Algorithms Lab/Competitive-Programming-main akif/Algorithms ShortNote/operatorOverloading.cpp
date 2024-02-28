#include <bits/stdc++.h>
using namespace std;

class Exam
{
public:
    Exam(double b = 0, double e = 0, double m = 0)
    {
        bangla = b;
        english = e;
        math = m;
    }

public:
    double bangla, english, math;

    Exam operator+(Exam ex)
    {
        Exam ex_new;
        ex_new.bangla = bangla + ex.bangla;
        ex_new.english = english + ex.english;
        ex_new.math = math + ex.math;
        return ex_new;
    }

    void printMarks()
    {
        cout << "Total in Bangla : " << bangla << endl;
        cout << "Total in English : " << english << endl;
        cout << "Total in Math : " << math << endl;
    }
};

int main()
{
    Exam class_test(10, 12, 15);
    Exam attendance(7.5, 5, 6);
    Exam final = class_test + attendance;
    final.printMarks();
}