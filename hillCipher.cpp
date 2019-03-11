/*#include <iostream>
#include<math.h>

using namespace std;
long main()
{
    long long number;
    long long arr[number];
    string plalongext;
    string ciphertext;
    cin>>number;
    for(long i=0;i<number;i++)
    {
        cin>>arr[i];
    }
    cin>>plalongext;
    string test ="";
    for (long i=0; i<plalongext.length();i+=2){
        if((plalongext[i]==plalongext[i+1])&& plalongext[i] !='X'){
            test = plalongext.substr(0,i+1) + "X" + plalongext.substr(i+1,plalongext.length());
            plalongext = test;
        }
        if(plalongext[i]=='J')
            plalongext[i]='I';
        if((plalongext[i]==plalongext[i+1])&& plalongext[i]=='X'){
            test = plalongext.substr(0,i+1) + "Q" + plalongext.substr(i+1,plalongext.length());
            plalongext = test;
        }
    }
    if((plalongext.length()%2 !=0) && plalongext[plalongext.length()-1]=='X')
        plalongext = plalongext + "QX";
    if(plalongext.length()%2 !=0 && plalongext[plalongext.length()-1]!='X')
        plalongext = plalongext + 'X';


    long n = sqrt(number);
    long matrix[n][n], inputt[n][1],plalongextmatrix[n][n],ciphermatrix[n][n];
    long k=0;
    for(long i=0;i<n;i++){
        for(long j=0;j<n;j++){
            matrix[i][j]= arr[k];
            k++;
        }
    }

      for(long i=0;i<n;i++){
        for(long j=0;j<n;j++){
            plalongextmatrix[i][j]= plalongext[k];
            k++;
        }
    }
    for(long i = 0; i < n; i++)
        for(long j = 0; j < 1; j++)
            for(long k = 0; k < n; k++)
                ciphermatrix[i][j] = ciphermatrix[i][j] + plalongextmatrix[i][k] * matrix[k][j];

    for(long i = 0; i < 3; i++)
        cout<<(char)(fmod(ciphermarix[i][0], 26) + 97);


    return 0;
}
*/

#include <iostream>
#include<string>
#include <math.h>
using namespace std;
int main(){
	long long number;
	cin>>number;//------------key number
    string plaintext;
	long long n=sqrt(number);
	string ciphertext;
	string alphabet="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	long long matrix[n][n];//-------------key matrix
	for (long long i = 0; i < n; i++){
		for (long long j = 0; j < n; j++)
			cin>>matrix[i][j];
	}
    	cin>>plaintext;//------------plaintext
    long long **result = new long long*[n];
	long long **plainmatrix = new long long*[n];
	for(long i = 0; i < n; i++) {
		result[i] = new long long[1];
		plainmatrix[i] = new long long[1];
		}
    	int position;

    long length=plaintext.length();
    for (long i=0;i<plaintext.length();i++){
            if(length%n !=0 ){
                plaintext.push_back('X');
                length+=1;
            }
    }
    long long c=0;
    while(c!=plaintext.length()){
		 for (long long i = 0; i < n; i++){
			for (long long j = 0; j < 1; j++){
				result[i][j] = 0;
				for(long long h=0;h<alphabet.length();h++){
                    if(plaintext[c]==alphabet[h])
                        position=h;
				}
				plainmatrix[i][j]=position;
				c++;
			}
        }
    for(long long i = 0; i < n; i++)
        for(long long j = 0; j < 1; j++)
            for(long long k = 0; k < n; k++)
				result[i][j] += matrix[i][k] * plainmatrix[k][j];
    int index;
	for(long long i = 0; i <n; i++){
        index=(result[i][0])%26;
        ciphertext.push_back(alphabet[index]);
    }
}
		 cout<<ciphertext;

    return 0;
}
