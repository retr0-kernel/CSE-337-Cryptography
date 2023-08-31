/*Write an encryption program such that we get the following input and output.
Input: computerscienceengineeringsrmuniversity 
Output: gsqtyxivwgmirgiirkmriivmrkwvqyrmzivwmxc*/
#include<iostream>
#include<String>
using namespace std;
string shift_cipher(string str, int shift){
    int i=0;
    while(str[i]!='\0'){
        if((int(str[i])+shift)>122){
            str[i]=char(int(str[i])+shift-26);
        }
        else{
            str[i]=char(int(str[i])+shift);
        }
        i++;
    }
    return str;
}
int main(){
    string str="computerscienceengineeringsrmuniversity",cipher;
    cipher=shift_cipher(str,4);
    cout<<"The encrypted text is: "+cipher;
    return 0;
}