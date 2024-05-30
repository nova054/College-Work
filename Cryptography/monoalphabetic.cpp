#include<iostream>
#include<vector>
#include<ctime>

using namespace std;

vector<int> key();
string encryption(string ,vector<int>);
string decryption(string, vector<int>);


int main(){
    vector <int> keys=key();
    // vector <int> numbers=number();
    cout<<"The key that is used for: "<<endl<<"=>"<<"[";
    for(char al='a';al<'z';al++)
    cout<<al<<",    ";
    cout<<"z"<<"]"<<endl<<"is:"<<endl<<"=>"<<"[";
    for(int k=0;k<25;k++)
    cout<<keys[k]<<",   ";
    cout<<keys[25]<<"]"<<endl<<"=>"<<"[";
    for(int kk=0;kk<25;kk++)
    cout<<char('a'+keys[kk])<<",   ";
    cout<<char('a'+keys[25])<<"]"<<endl;
    cout<<"The mapping of each character is:"<<endl<<"=>[";
    for(char all='a';all<'z';all++)
    cout<<all<<"="<<char('a'+keys[all-'a'])<<", ";
    cout<<"]"<<endl;
    
    
string plain;
cout<<"Enter the string to encrypt: "<<endl<<"=>";
getline(cin,plain);
string cipher_text=encryption(plain,keys);
cout<<endl<<"The encrypted text is:"<<endl<<"=>"<<cipher_text;

cout<<endl<<"The decrypted text is:"<<endl<<"=>"<<decryption(cipher_text,keys);

}


string encryption(string plain_text,vector<int> key){
string ciphertext;
char chh;
    for (char ch : plain_text) {
        if (ch=='\0')
        break;
        if(!isspace(ch)){
            ch= tolower(ch);
            // char base = islower(ch) ? 'a' : 'a';
            int index = int(ch - 'a' );
            chh= 'a'+key[index];
            ciphertext += chh; 
        }
        }
    return ciphertext;
}
string decryption(string plain_text,vector<int> key){
string ciphertext;
    vector<int> number(26);
    for (int i=0; i<26 ;i++)
        number[i]=i;
char chh;
    for (char ch : plain_text) {
        if (ch=='\0')
        break;
        int index = int(ch - 'a' );
        for(int kkk=0;kkk<26;kkk++)
            if(key[kkk]==index){
                chh= 'a'+number[kkk];
                ciphertext += chh; 
                }
            
        }
    return ciphertext;
}




vector<int> key(){
    srand(time(0));
    vector<int> numbers(26);
    for (int i=0; i<26 ;i++)
        numbers[i]=i;
    for (int i=0;i<26;i++){
        int random_number=rand()%26;
        swap(numbers[i], numbers[random_number]);
    }
    return numbers;    
}