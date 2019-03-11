#include <iostream>

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
    string binary="";
    for(int i = 0; i < hex.length(); i++)
       binary += hex_char_to_bin(hex[i]);
    return binary;
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

string addition(string first,string second){
    string result="00000000",res="",add="";
    for(int i=0;i<first.length();i++){
        if((first[i]=='0' && second[i]=='1') || (first[i]=='1' && second[i]=='0')) result[i]='1';
    }
    for(int i=0;i<result.length();i+=4){
        res=result.substr(i,4);
        add+=bin_to_hex(res);
    }
    return add;

}
string additionBinary(string first,string second){
    string result="00000000";
    for(int i=0;i<first.length();i++){
        if((first[i]=='0' && second[i]=='1') || (first[i]=='1' && second[i]=='0')) result[i]='1';
    }
    return result;
}

int main()
{
    string input1,input2,first,second,outputAdd;
    cin>>input1>>input2;
    first=hex_str_to_bin_str(input1);
    second=hex_str_to_bin_str(input2);
    outputAdd=addition(first,second);
    cout<<outputAdd<<" ";

    //----------------------------------------
    string zero,one,two,three,four,five,six,seven,m="00011011",outputMul="00000000";//powers of x
    zero=first; //cout<<"zero:"<<zero<<endl;

    one=zero+"0";
    if(one[0]=='1'){
        one=one.substr(1,8);
        one=additionBinary(one,m);
    }
    else one=one.substr(1,8); //cout<<"one:"<<one<<endl;

    two=one+"0";
    if(two[0]=='1'){
        two=two.substr(1,8);
        two=additionBinary(two,m);
    }
    else two=two.substr(1,8); //cout<<"two:"<<two<<endl;

    three=two+"0";
    if(three[0]=='1'){
        three=three.substr(1,8);
        three=additionBinary(three,m);
    }
    else three=three.substr(1,8); //cout<<"three:"<<three<<endl;

    four=three+"0";
    if(four[0]=='1'){
        four=four.substr(1,8);
        four=additionBinary(four,m);
    }
    else four=four.substr(1,8); //cout<<"four:"<<four<<endl;

    five=four+"0";
    if(five[0]=='1'){
        five=five.substr(1,8);
        five=additionBinary(five,m);
    }
    else five=five.substr(1,8); //cout<<"five:"<<five<<endl;

    six=five+"0";
    if(six[0]=='1'){
        six=six.substr(1,8);
        six=additionBinary(six,m);
    }
    else six=six.substr(1,8); //cout<<"six:"<<six<<endl;

    seven=six+"0";
    if(seven[0]=='1'){
        seven=seven.substr(1,8);
        seven=additionBinary(seven,m);
    }
    else seven=seven.substr(1,8); //cout<<"seven:"<<seven<<endl;

    if(second[0]=='1') outputMul=additionBinary(outputMul,seven); //cout<<outputMul<<endl;
    if(second[1]=='1') outputMul=additionBinary(outputMul,six);  //cout<<outputMul<<endl;
    if(second[2]=='1') outputMul=additionBinary(outputMul,five); //cout<<outputMul<<endl;
    if(second[3]=='1') outputMul=additionBinary(outputMul,four); //cout<<outputMul<<endl;
    if(second[4]=='1') outputMul=additionBinary(outputMul,three); //cout<<outputMul<<endl;
    if(second[5]=='1') outputMul=additionBinary(outputMul,two); //cout<<outputMul<<endl;
    if(second[6]=='1') outputMul=additionBinary(outputMul,one); //cout<<outputMul<<endl;
    if(second[7]=='1') outputMul=additionBinary(outputMul,zero); //cout<<outputMul<<endl;

    string multiplyResult="",res;
    for(int i=0;i<outputMul.length();i+=4){
        res=outputMul.substr(i,4);
        multiplyResult+=bin_to_hex(res);
    }
    cout<<multiplyResult;


    return 0;
}
