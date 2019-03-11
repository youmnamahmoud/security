#include <iostream>

using namespace std;

int main()
{
    int s;
    cin>>s;
    int per[s],inv[s];
    for(int i=0;i<s;i++)
        cin>>per[i];
    for(int i=0;i<s;i++){
        for(int j=0;j<s;j++){
            if(per[j]==i+1){
                inv[i]=j+1;
            }
        }
    }
    bool reversable=1;
    for (int i = 0; i <s-1; i++){
        for (int j = i + 1;j <s; j++){
            if (per[i] == per[j])
            reversable=0;
        }
    }
    if(reversable==1)
    for(int i=0;i<s;i++){
        cout<<inv[i]<<" ";
    }
    else{
        cout<<"IMPOSSIBLE";
    }


    return 0;
}
