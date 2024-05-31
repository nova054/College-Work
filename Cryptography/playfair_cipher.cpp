#include <iostream>
#include <unordered_set>
using namespace std;

class Encryption
{
private:
    string *key = new string[5];

    string removeDuplicates(string input)
    {
        unordered_set<char> seen;
        string result;
        for (int ij = 0; ij < input.length(); ij++)
        {
            input[ij] = tolower(input[ij]) == 'i' ? 'j' : input[ij]; // Let i and j be same and denoted by j.
        }
        for (char chh : input)
        {
            char ch = tolower(chh);
            // Check if the character is already in the set
            if (seen.find(ch) == seen.end())
            {
                // If not, add it to the set and to the result string
                seen.insert(ch);
                result += ch;
            }
        }

        return result;
    }

    string *showkeys(string keys)
    {

        int k = 0;
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                key[i] += keys[k];
                k++;
            }
        }
        return key;
    }

    string plain_text(string plaintext)
    {
        string plain;
        for (char ch : plaintext)
        {
            ch = (ch == 'i') ? 'j' : ch;

            if (!isspace(ch))
                plain += tolower(ch);
        }
        plaintext = plain;
        // if(plaintext.length()%2!=0)     //Adding filler character
        // plaintext+='x';
        for (int i = 0; i < plaintext.length(); i += 2)
            if (i + 1 == plaintext.length() || plaintext[i] == plaintext[i + 1])
                plaintext.insert(i + 1, 1, 'x');

        return plaintext;
    }

    string *arraydiv(string plaintext)
    {
        int length = plaintext.length();
        string *array = new string[length / 2];
        int count = 0, j = 0;
        for (char ch : plaintext)
        {
            count++;
            array[j] += ch;
            if (count % 2 == 0)
                j++;
        }
        return array;
    }

    string cipher_text(string *plaintext, string *key, int lenght, bool encrypt)
    {
        // int l=0;
        string ciphertext;
        string indexing;
        int row, col;
        for (int l = 0; l < (lenght); l++)
        {
            for (int i = 0; i < 2; i++)
            {
                for (int j = 0; j < 5; j++)
                {
                    for (int k = 0; k < 5; k++)
                    {
                        if (plaintext[l][i] == key[j][k])
                        {
                            row = j;
                            col = k;
                        }
                    }
                }
                indexing += to_string(row);
                indexing += to_string(col);
            }
        }
        int index[indexing.length()];
        for (int c = 0; c < indexing.length(); c++)
        {
            index[c] = indexing[c] - '0';
        }
        int a = 0, b = 0, c = 0;
        for (a = 0; a < indexing.length(); a += 4)
        {
            if (index[a] == index[a + 2])
            { // in same row
                ciphertext += key[index[a]][(index[a + 1] + (encrypt ? 1 : 4)) % 5];

                ciphertext += key[index[a + 2]][(index[a + 2 + 1] + (encrypt ? 1 : 4)) % 5];
            }
            else if (index[a + 1] == index[a + 1 + 2])
            { // in same column
                ciphertext += key[(index[a] + (encrypt ? 1 : 4)) % 5][index[a + 1]];
                ciphertext += key[(index[a + 2] + (encrypt ? 1 : 4)) % 5][index[a + 2 + 1]];
            }
            else
            {
                ciphertext += key[index[a]][index[a + 2 + 1]];
                ciphertext += key[index[a + 2]][index[a + 1]];
            }
        }
        return ciphertext;
    }

public:
    string encrpyt(string plaintext, string keyword, bool encrypt)
    {

        for (char ch : keyword)
            if (!isalpha(ch))
            {
                cout << "Keyword should be alphabet........" << endl;
                exit(0);
            }

        for (char ch = 'a'; ch <= 'z'; ch++)
            keyword += ch;
        plaintext = plain_text(plaintext);
        string *pt = arraydiv(plaintext);

        string keys = removeDuplicates(keyword);
        string *k = showkeys(keys);
        if (encrypt)
        {
            cout << endl
                 << "The plain text is:" << endl
                 << "=>" << plaintext << endl;
            cout << endl
                 << "------------------------------" << endl
                 << "The key that is now used is: " << endl;

            for (int i = 0; i < 5; i++)
            {
                for (int j = 0; j < 5; j++)
                    cout << k[i][j] << " ";
                cout << endl;
            }
        }
        string ciphertext = cipher_text(pt, k, plaintext.length() / 2, encrypt);

        return ciphertext;
    }
};

int main()
{
    int length;
    Encryption En;
    string plaintext, keyword;
    cout << "Enter the keyword:" << endl
         << "=>";
    getline(cin, keyword);

    cout << endl
         << "Enter the plain_text to encrypt:" << endl
         << "=>";
    getline(cin, plaintext);

    string ciphertext = En.encrpyt(plaintext, keyword, true);

    cout << endl
         << "The cipher text is :" << endl
         << "=>"
         << ciphertext;

    cout << endl
         << "The plain text after decryption is :" << endl
         << "=>" << En.encrpyt(ciphertext, keyword, false);

    return 0;
}
