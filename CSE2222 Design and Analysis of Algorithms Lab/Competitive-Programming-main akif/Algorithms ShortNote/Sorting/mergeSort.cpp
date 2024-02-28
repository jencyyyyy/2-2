#include <bits/stdc++.h>


using namespace std;

int numbers[1010], temp[1010];

void mergeSort(int lowerBound, int upperBound)
{
    if (lowerBound == upperBound)
        return;

    int mid = (lowerBound + upperBound) / 2;

    mergeSort(lowerBound, mid);
    mergeSort(mid + 1, upperBound);

    int i, j, k;

    for (i = lowerBound, j = mid + 1, k = lowerBound; k <= upperBound; k++)
    {
        if (i == mid + 1)
            temp[k] = numbers[j++];
        else if (j == upperBound + 1)
            temp[k] = numbers[i++];
            
        else if (numbers[i] < numbers[j])
            temp[k] = numbers[i++];
        else
            temp[k] = numbers[j++];
    }

    for (k = lowerBound; k <= upperBound; k++)
    {
        numbers[k] = temp[k];
    }
}

int main()
{
    int size;
    cin >> size;
    for (int k = 0; k < size; k++)
    {
        cin >> numbers[k];
    }
    mergeSort(0, size - 1);
    for (int k = 0; k < size; k++)
    {
        cout << numbers[k] << " ";
    }
}
