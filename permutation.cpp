#include <iostream>
#include <sstream>
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

string hex_str_to_bin_str(string& hex)
{
    string binary;
    for(int i = 0; i < hex.length(); i++)
       binary += hex_char_to_bin(hex[i]);
    return binary;
}
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
    int s;
    cin>>s;
    int permutation[s];
    for (int i=0;i<s;i++)
        cin>>permutation[i];
    int n;
    cin>>n;
    string input;
    cin>>input;
    string output="",test;
    test=hex_str_to_bin_str(input);
    for(int i=0;i<s;i++){
        output += test[permutation[i]-1];
    }
    //cout<<output<<endl;

    string outputhexa="",inputbinary="";
    //for (int i=0;i<n/4;i++){
        for(int j=0;j<s;j+=4){
            inputbinary=output.substr(j,4);
            outputhexa+=bin_to_hex(inputbinary);
        }
    //}
    cout<<outputhexa;



    return 0;
}
