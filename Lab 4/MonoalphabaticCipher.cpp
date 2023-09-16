#include <bits/stdc++.h>

using namespace std;
string encrypt(string plaintext, string key) {
    string ciphertext = plaintext;
    for (int i = 0; i < plaintext.length(); i++) {
        if (isalpha(plaintext[i])) {
            char base = isupper(plaintext[i]) ? 'A' : 'a';
            ciphertext[i] = key[plaintext[i] - base];
        }
    }
    return ciphertext;
}
string decrypt(string ciphertext, string key) {
    string plaintext = ciphertext;
    for (int i = 0; i < ciphertext.length(); i++) {
        if (isalpha(ciphertext[i])) {
            char base = isupper(ciphertext[i]) ? 'A' : 'a';
            size_t index = key.find(ciphertext[i]);
            plaintext[i] = 'A' + index;
            if (islower(ciphertext[i])) {
                plaintext[i] = tolower(plaintext[i]);
            }
        }
    }
    return plaintext;
}
int main() {
    string key = "QWERTYUIOPASDFGHJKLZXCVBNM";
    string plaintext, ciphertext, decryptedText;
    cout << "Enter a message to encrypt: ";
    cin >> plaintext;
    ciphertext = encrypt(plaintext, key);
    cout << "Encrypted message: " << ciphertext << endl;
    decryptedText = decrypt(ciphertext, key);
    cout << "Decrypted message: " << decryptedText << endl;
    return 0;
}