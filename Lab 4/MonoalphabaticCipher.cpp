#include <iostream>
#include <string>
using namespace std;

string decrypt(string message, string key) {
    string decrypted = "";
    int keyIndex = 0;
    for (int i = 0; i < message.length(); i++) {
        char c = message[i];
        char k = key[keyIndex];
        int diff = c - k;
        if (diff < 0) {
            diff += 26;
        }
        decrypted += 'A' + diff % 26;
        keyIndex = (keyIndex + 1) % key.length();
    }
    return decrypted;
}

int main() {
    string message = "ZICVTWQNGKZEIIGASXSTSLVVWLA";
    string key = "DECEPTIVEWEAREDISCOVEREDSAV";
    string decrypted = decrypt(message, key);
    cout << "Decrypted message: " << decrypted << endl;
    return 0;
}