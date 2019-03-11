#include <iostream>
#include <sstream>
#include <string>
#include <stdlib.h>

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
        //res='0'+res;
    return res;
}

    string exp(string input){
    int expansion[48] = {32, 1, 2, 3, 4, 5, 4, 5, 6, 7, 8, 9, 8, 9, 10, 11, 12, 13, 12, 13, 14, 15, 16, 17, 16, 17, 18, 19, 20, 21,20, 21, 22, 23, 24, 25, 24, 25, 26, 27, 28, 29, 28, 29, 30, 31, 32, 1};
    string output="",test;
    test=hex_str_to_bin_str(input);
    for(int i=0;i<48;i++){
        output += test[expansion[i]-1];
    }
    return output;
    }
    string per(string input){
    int perm [32]= {16, 7, 20, 21, 29, 12, 28, 17, 1, 15, 23, 26, 5, 18, 31, 10, 2, 8, 24, 14, 32, 27, 3, 9, 19, 13, 30, 6, 22, 11, 4, 25 };
      string output="",test;
    //test=hex_str_to_bin_str(input);
    for(int i=0;i<32;i++){
        output += input[perm[i]-1];
    }
    return output;
    }

    int b(char x,char y){
    if(x=='0' && y=='0') return 0;
    else if(x=='0' && y=='1') return 1;
    else if(x=='1' && y=='0') return 2;
    else if(x=='1' && y=='1') return 3;
}
int bin_to_int(string bin){
        if(bin=="0000") return 0;
        if(bin=="0001") return 1;
        if(bin=="0010") return 2;
        if(bin=="0011") return 3;
        if(bin=="0100") return 4;
        if(bin=="0101") return 5;
        if(bin=="0110") return 6;
        if(bin=="0111") return 7;
        if(bin=="1000") return 8;
        if(bin=="1001") return 9;
        if(bin=="1010") return 10;
        if(bin=="1011") return 11;
        if(bin=="1100") return 12;
        if(bin=="1101") return 13;
        if(bin=="1110") return 14;
        if(bin=="1111") return 15;



}


    string s(string x){
      int s1[4][16] = {

{14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7},

{0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8},

{4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0},

{15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13},

};
    int s2[4][16]= {
{15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10},

{3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5},

{0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15},

{13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9},

};
    int s3[4][16]= {

{10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8},

{13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1},

{13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7},

{1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12},

};
    int s4[4][16] = {

{7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15},

{13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9},

{10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4},

{3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14},

};
    int s5[4][16] ={

{2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9},

{14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6},

{4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14},

{11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3},

};
    int s6[4][16]={

{12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11},

{10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8},

{9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6},

{4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13},

};
    int s7[4][16]={

{4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1},

{13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6},

{1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2},

{6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12},

};
    int s8[4][16]={

{13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7},

{1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2},

{7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8},

{2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11},

};
   string inputbin,outputhexa="";
   //inputbin = hex_str_to_bin_str(input);
   string s1bin,s2bin,s3bin,s4bin,s5bin,s6bin,s7bin,s8bin;
        s1bin=x.substr(0,6);
        s2bin=x.substr(6,6);
        s3bin=x.substr(12,6);
        s4bin=x.substr(18,6);
        s5bin=x.substr(24,6);
        s6bin=x.substr(30,6);
        s7bin=x.substr(36,6);
        s8bin=x.substr(42,6);
        int row1=b(s1bin[0],s1bin[5]);
        int row2=b(s2bin[0],s2bin[5]);
        int row3=b(s3bin[0],s3bin[5]);
        int row4=b(s4bin[0],s4bin[5]);
        int row5=b(s5bin[0],s5bin[5]);
        int row6=b(s6bin[0],s6bin[5]);
        int row7=b(s7bin[0],s7bin[5]);
        int row8=b(s8bin[0],s8bin[5]);
        int col1=bin_to_int(s1bin.substr(1,4));
        int col2=bin_to_int(s2bin.substr(1,4));
        int col3=bin_to_int(s3bin.substr(1,4));
        int col4=bin_to_int(s4bin.substr(1,4));
        int col5=bin_to_int(s5bin.substr(1,4));
        int col6=bin_to_int(s6bin.substr(1,4));
        int col7=bin_to_int(s7bin.substr(1,4));
        int col8=bin_to_int(s8bin.substr(1,4));
        outputhexa=hexa(s1[row1][col1])+hexa(s2[row2][col2])+hexa(s3[row3][col3])+hexa(s4[row4][col4])+hexa(s5[row5][col5])+hexa(s6[row6][col6])+hexa(s7[row7][col7])+hexa(s8[row8][col8]);
        outputhexa=hex_str_to_bin_str(outputhexa);
        return outputhexa;
    }




int main()
{
    string input,key,expout,keybin,keytest="";
    cin>>input;
    cin>>key;

    expout=exp(input);
    //cout<<expout<<endl;
    keybin=hex_str_to_bin_str(key);
    int l=keybin.length();
    while(l<48){
        keytest+="0";
        l++;
    }
    keybin=keytest+keybin;
    //cout<<keybin<<endl;
    string x="000000000000000000000000000000000000000000000000";
    for(int i=0;i<48;i++){
        if(expout[i]=='0' && keybin[i]=='0') x[i]='0';
        else if(expout[i]=='1' && keybin[i]=='1') x[i]='0';
        else if(expout[i]=='1' && keybin[i]=='0') x[i]='1';
        else if(expout[i]=='0' && keybin[i]=='1') x[i]='1';
    }
    //cout<<x<<endl;

    string sout;
    sout=s(x);
    //cout<<sout<<endl;

    string finaloutput;
    finaloutput=per(sout);
    //cout<<finaloutput<<endl;
    string final="";

    for(int i=0;i<32;i+=4){
        final+=bin_to_hex(finaloutput.substr(i,4));
    }
    //finaloutput=hex_str_to_bin_str(finaloutput);
    cout<<final;




    return 0;
}
