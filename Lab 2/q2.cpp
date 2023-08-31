/*Raju send an encrypted message (cipher text) “PHHW PH DIWHU WKH WRJD SDUWB” to
Rani. Can you build decryption process and find out what is the message (plain text) send to
Rani?*/

#include<iostream>
#include<String>
using namespace std;
string Decrypt(string str, int shift){
    int i=0;
    while(str[i]!='\0'){
        if(str[i]==' ')
        {
            i++;
            continue;
        }
        if((int(str[i])-shift)<65){
            str[i]=char(int(str[i])-shift+26);
        }
        else{
            str[i]=char(int(str[i])-shift);
        }
        i++;
    }
    return str;
}
int main(){
    string str="PHHW PH DIWHU WKH WRJD SDUWB",cipher;
    cipher=Decrypt(str,3);
    cout<<"The decrypted text is: "+cipher;
    return 0;
}
