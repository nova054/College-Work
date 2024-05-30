#include<iostream>
#include<unordered_set>
using namespace std;
// string removeDuplicates(string );

class Encryption{
private:
string* key=new string[5];

public:

string removeDuplicates(string input) {
    unordered_set<char> seen;
    string result;
    for(int ij=0;ij<input.length();ij++){
        input[ij]=tolower(input[ij])=='i' ? 'j' : input[ij]  ;  // Let i and j be same and denoted by j.
    }
    for (char chh : input) {
        char ch=tolower(chh);
        // Check if the character is already in the set
        if (seen.find(ch) == seen.end()) {
            // If not, add it to the set and to the result string
            seen.insert(ch);
            result += ch;
        }
    }
    
    return result;
}


string* showkeys(string keys){
    
int k=0;
// cout<<"The key that is now used is: "<<endl;
for(int i=0;i<5;i++){
    for (int j=0; j<5;j++){
        key[i]+=keys[k];
        k++;
        // cout<<key[i][j]<<" ";
    }
    // cout<<endl;
}
    return key;
}

string plain_text(string plaintext){
string plain;
for(char ch: plaintext){
ch = (ch=='i') ? 'j' : ch;

if(!isspace(ch))
plain+=tolower(ch);
}
plaintext=plain;
// if(plaintext.length()%2!=0)     //Adding filler character
// plaintext+='x';
 for (int i = 0; i < plaintext.length(); i += 2) 
        if (i + 1 == plaintext.length() || plaintext[i] == plaintext[i + 1]) 
             plaintext.insert(i + 1, 1, 'x');



// int length=plaintext.length();
return plaintext;
}

string* arraydiv(string plaintext){
int length = plaintext.length();
string* array= new string[length/2];
int count=0, j=0;
for(char ch : plaintext){
    count++;
    array[j]+=ch;
    if(count%2==0)
    j++;
}
return array;
}

string cipher_text(string* plaintext, string* key, int lenght, bool encrypt){
    // int l=0;
    string ciphertext;
    string indexing;
    int row,col;
    for(int l=0; l<(lenght); l++){
    for(int i=0;i<2  ;i++){
        for(int j=0;j<5;j++){
            for(int k=0;k<5;k++){
            if(plaintext[l][i]==key[j][k]){
                row=j;
                col=k;
                // return;
                // cout<<row<<" "<<col<<endl;
                }
            }
            }
            indexing+=to_string(row);
            indexing+=to_string(col);
                cout<<indexing<<endl;
        }

    }
    // cout<<endl<<index<<endl;
    int index[indexing.length()];
for(int c=0 ;c<indexing.length();c++)
{
    index[c]=indexing[c]-'0';
    cout<<index[c]<<endl;
}


int len= indexing.length();
cout<<endl<<"length"<<"="<<len<<endl;
// int len=sizeof(index)/sizeof(index[0]);

    int a=0,b=0,c=0;
    // for(a=0; a<index.length();a+=4){
    for(a=0; a<len;a+=4){
    if(index[a]==index[a+2]){// in same row
    ciphertext+=key[index[a]][index[a+1]+1];
    ciphertext+=key[index[a+2]][index[a+2+1]+1];
    cout<<ciphertext<<endl;
    }
    else if(index[a+1]==index[a+1+2]){// in same column
    ciphertext+=key[index[a]+1][index[a+1]];
    ciphertext+=key[index[a+2]+1][index[a+2+1]];
    cout<<ciphertext<<endl;
    }
    else{
        ciphertext+=key[index[a+2]][index[a+2+1]];
        ciphertext+=key[index[a]][index[a+1]];
    cout<<ciphertext<<endl;
    }
    }
    cout<<ciphertext;
    // return ciphertext;
    }

};



int main(){
int length;
Encryption En;
string plaintext;
string keyword="Bingo";
for(char ch='a';ch<='z';ch++)
keyword+=ch;
string keys= En.removeDuplicates(keyword);
cout<<keys;
string* k=En.showkeys(keys);
cout<<"The key that is now used is: "<<endl;

for(int i=0;i<5;i++){
for(int j=0; j<5; j++)
cout<<k[i][j]<<" ";
cout<<endl;
}

cout<<endl<<"Enter the plain_text to encrypt:"<<endl<<"=>";
getline(cin, plaintext);
plaintext=En.plain_text(plaintext);
// length=plaintext.length();
int length_Of_div_plaintext=plaintext.length()/2;
cout<<endl<<"The plain text is:"<<endl<<"=>"<<plaintext<<endl;

string* pt=En.arraydiv(plaintext);
for(int e=0;e<length_Of_div_plaintext;e++)
cout<<pt[e]<<endl;
// string ciphertext=
En.cipher_text(pt, k, length_Of_div_plaintext, true);

// void cipher_text(string* plaintext, string* key, int lenght, bool encrypt, string& ciphertext)
// En.cipher_text(pt,k,length_Of_div_plaintext);
// cout<<"The cipher text is :"<< ciphertext;



return 0;
}











