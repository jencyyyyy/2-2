
#include <bits/stdc++.h>
using namespace std;

string gap = " ";
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v)
{
    os << '{';
    for (const auto &x : v)
        os << gap << x;
    return os << '}';
}

vector<int> arr;

void merge(int l, int m, int r)
{

    // Saving into Temporary Array
    cout << "Left : " << l << " Right : " << r << endl;

    int n1 = m - l + 1;
    int n2 = r - m;

    vector<int> L(n1);
    vector<int> M(n2);

    // Left Part
    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[l + i];
    }



    // Right Part
    for (int i = 0; i < n2; i++)
    {
        M[i] = arr[r + i + 1];
    }


    int i = 0, j = 0, k = l;

    while (i < n1 && j < n2)
    {
        if (L[i] <= M[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = M[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = M[j];
        j++;
        k++;
    }

    for (int i = l; i <= r; i++)
    {
        cout << arr[i] << "-";
    }
    cout << endl;
}

void mergeSort(int l, int r)
{
    cout << "Printing Sub-Array" << endl;
    for (int i = l; i <= r; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    if (l < r)
    {
        int mid = l + (r - l) / 2;

        mergeSort(l, mid);
        mergeSort(mid + 1, r);

        merge(l, mid, r);
    }
}

int main()
{

    arr.push_back(4);
    arr.push_back(0);
    arr.push_back(6);
    arr.push_back(1);
    arr.push_back(5);
    arr.push_back(2);
    arr.push_back(3);

    mergeSort(0, arr.size() - 1);
    cout << arr << endl;
}