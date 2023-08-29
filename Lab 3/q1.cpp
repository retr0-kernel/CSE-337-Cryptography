#include <bits/stdc++.h>
using namespace std;

string decrypt(const string &cipher, int key_length, const std::string &key) {
    string decrypted;
    
    for (int i = 0; i < cipher.length(); ++i) {
        char cipher_char = cipher[i];
        char key_char = key[i % key_length];
        
        int decrypted_char = (cipher_char - key_char + 26) % 26 + 'A';
        decrypted.push_back(decrypted_char);
    }
    
    return decrypted;
}
int findKeyLength(const string &cipher) {
    int max_t = 10;
    double target_sum = 0.065;
    vector<int> char_freq(26, 0);
    for (int t = 1; t <= max_t; ++t) {
        char_freq.assign(26, 0);    
        for (int i = 0; i < cipher.length(); ++i) {
            if ((i - 1) % t != 0) {
                char_freq[cipher[i] - 'A']++;
            }
        }
        double sum_squares = 0.0;
        for (int freq : char_freq) {
            sum_squares += freq * freq;
        }
        if (std::abs(sum_squares / (cipher.length() - 1) - target_sum) < 0.01) {
            return t;
        }
    }
    return -1;
}
int main() {
    string cipher = "ULE PSO ENG LII WREBR RHLSMEWE XHH DFXTHJ GVOP LII PRKU SFIADI";
    int key_length = findKeyLength(cipher);
    if (key_length != -1) {
        cout << "Found key length: " << key_length << endl;
        string key = "KEY";
        string decrypted = decrypt(cipher, key_length, key);
        cout << "Decrypted text: " << decrypted <<endl;
    } else {
        cout << "Key length not found." << endl;
    }
    return 0;
}