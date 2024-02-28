#include <bits/stdc++.h>
#include <iostream>

using namespace std;

class GaussElimination
{
public:
    int mat[100][100],ans[100];
    GaussElimination()
    {
        cout << "Enter the number of rows and columns: ";
        int n, m;
        cin >> n >> m;
        cout << "Enter the matrix: ";
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                cin >> mat[i][j];
            }
        }
        GaussEliminationMethod(n, m);
        Print(n,m);
    }
    void GaussEliminationMethod(int n, int m)
    {
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int k = mat[j][i] / mat[i][i];
                for (int l = 0; l <= m; l++)
                {
                    mat[j][l] = mat[j][l] - k * mat[i][l];
                }
            }
        }
    }
    void Print(int n,int m){
        ans[n-1]=mat[n-1][m]/mat[n-1][m-1];
        for(int i=n-2;i>=0;i--){
            ans[i]=mat[i][m];
            for(int j=i+1;j<m;j++){
                ans[i]=ans[i]- mat[i][j]*ans[j];  
            }
            ans[i]=ans[i]/mat[i][i];
        }
        cout<<"The solution is: ";
        for(int i=0;i<n;i++){
            cout<<ans[i]<<" ";
        }
    }
};

// main
int main()
{
    GaussElimination g;
    return 0;
}
