#include <iostream>
#include <sstream>

using namespace std;

string hexa(int x){
    stringstream ss;
    ss<< std::hex<<x;
    std::string res(ss.str());
    if(res.length()==1)
        res='0'+res;
    return res;
}

int main()
{

            string key,plaintext;
            cin>>key;
            cin>>plaintext;
            string ciphervigenere, ciphervernam;
            string *out=new string[plaintext.length()];
            long long j=0;
            for (long long i = 0; i < plaintext.length(); i++){
                ciphervigenere += (plaintext[i]+key[j]-2*'A')%26+'A';
                j=(j+1)%key.length();
            }
            cout<<"Vigenere: "<<ciphervigenere<<endl;

            long long k=0;
            for(long long i=0;i<plaintext.length();i++){
                out[i] =hexa(int(plaintext[i])^int(key[k]));
                ciphervernam+=out[i];
                k++;
                if(k>=key.length())
                    k=0;
            }
            for (long long i=0;i<ciphervernam.length();i++){
                ciphervernam[i]=toupper(ciphervernam[i]);
            }
            cout<<"Vernam: "<<ciphervernam<<endl;
            bool flag=1;
            /*for(long long i=0;i<plaintext.length();i++){
                if(hexa(int(ciphervernam[i])^int(key[k]))==hexa(int(plaintext[i])))
                   continue;
                else{
                    flag=0;
                    break;
                }
            }*/
            if(plaintext.length()==key.length())
                cout<<"One-Time Pad: YES";
            else
                cout<<"One-Time Pad: NO";

            /*if(flag==1)
                   cout<<"One-Time Pad: YES";
                else
                    cout<<"One-Time Pad: NO";
*/

    return 0;
}
