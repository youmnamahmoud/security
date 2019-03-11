#include <iostream>
#include <string>

using namespace std;
char* hex_char_to_bin(char c)
{
    switch(toupper(c))
    {
        case '0': return "0000";
        case '1': return "0001";
        case '2': return "0010";
        case '3': return "0011";
        case '4': return "0100";
        case '5': return "0101";
        case '6': return "0110";
        case '7': return "0111";
        case '8': return "1000";
        case '9': return "1001";
        case 'A': return "1010";
        case 'B': return "1011";
        case 'C': return "1100";
        case 'D': return "1101";
        case 'E': return "1110";
        case 'F': return "1111";
    }
}
string hex_str_to_bin_str(string& hex)
{
    string binary;
    for(int i = 0; i < hex.length(); i++)
       binary += hex_char_to_bin(hex[i]);
    return binary;
}
string p1(string input){
    int pc1[56] = {57, 49, 41, 33, 25, 17, 9, 1, 58, 50, 42, 34, 26, 18, 10, 2, 59, 51, 43, 35, 27, 19, 11, 3, 60, 52, 44, 36, 63, 55, 47, 39, 31, 23, 15, 7, 62, 54, 46, 38, 30, 22, 14, 6, 61, 53, 45, 37, 29, 21, 13, 5, 28, 20, 12, 4 };
    string output="",test;
    test=hex_str_to_bin_str(input);
    for(int i=0;i<56;i++){
        output += test[pc1[i]-1];
    }
    return output;
}
string p2(string input){
    int pc2[48] ={14, 17, 11, 24, 1, 5, 3, 28, 15, 6, 21, 10, 23, 19, 12, 4, 26, 8, 16, 7, 27, 20, 13, 2, 41, 52, 31, 37, 47, 55, 30, 40, 51, 45, 33, 48, 44, 49, 39, 56, 34, 53, 46, 42, 50, 36, 29, 32 };
    string output="",test;
    for(int i=0;i<48;i++){
        output += input[pc2[i]-1];
    }
    return output;
}
string bin_to_hex(string bin){
        if(bin=="0000") return "0";
        if(bin=="0001") return "1";
        if(bin=="0010") return "2";
        if(bin=="0011") return "3";
        if(bin=="0100") return "4";
        if(bin=="0101") return "5";
        if(bin=="0110") return "6";
        if(bin=="0111") return "7";
        if(bin=="1000") return "8";
        if(bin=="1001") return "9";
        if(bin=="1010") return "A";
        if(bin=="1011") return "B";
        if(bin=="1100") return "C";
        if(bin=="1101") return "D";
        if(bin=="1110") return "E";
        if(bin=="1111") return "F";

}

int main()
{
    int rotations[16] = {1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 1 };
    string keyhexa,pc1;
    cin>>keyhexa;
    pc1=p1(keyhexa);
    /*string y="",h="";
    for(int i=0;i<56;i+=4){
            y+=bin_to_hex(pc1.substr(i,4));
        }
    cout<<"first permuation:::"<<y<<endl;*/
    string upper,lower,upperafter,lowerafter,keyround,keyroundhexa="";
        string pc2;
    upper=pc1.substr(0,56/2);
    lower=pc1.substr(28,56/2);
    upperafter=upper;
    lowerafter=lower;
    for(int j=0;j<16;j++){
            if(j!=0){
        upper=keyround.substr(0,56/2);
        lower=keyround.substr(28,56/2);
            }
        if(rotations[j]==0 || rotations[j]==1 || rotations[j]==8 || rotations[j]==15){
            for(int i=0;i<28;i++){
                if(i==27){
                    upperafter[i]=upper[0];
                    lowerafter[i]=lower[0];
                }
                else{
                upperafter[i]=upper[i+1];
                lowerafter[i]=lower[i+1];
                }
            }
        }
        else {
            for(int i=0;i<28;i++){
                if(i==27){
                    upperafter[i]=upper[1];
                    lowerafter[i]=lower[1];
                }
                else if(i==26){
                    upperafter[i]=upper[0];
                    lowerafter[i]=lower[0];
                }
                else{
                upperafter[i]=upper[i+2];
                lowerafter[i]=lower[i+2];
                }
            }
        }

        keyround=upperafter+lowerafter;
        /*for(int i=0;i<56;i+=4){
            h+=bin_to_hex(keyround.substr(i,4));
        }
        cout<<"before second permutation:::"<<h<<endl;
        h="";*/
        pc2=p2(keyround);

        for(int i=0;i<48;i+=4){
            keyroundhexa+=bin_to_hex(pc2.substr(i,4));
        }
        cout<<keyroundhexa<<endl;
        keyroundhexa="";
}

    return 0;
}
