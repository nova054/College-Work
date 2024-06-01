#include<iostream>

using namespace std;


int main(){
 string p="abc";
 string k="bcd";
 char c= p[0]^ k[0];
 cout<<c;
 char pl= c^k[0];
 cout<<pl;

}