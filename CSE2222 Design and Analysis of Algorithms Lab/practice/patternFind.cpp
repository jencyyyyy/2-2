#include <iostream>

#include <cstdio>

#include <vector>

using namespace std;

long int kmphelper[100002];

vector<long int>v;

string str,pat;

long int len1,len2;

void printanswers()

{

    v.clear();

    long i=0,j=0;

    int flag=0;
    while(i<len1)
    {
        if(str[i]==pat[j])
        {

            i++;
            j++;
              if(j==len2)
        {
                  flag=1;
                  j=0;/*
                       long int r =i-len2+1;
                    cout<<"r: "<< r << ", i: "<<i <<endl;
                    */
                  i=i-len2+1;

                  //  cout<<"2nd i: "<<i <<endl;

                  v.push_back(i);
        }
        }
        else
        {
            if(j!=0)
            {
                j=kmphelper[j-1];
            }
            else
            {
                i++;
            }
        }
    }
    if(flag==1)
    {
        cout<<v.size()<<endl;
        for(long int i=0;i<v.size();i++)
        {
            cout<<v[i]<<" ";
        }
    }
    if(flag==0)
    {
        cout<<"Not Found";
    }
    cout<<endl;
}
/*
void makekmphelper(){
    long int i=0,j,k;

    cout<< "i: "<<i<<endl;
    j=0;
    i=1;
    kmphelper[0]=0;

}*/
int main()
{
    long int t,i,j,k,n,m;
    cin>>t;
    for(long int ii=0;ii<t;ii++)
    {
        cin>>str;
        cin>>pat;
        len1 = str.length();
        len2 = pat.length();

        for(i=0;i<len2;i++)
            kmphelper[i]=0;
        printanswers();
        cout<<endl;
    }

    return 0;
}
