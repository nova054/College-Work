#include<iostream>
#include<unordered_set>
using namespace std;
string removeDuplicates(string );

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

void encrypting(){
    
}
string plain_text(string plaintext){
string plain;
for(char ch: plaintext){
ch = (ch=='i') ? 'j' : ch;
if(!isspace(ch))
plain+=tolower(ch);
}
plaintext=plain;
if(plaintext.length()%2!=0)     //Adding filler character
plaintext+='x';

int length=plaintext.length();
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

string* cipher_text(string* plaintext, string* key, int lenght){
    // int l=0;
    string ciphertext;
    string index;
    int row,col;
    for(int l=0; l<(lenght); l++){
    for(int i=0;i<2  ;i++){
        for(int j=0;j<5;j++){
            for(int k=0;k<5;k++){
            if(plaintext[l][i]==key[j][k]){
                row=j;
                col=k;
                cout<<row<<" "<<col<<endl;
                }
            }
            }
                // cout<<row<<" "<<col<<endl;
            index+=to_string(row);
            index+=to_string(col);
        }

    }
    cout<<endl<<index<<endl;
    int a=0,b=0,c=0;
    if(index[a]==index[a+2]){
    ciphertext+=key[index[a]][index[a+1]];
    ciphertext+=key[index[a+2]][index[a+3]];

    }
    cout<<ciphertext;
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
En.cipher_text(pt,k,length_Of_div_plaintext);



return 0;
}











