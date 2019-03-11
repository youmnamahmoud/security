#include <iostream>
#include <map>

using namespace std;

int main()
{
    long long a,b,c,result=1,temp=0;
    map<long long,long long> powerValues;

    cin>>a>>b>>c;

    powerValues.insert({1,a});

    for (long long i=1;i<b;i*=2)
        powerValues.insert({i*2,(powerValues.at(i)*powerValues.at(i))%c});

    for (auto iter=powerValues.rbegin();iter!=powerValues.rend();++iter)
    {
        if (temp+iter->first <= b)
        {
            temp+=iter->first;
            result*=iter->second;
            result%=c;
        }
    }



    cout<<result;

    return 0;
}
