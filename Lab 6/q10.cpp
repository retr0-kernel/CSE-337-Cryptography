#include<bits/stdc++.h>
using namespace std;

int main(){
    string key = "deceptive";
    string plainText = "wearediscoveredsaveyourself";
    string cipherText = "";
    for(int i=0;i<plainText.length();i++){
        int x = plainText[i]-'a';
        int y = key[i%key.length()]-'a';
        cipherText += (char)((x+y)%26 + 'a');
    }
    cout<<"Cipher Text: "<<cipherText<<endl;
    string decryptedText = "";
    for(int i=0;i<cipherText.length();i++){
        int x = cipherText[i]-'a';
        int y = key[i%key.length()]-'a';
        decryptedText += (char)((x-y+26)%26 + 'a');
    }
    cout<<"Decrypted Text: "<<decryptedText<<endl;
}
