
#include<bits/stdc++.h>
using namespace std;

int main(){
    int k[2][2] = {{2,1},{3,4}};
    string plainText = "HELLO WORLD";
    plainText.erase(remove(plainText.begin(), plainText.end(), ' '), plainText.end());
    string cipherText = "";
    if(plainText.length()%2!=0)
        plainText += 'X';
    for(int i=0;i<plainText.length();i+=2){
        int x = plainText[i]-'A';
        int y = plainText[i+1]-'A';
        int a = k[0][0]*x + k[0][1]*y;
        int b = k[1][0]*x + k[1][1]*y;
        cipherText += (char)(a%26 + 'A');
        cipherText += (char)(b%26 + 'A');
    }
    cout<<"Cipher Text: "<<cipherText<<endl;
    string decryptedText = "";
    for(int i=0;i<cipherText.length();i+=2){
        int x = cipherText[i]-'A';
        int y = cipherText[i+1]-'A';
        int a = (k[1][1]*x - k[0][1]*y + 26)%26;
        int b = (-k[1][0]*x + k[0][0]*y + 26)%26;
        decryptedText += (char)(a%26 + 'A');
        decryptedText += (char)(b%26 + 'A');
    }
}
