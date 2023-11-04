#include <bits/stdc++.h>
using namespace std;

vector<uint8_t> KSA(const vector<uint8_t>& key) {
    vector<uint8_t> S(256);
    for (int i = 0; i < 256; i++) {
        S[i] = i;
    }

    int j = 0;
    for (int i = 0; i < 256; i++) {
        j = (j + S[i] + key[i % key.size]) % 256;
        swap(S[i], S[j]);
    }

    return S;
}

vector<uint8_t> PRGA(const vector<uint8_t>& S, int data_len) {
    vector<uint8_t> keystream(data_len);
    int i = 0;
    int j = 0;

    for (int k = 0; k < data_len; k++) {
        i = (i + 1) % 256;
        j = (j + S[i]) % 256;
        swap(S[i], S[j]);
        int t = (S[i] + S[j]) % 256;
        keystream[k] = S[t];
    }

    return keystream;
}

vector<uint8_t> RC4(const vector<uint8_t>& key, const vector<uint8_t>& data) {
    vector<uint8_t> S = KSA(key);
    vector<uint8_t> keystream = PRGA(S, data.size());

    vector<uint8_t> ciphertext(data.size());
    for (size_t i = 0; i < data.size(); i++) {
        ciphertext[i] = data[i] ^ keystream[i];
    }

    return ciphertext;
}

int main() {
    vector<uint8_t> key = {0x01, 0x02, 0x03, 0x04, 0x05}; // 40-bit key
    vector<uint8_t> data = {'H', 'e', 'l', 'l', 'o'};

    vector<uint8_t> ciphertext = RC4(key, data);

    cout << "Original Data: ";
    for (uint8_t byte : data) {
        cout << byte;
    }
    cout << endl;

    cout << "Ciphertext: ";
    for (uint8_t byte : ciphertext) {
        cout << byte;
    }
    cout << endl;

    vector<uint8_t> plaintext = RC4(key, ciphertext);

    cout << "Decrypted Data: ";
    for (uint8_t byte : plaintext) {
        cout << byte;
    }
    cout << endl;

    return 0;
}
