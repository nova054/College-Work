#include <iostream>
#include <string>
#include <cctype> // For toupper and tolower

using namespace std;

// Function to encrypt the plaintext using Caesar Cipher
string encryptCaesarCipher(string plaintext, int shift) {
    string ciphertext = "";

    for (char ch : plaintext) {
        if (isalpha(ch)) {
            // Determine the base ASCII value
            char base = islower(ch) ? 'a' : 'A';
            // Apply the shift
            ch = (ch - base + shift) % 26 + base;
        }
        ciphertext += ch; // Append the character to the ciphertext
    }

    return ciphertext;
}

// Function to decrypt the ciphertext using Caesar Cipher
string decryptCaesarCipher(string ciphertext, int shift) {
    return encryptCaesarCipher(ciphertext, 26 - shift); // Decrypting is just encrypting with (26 - shift)
}

int main() {
    string plaintext, ciphertext;
    int shift;

    cout << "Enter the plain text to encrypt: ";
    getline(cin, plaintext);

    cout << "Enter the key (1-25): ";
    cin >> shift;

    // Validate the shift value
    if (shift < 1 || shift > 25) {
        cout << "Invalid key! Default key '3' is chosen." << endl;
        shift = 3;
    }

    // Encrypt the plaintext
    ciphertext = encryptCaesarCipher(plaintext, shift);
    cout << "Encrypted Text: " << ciphertext << endl;

    // Decrypt the ciphertext
    string decryptedtext = decryptCaesarCipher(ciphertext, shift);
    cout << "Decrypted Text: " << decryptedtext << endl;

    return 0;
}
