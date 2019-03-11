#include <iostream>

using namespace std;

long long extendedEclidean(long long M, long long B)
{
    long long Q,a1=1,a2=0,a3=M,b1=0,b2=1,b3=B,b1_new,b2_new,b3_new;
    while (b3!=1)
    {
        if (b3==0)
            return 0;
        else
        {
            Q=a3 / b3; //qoutient
            b1_new=a1-Q*b1;
            b2_new=a2-Q*b2;
            b3_new=a3-Q*b3;
            a1=b1;
            a2=b2;
            a3=b3;
            b1=b1_new;
            b2=b2_new; //inverse
            b3=b3_new;
        }
    }
    return b2;
}

int main()
{
    long long M,N;
    cin>>M>>N;

    long long additiveInverse=(0-N)%M;
    while (additiveInverse<0)
        additiveInverse+=M;

    long long multiplicativeInverse;

    multiplicativeInverse=extendedEclidean(M,N);

    while (multiplicativeInverse<0)
        multiplicativeInverse+=M;

    if (multiplicativeInverse==0)
        cout<<"IMPOSSIBLE";
    else
        cout<<additiveInverse<<" "<<multiplicativeInverse;
    return 0;
}
