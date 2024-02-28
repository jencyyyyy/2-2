#include<iostream>
#include<iomanip>

using namespace std;

void checker(int a);

int main(){

    int  test;

    cin>>test;

    for(int i=0;i<test;i++){
        int a;
        cin>>a;
        checker(a);
    }
    return 0;
}

void checker(int a){

        switch (a){
            case 1:
                cout<<"1"<<endl;
                break;
            case 2:
                cout<<"-1"<<endl;
                break;
            default:
                int odd = 1;

                int v;
                if (a%2!=0) {
                    v = ((a/ 2 )+ 1) * a + 1;
                }else{
                    v = (a*a)/2 + 1;
                }

                for (int i = 1; i <= a; i++) {
                    for (int j = 1; j <= a; j++) {


                        if ((j-1)%2!=0){
                            cout<<setw(2)<<v<<" ";
                            v++;
                        } else{
                            cout<<setw(2)<<odd<<" ";
                            odd++;
                        }
                    }
                    cout<<endl;
                }
                 break;

        }
    }



