#include <iostream>

using namespace std;


string encryption(string plain, string key){
    if(key.length()<plain.length()){
        key+=key;
    }
    if(key.length()>plain.length()){
        while(key.length()!=plain.length())
        plain+='x';
    }
    string ciphertext="";
    int len=key.length();
    // int len =1;
    for(int i=0; i<len; i++){
        ciphertext+=plain[i] ^ key[i];
        // cout<<ciphertext;
    }
    return ciphertext;
}
int main() {
    string plaintext;
    string key;
    cout<<"Enter the plain text: "<<endl;
    getline(cin, plaintext);
    cout<<endl<<"Enter the key: "<<endl;
    getline(cin, key);
    cout<<"The plain text you entered is: "<<endl<<plaintext<<endl;
    string ciphertext=encryption(plaintext,key);

    cout<<"The cipher text is :"<<endl<<ciphertext<<endl;
    cout<< "The ASCII value of ciphertext:";
    for(char ch: ciphertext)
    cout<<int(ch);
    cout<<endl;
    
    cout<<"The plain text after decryption is: "<<endl<<encryption(ciphertext,key);

return 0;
}
