// Ceaser Cipher Algorithm
#include <iostream>
#include <limits>

using namespace std;
const string numeric = "abcdefghijklmnopqrstuvwxyz";

string encryption(string,int);
string decryption(string,int);

int main()
{   
    int choosen;
    int key = 3;
    string plain_text;
    string cipher_text;
while(1){
    cout<<endl<<endl<<"Choose the process to execute:"<<endl;
    cout<<"1. Encryption"<<endl;
    cout<<"2. Decryption"<<endl;
    cout<<"3. Exit."<<endl<<"=>";
    cin>>choosen;
    choosen==3 ? exit(0) : void();
    switch(choosen){
        case 1:
        cout<<endl<<"Enter the plain text to encrypt: "<<endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, plain_text);

        cout<<"Enter the key (1-24): ";
        cin>>key;
        if(key<1 || key >24){
        cout<<"Default key '3' is choosen."<<endl;
        key=3;
        }
        cipher_text=encryption(plain_text,key);
        cout<<endl<<"Encrypting completed."<<endl;
        cout<<"Plain Text: "<<plain_text<<endl;
        plain_text=decryption(cipher_text,key);
        cout<<"Key used: "<<key<<endl;
        cout<<"Encrypted Text: "<<cipher_text<<endl;
        cout<<"Decrypted Text: "<<plain_text<<endl;
        break;



        case 2:
        cout<<"Enter the cipher text to decrypt: "<<endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, cipher_text);
        cout<<"Enter the key (1-24): ";
        cin>>key;
        if(key<1 || key >24){
        cout<<"Default key '3' is choosen."<<endl;
        key=3;
        }
        plain_text=decryption(cipher_text,key);
        cout<<endl<<"Decrypting completed."<<endl;
        cout<<"Cipher Text: "<<cipher_text<<endl;
        cout<<"Key used: "<<key<<endl;
        cout<<"Decrypted Text: "<<plain_text<<endl;
        break;
    
        default:
        cout<<"Invalit number try again....."<<endl;
    
    }
}
    return 0;
}






string encryption(string plain_text, int key)
{
    int num;
    string cipher_text;
    for (int j = 0; j < plain_text.length(); j++)
    {
        for (int i = 0; i < numeric.length(); i++)
            if (tolower(plain_text[j]) == numeric[i])
                num = i;
/*        if (!isspace(plain_text[j]))
        {
            if (num + key >= 26)
                num -= 26;
            cipher_text += numeric[num + key];
            cipher_text+=numeric[(num+key)%26];
        }
        else
            cipher_text.insert(j,1,' ');
*/
            if(!isspace(plain_text[j]))
            cipher_text+=toupper(numeric[(num+key)%26]);
    }
    return cipher_text;
}
string decryption(string cipher_text, int key)
{
    int num;
    string plain_text;
    for (int j = 0; j < cipher_text.length(); j++)
    {
        for (int i = 0; i < numeric.length(); i++)
            if (tolower(cipher_text[j]) == numeric[i])
                num = i;
/*        if (!isspace(cipher_text[j]))
        {
            if (num - key < 0)
                num += 26;
            plain_text += numeric[num - key];
            plain_text+=numeric[((num-key)%26+26)%26];
            cout<<endl<<(num-key)%26;
        }
        else
            plain_text.insert(j,1,' ');
*/
        if (!isspace(cipher_text[j]))
            plain_text+=numeric[((num-key)%26+26)%26];
    }
    return plain_text;
}

