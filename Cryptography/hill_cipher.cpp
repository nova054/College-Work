#include<iostream>
#include<cstring>
using namespace std;
    int len;                            
string encryption(int len,string key,string plaintext){
    // cipher text= (plaintext * key) % 26
    // plain text= (ciphertext * key -1) % 26
    string cipher;
    string *k= new string[4/2];
    // string k[len/2];
    cout<<len<<endl;
        int count = 0, j = 0;
        for (char ch : key)
        {   
            count++;
            k[j] += ch;
            if (count % (4/2) == 0)
                j++;
            cout<<k[j]<<endl;
        }
/*
int ciphertext[len];
// char cipher;
    for(int i=0; i<len; i++){
        for (int j=0; j< len; j++){
            ciphertext[i] +=int(k[i][j]-'a')*int(plaintext[j]-'a');
        }
        ciphertext[i]%=26;
        cipher+=char(ciphertext[i])+'a';
    }
    return cipher;*/
}
void decryption(){

}

void inverse(){


}
 int main(){
    int len;
    char cipher;
// cout<<"Enter the length of the plaintext: ";
// cin>>len;

string key="ajay";
string plaintext= "aj";
cout<<"Enter the plain text:"<<endl;
// getline(cin,plaintext);

// cout<<"Len of plaintext"<<plaintext.length();
cout<<"enter the key:"<<endl;
    // getline(cin, key);

// cout<<"Len of key"<<key.length();
int l= plaintext.length();
if(l*2!=key.length()){
    cout<<"The length of plain text is not equal to the key..........";
    exit(0);
}
len=key.length();
encryption(len, key, plaintext);
// cout<<"Ciooher text"<<encryption(len,key, plaintext);
// cout<<cipher<<endl;



    return 0;
 }