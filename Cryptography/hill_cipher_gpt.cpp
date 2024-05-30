#include <iostream>
#include <vector>

using namespace std;

// Function to calculate the inverse of a matrix using Gauss-Jordan elimination
vector<vector<double>> inverseMatrix(vector<vector<double>> matrix) {
    int n = matrix.size();
    vector<vector<double>> inverse(n, vector<double>(n * 2, 0));

    // Augmenting the matrix with the identity matrix
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            inverse[i][j] = matrix[i][j];
        }
        inverse[i][i + n] = 1;
    }

    // Applying Gauss-Jordan elimination
    for (int i = 0; i < n; ++i) {
        // Make the diagonal element 1
        double divisor = inverse[i][i];
        for (int j = 0; j < 2 * n; ++j) {
            inverse[i][j] /= divisor;
        }

        // Make other elements in the column 0
        for (int j = 0; j < n; ++j) {
            if (j != i) {
                double multiplier = inverse[j][i];
                for (int k = 0; k < 2 * n; ++k) {
                    inverse[j][k] -= multiplier * inverse[i][k];
                }
            }
        }
    }

    // Extracting the inverse matrix
    vector<vector<double>> result(n, vector<double>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            result[i][j] = inverse[i][j + n];
        }
    }

    return result;
}

// Function to perform Hill cipher encryption
string hillEncrypt(string plaintext, vector<vector<double>> key) {
    int n = key.size();
    string ciphertext;

    // Padding the plaintext if its length is not a multiple of n
    int padding = n - (plaintext.length() % n);
    if (padding < n) {
        plaintext += string(padding, 'x');
    }

    // Encrypting blocks of plaintext
    for (int i = 0; i < plaintext.length(); i += n) {
        vector<double> block(n, 0);
        for (int j = 0; j < n; ++j) {
            block[j] = plaintext[i + j] - 'a'; // Assuming lowercase alphabets
        }

        // Matrix multiplication
        for (int j = 0; j < n; ++j) {
            double sum = 0;
            for (int k = 0; k < n; ++k) {
                sum += key[j][k] * block[k];
            }
            ciphertext += char(int(sum) % 26 + 'a'); // Assuming modulo 26 arithmetic
        }
    }

    return ciphertext;
}

// Function to perform Hill cipher decryption
string hillDecrypt(string ciphertext, vector<vector<double>> key) {
    vector<vector<double>> inverseKey = inverseMatrix(key);
    return hillEncrypt(ciphertext, inverseKey);
}

int main() {
    // Example key matrix (3x3)
    vector<vector<double>> key = {{6, 24, 1}, {13, 16, 10}, {20, 17, 15}};

    // Example plaintext
    string plaintext = "hello";

    // Encrypt the plaintext
    string ciphertext = hillEncrypt(plaintext, key);
    cout << "Ciphertext: " << ciphertext << endl;

    // Decrypt the ciphertext
    string decryptedText = hillDecrypt(ciphertext, key);
    cout << "Decrypted text: " << decryptedText << endl;

    return 0;
}
