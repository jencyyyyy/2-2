
#include<iostream>
#include<windows.h>
#include<iomanip>
#include<math.h>


using namespace std;

void dataInput ();
void solution ();

int m, n;
int i, j, k;

char CONTINUE;
float constant [10] [10];
float temp;

 int main() {
    cout <<"Enter the number of equations to be solved: ";
    cin >>m;

    n = m + 1;

    cout <<setprecision (3);

    dataInput();

    cout <<endl;

    solution();
   return 0;
}


void dataInput () {

    cout <<"Enter the coefficients:" <<endl;
    cout <<endl;
    cout <<endl;

    for (i=0; i<m; i++) {
        for(j=0; j<n; j++) {
            cin >>constant [i][j];
        }
    }
}


 void solution () {

    stepOne:
    for (k=0; k<m; k++) {
        if ( constant [k] [k] != 1) {
            if( constant [k] [k] == 0) {
                for (j=0; j<n; j++) {
                    temp =constant [k][j];
                    constant [k][j]= constant [k+1][j];
                    constant [k+1][j] = temp;
                }
                cout <<"Exchange row" <<k+1 <<" and row" <<k+2 <<endl;
                goto stepTwo;
            }

            temp = constant [k][k];

            for(j=0; j<n; j++) constant [k][j] /= temp;

            cout <<" Row " <<k+1 <<" / (" <<temp <<")" <<endl;
            Sleep (2000);

            goto stepTwo;
        }
        for(i=0; i<m; i++) {
            if (i != k) {
                if( constant [i] [k] != 0 ) {
                    temp = constant [i] [k];
                    for(j=0; j<n; j++) constant[i][j] -= temp*constant[k][j];
                    cout <<" Row " <<i+1 <<" - (" <<temp <<") Row " <<k+1 <<endl;
                    Sleep (2000);
                    if (i == m-1) goto stepTwo;
                }
            }
        }
    }

    stepTwo:
    cout <<endl<<endl;

    for (i=0; i<m; i++) {
        for (j=0; j<n; j++) {
            if (constant [i] [j]== -0) constant [i] [j] = 0;
            cout <<"\t";
            if (j == n-1) cout <<"| ";
            cout <<constant [i] [j];
        }
        cout <<endl<<endl;
    }
    Sleep (2000);
    cout <<endl;
    if ( constant [m-1] [n-2] != 1 || constant [m-2] [n-2] != 0) goto stepOne;
}





