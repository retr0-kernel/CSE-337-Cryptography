/*Write a program take text file as an input and print word, character count and ascii value of
each characters as output.*/

#include <bits/stdc++.h>
using namespace std;
int main() {
    ifstream file;
    string filename;
    cout << "Enter the file name: ";
    cin >> filename;
    file.open(filename.c_str());
    if (!file) {
        cout << "Unable to open file";
    }
    char ch;
    int count = 0;
    int word = 0;
    int ascii = 0;
    while (file >> noskipws >> ch) {
        if (ch == ' ' || ch == '\n') {
            word++;
        }
        count++;
        ascii = ch;
        cout << ch << " " << ascii << endl;
    }
    cout << endl;
    cout << "Number of characters in file: " << count << endl;
    cout << endl;
    cout << "Number of words in file: " << word << endl;
    file.close();
    return 0;
}
