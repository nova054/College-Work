#include<iostream>

using namespace std;

string encryption(string plaintext, string key, bool encrypt){
    if(key.length()<plaintext.length()){
        key+=key;
    }
    if(key.length()>plaintext.length()){
        while(key.length()!=plaintext.length())
        plaintext+='x';
        // cout<<plaintext<<endl;
    }
    string ciphertext;
    int len=key.length();
    // cout<<endl<<len;
    for(int i= 0 ;i<len;i++){
        ciphertext+=  encrypt ? 
        ((plaintext[i]-'a' +key[i]-'a')+26)%26 + 'a'
        :
        ((plaintext[i]-'a') - (key[i]-'a')+26)%26 + 'a';

    }
    return ciphertext;
    }


int main(){
    string plaintext;
    string key;
    cout<<"Enter the plain text: "<<endl;
    getline(cin, plaintext);
    cout<<endl<<"Enter the key: "<<endl;
    getline(cin, key);
    cout<<"The plain text you entered is: "<<endl<<plaintext<<endl;
    string ciphertext=encryption(plaintext,key, true);

    cout<<"The cipher text is :"<<endl<<ciphertext<<endl;
    cout<<"The plain text after decryption is: "<<endl<<encryption(ciphertext,key, false);

return 0;
}