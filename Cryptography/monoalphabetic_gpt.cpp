#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// Function to encrypt the plaintext using the provided key
string encrypt(const string& plaintext, const unordered_map<char, char>& key) {
    string ciphertext = "";
    for (char ch : plaintext) {
        if (isalpha(ch)) {
            char lower_ch = tolower(ch);
            ciphertext += key.at(lower_ch);
        } else {
            ciphertext += (ch);
        }
    }
    return ciphertext;
}

// Function to decrypt the ciphertext using the provided reverse key
string decrypt(const string& ciphertext, const unordered_map<char, char>& reverse_key) {
    string plaintext = "";
    for (char ch : ciphertext) {
        if (isalpha(ch)) {
            char lower_ch = tolower(ch);
            plaintext += reverse_key.at(lower_ch);
        } else {
            plaintext += ch;
        }
    }
    return plaintext;
}

int main() {
    // Define the substitution key
    unordered_map<char, char> key = {
        {'a', 'm'}, {'b', 'n'}, {'c', 'b'}, {'d', 'v'}, {'e', 'c'},
        {'f', 'x'}, {'g', 'z'}, {'h', 'a'}, {'i', 's'}, {'j', 'd'},
        {'k', 'f'}, {'l', 'g'}, {'m', 'h'}, {'n', 'j'}, {'o', 'k'},
        {'p', 'l'}, {'q', 'q'}, {'r', 'w'}, {'s', 'e'}, {'t', 'r'},
        {'u', 't'}, {'v', 'y'}, {'w', 'u'}, {'x', 'i'}, {'y', 'o'},
        {'z', 'p'}
    };

    // Create the reverse key for decryption
    unordered_map<char, char> reverse_key;
    for (const auto& pair : key) {
        reverse_key[pair.second] = pair.first;
    }

    // Input plaintext
    string plaintext;
    cout << "Enter the plaintext: ";
    getline(cin, plaintext);

    // Encrypt the plaintext
    string ciphertext = encrypt(plaintext, key);
    cout << "Encrypted Text: " << ciphertext << endl;

    // Decrypt the ciphertext
    string decrypted_text = decrypt(ciphertext, reverse_key);
    cout << "Decrypted Text: " << decrypted_text << endl;

    return 0;
}
