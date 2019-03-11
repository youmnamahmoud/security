#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main()
{

    int inputp,outputp;
    cin>>inputp>>outputp;
    int pbox[outputp];
    int invpbox[inputp];
    for(int i=0;i<outputp;i++)
        cin>>pbox[i];



    for(int i=0;i<inputp;i++){
        for(int j=0;j<outputp;j++){
            if(pbox[j]==i+1){
                invpbox[i]=j+1;
                break;
            }
        }
    }
    bool reversable=1;
    set<int> p(pbox,pbox+outputp);
    if(p.size()!=inputp) reversable=0;
    if(reversable==1)
    for(int i=0;i<inputp;i++){
        cout<<invpbox[i]<<" ";
    }
    else{
        cout<<"IMPOSSIBLE";
    }




    return 0;
}
