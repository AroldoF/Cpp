#include <iostream>
using namespace std;
int main()
{
    int n100=0,n50=0,n20=0,n10=0,n5=0,n2=0,m1=0,v;
    cout<<"Digite um valor!"<<endl;
    cin>>v;
    do
    {
        if (v>=100)
        {
            v-=100;
            n100++;
            continue;
        }
        else if (v>=50)
        {
            v-=50;
            n50++;
            continue;
        }
        else if (v>=20)
        {
            v-=20;
            n20++;
            continue;
        }
        else if (v>=10)
        {
            v-=10;
            n10++;
            continue;
        }
        else if (v>=5)
        {
            v-=5;
            n5++;
            continue;
        }
        else if (v>=2)
        {
            v-=2;
            n2++;
            continue;
        }
        else
        {
            v-=1;
            m1++;
            continue;
        }
    } while (v!=0);
    cout<<v<<endl;
    
}