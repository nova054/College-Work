#include <iostream>
#include<vector>
#include<string>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

using namespace std;
// vector<int> key(){
//     srand(time(0));
//     vector<int> numbers(26);
//     for (int i=0; i<26 ;i++)
//         numbers[i]=i;
//     for (int i=0;i<26;i++){
//         int random_number=rand()%26;
//         swap(numbers[i], numbers[random_number]);
//     }
//     return numbers;    
// }
// int main() {
//     // vector<int> keys=key();
//  string andd="abc";
// // for (char ch: andd){
// // cout <<ch<<endl;
// // cout <<(int(ch)-'a')<<endl;
// // cout<< andd[ch];
// int keys[5]={3,2,1,4,0};
// char chh;
// string ciphertext;
//     for (char ch : andd) {
//         if (ch=='\0')
//         break;
//             char base = islower(ch) ? 'a' : 'a';
//             int index = int(ch - base );
//             cout<<index<<endl;
//             cout<<endl;
//             chh= 'a'+keys[index];
//             cout<<keys[index]<<" ";
//             cout<<endl<<chh<<endl;
//         ciphertext += chh; // Append the character to the ciphertext
//         }
//         cout<<endl<<ciphertext;
        


// }
// // cout<<ch;




// string decryption(string plain_text){
// string plain_text="fmfcduadvy";
// string ciphertext;
//     int number[26];
//     for (int i=0; i<26 ;i++)
//         number[i]=i;
// char chh;
//     for (char ch : plain_text) {
//         if (ch=='\0')
//         break;
//         if(!isspace(ch)){

//             int index = int(ch - 'a' );
//             // chh= 'a'+number[index];
//             chh= 'a'+index;
//             cout<<index<<endl;
            
//             ciphertext += chh; 
//         }
//         }
//         cout<<ciphertext<<endl;

//         cout<<char('a'+10)<<endl;
//     // return ciphertext;

// string plaintext="Ajay is my name and its all good";

// string plain_text(string plaintext){
// string plain;
// for(char ch: plaintext)
// if(!isspace(ch))
// plain+=tolower(ch);
// plaintext=plain;

// // cout<<endl<<length;
// // cout<<plaintext.length();
// if(plaintext.length()%2!=0)     //Adding filler character
// plaintext+='x';

// int length=plaintext.length();
// return plaintext;
// }
// cout<<endl<<length;
// // Plaintext is gained.
// //Now dividing plain text to 2 alphabet each

// int length =10;


string* arraydiv(string plaintext){
int length = plaintext.length();
string* array= new string[length/2];
// string array[length/2];
int count=0, j=0;
for(char ch : plaintext){
    count++;
    // cout<<ch<<endl;
    array[j]+=ch;
    // cout<<array[j]<<endl;
    if(count%2==0)
    j++;
}
return array;

}


int main(){
    string sth="abcdefgh";
    string* sss= arraydiv(sth);
for(int i=0;i<sth.length()/2;i++){
    cout<<endl<<sss[i];
}
cout<<endl<<sss<<endl;
cout<<endl<<sizeof(sss[0])<<endl;


}