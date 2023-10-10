#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> createPlayfairMatrix(const string& key) {
    vector<vector<char>> matrix(5, vector<char>(5, ' '));
    string uniqueKey = "";    
    for (char c : key) {
        if (c != 'J' && find(uniqueKey.begin(), uniqueKey.end(), c) == uniqueKey.end()) {
            uniqueKey += c;
        }
        if (c == 'I' && find(uniqueKey.begin(), uniqueKey.end(), 'J') == uniqueKey.end()) {
            uniqueKey += 'I';
        }
    }
    int row = 0, col = 0;
    for (char c : uniqueKey) {
        matrix[row][col] = c;
        col++;
        if (col == 5) {
            col = 0;
            row++;
        }
    }
    
    char letter = 'A';
    for (row = 0; row < 5; row++) {
        for (col = 0; col < 5; col++) {
            if (matrix[row][col] == ' ') {
                while (uniqueKey.find(letter) != string::npos || letter == 'J') {
                    letter++;
                }
                matrix[row][col] = letter;
                letter++;
            }
        }
    }
    
    return matrix;
}

int main() {
    string key = "srmapuniversity";
    vector<vector<char>> playfairMatrix = createPlayfairMatrix(key);
    
    cout << "Playfair Key Matrix:" << endl;
    for (int row = 0; row < 5; row++) {
        for (int col = 0; col < 5; col++) {
            cout << playfairMatrix[row][col] << " ";
        }
        cout << endl;
    }
    
    return 0;
}