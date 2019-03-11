#include <iostream>

using namespace std;

long long gcd(long long A, long long B){
    if(B==0)
        return A;
    return gcd(B,A%B);
}

int main()
{
    long long A,B;
    cin>>A>>B;
    long long C=gcd(A,B);
    cout<<C;
    return 0;
}
