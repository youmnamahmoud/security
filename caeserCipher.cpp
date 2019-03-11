#include <iostream>

using namespace std;

int main()
{
    string plaintext;
    long long key;

    cin>>key; //shift amount
    cin>>plaintext; //before encryption

    string ciphertext = ""; //result of decryption
    string arrayofletters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i=0; i<plaintext.length();i++){
        for(int j=0; j<arrayofletters.length(); j++){
           if (plaintext[i]==arrayofletters[j]){
                ciphertext += arrayofletters[(j+key)%26];
                continue;
           }
        }
    }


    cout<<ciphertext;



    return 0;
}
