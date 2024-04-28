#include <iostream>
using namespace std;
int main()
{
    int n,i,a=0;
    cin>>n;
    int um,dois,tres;
    for (i = 1; i <=n; i++)
    {
        um=i+a;
        dois=i+a+1;
        tres=i+a+2;
        cout<<um<<" "<<dois<<" "<<tres<<" "<<"PUM"<<endl;
        a+=3;
    }
    return 0;
}