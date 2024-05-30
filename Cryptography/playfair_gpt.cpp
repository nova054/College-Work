
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class PlayfairCipher {
private:
    char keySquare[5][5];
    string key;

    void generateKeySquare() {
        string alpha = "ABCDEFGHIKLMNOPQRSTUVWXYZ"; // I/J are combined
        string keyString = key + alpha;
        string filteredKey = "";

        // Remove duplicates
        for (char c : keyString) {
            if (filteredKey.find(c) == string::npos) {
                filteredKey += c;
            }
        }

        // Fill key square
        int k = 0;
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {
                keySquare[i][j] = filteredKey[k++];
            }
        }
    }

    void preprocessText(string& text) {
        // Remove spaces and convert to uppercase
        text.erase(remove_if(text.begin(), text.end(), ::isspace), text.end());
        transform(text.begin(), text.end(), text.begin(), ::toupper);

        // Replace J with I
        replace(text.begin(), text.end(), 'J', 'I');

        // Insert 'X' between identical pairs and at the end if needed
        for (size_t i = 0; i < text.length(); i += 2) {
            if (i + 1 == text.length() || text[i] == text[i + 1]) {
                text.insert(i + 1, 1, 'X');
            }
        }
    }

    void findPosition(char c, int& row, int& col) {
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 5; ++j) {
                if (keySquare[i][j] == c) {
                    row = i;
                    col = j;
                    return;
                }
            }
        }
    }

    string processDigraphs(string text, bool encrypt) {
        string result = "";
        preprocessText(text);

        for (size_t i = 0; i < text.length(); i += 2) {
            int row1, col1, row2, col2;
            findPosition(text[i], row1, col1);
            findPosition(text[i + 1], row2, col2);

            if (row1 == row2) {
                result += keySquare[row1][(col1 + (encrypt ? 1 : 4)) % 5];
                result += keySquare[row2][(col2 + (encrypt ? 1 : 4)) % 5];
            } else if (col1 == col2) {
                result += keySquare[(row1 + (encrypt ? 1 : 4)) % 5][col1];
                result += keySquare[(row2 + (encrypt ? 1 : 4)) % 5][col2];
            } else {
                result += keySquare[row1][col2];
                result += keySquare[row2][col1];
            }
        }

        return result;
    }

public:
    PlayfairCipher(string k) : key(k) {
        generateKeySquare();
    }

    string encrypt(string plaintext) {
        return processDigraphs(plaintext, true);
    }

    string decrypt(string ciphertext) {
        return processDigraphs(ciphertext, false);
    }
};

int main() {
    string keyword;
    cout<<"Enter the keyword:"<<endl;
    getline(cin , keyword);
    transform(keyword.begin(), keyword.end(), keyword.begin(), ::toupper);
    PlayfairCipher cipher(keyword);
    
    string plaintext;
    cout << "Enter text to encrypt: ";
    getline(cin, plaintext);

    string encrypted = cipher.encrypt(plaintext);
    cout << "Encrypted Text: " << encrypted << endl;

    string decrypted = cipher.decrypt(encrypted);
    cout << "Decrypted Text: " << decrypted << endl;

    return 0;
}
