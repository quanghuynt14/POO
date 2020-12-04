#include <iostream>
using namespace std;

/*
Algo 5:
On supprime les multiples des diviseurs premiers qu'on a rencontré.
*/

int main()
{
    int i,j, maximum, sommet, essai;
    int * dP = new int[maximum/3];
    int * m = new int[maximum/3];
    dP[0]=5;
    m[0]=25;
    sommet =1;
    int pasI=4;

    cin >> maximum;

    for(i=7;i<maximum;i+=pasI,pasI=6-pasI)
    {
        for(essai=dP[j=0];(i!=m[j])&&(essai*essai<i);essai=dP[++j])
        {
            if(i>m[j])
            {
                m[j]+=2*essai;
            }
        }
        if(i!=m[j])
        {
            cout << i << endl;
            dP[sommet++]=i;
            m[sommet++]=i*i;
        }

    }
    cout << "FIN. BORNE SUP : " << maximum << "." << endl;
    delete[] dP;
    delete[] m;
    return 0;
}
