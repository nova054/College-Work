#include<iostream>
#include<cmath>
using namespace std;

float encrypt[2][1], decrypt[2][1], a[2][2], b[2][2], mes[2][1], c[2][2];
void inverse();
void encryption(){
    int i,j,k;
    for(i=0;i<2;i++)
    for(j=0;j<1;j++)
    for(k=0;k<2;k++)
    encrypt[i][j]=encrypt[i][j]+a[i][j]+mes[k][j];
    cout<<"Encrypted string is :"<<endl;
    for(i=0;i<2;i++)
    cout<<char(fmod(encrypt[i][0], 26)+97);
}
void decryption(){
    int i,j,k;
    inverse();
    for(i=0;i<2;i++)
    for(j=0;j<1;j++)
    for(k=0;k<2;k++)
    decrypt[i][j]=decrypt[i][j]+a[i][j]+encrypt[k][j];
    cout<<"Decrypted string is :"<<endl;
    for(i=0;i<2;i++)
    cout<<char(fmod(decrypt[i][0], 26)+97);   
    cout<<endl;
}
void getkeymessage(){
    int i,j;
    char msg[2];
    cout<<"ENter 2x2 matrix for key (inversible):"<<endl;
    for(i=0;i<2;i++)
    for(j=0;j<2;j++)
    {
        cin>>a[i][j];
        c[i][j]=a[i][j];
    }
    cout<<endl<<"Enter a 2 letter string: ";
    cin>>msg;               //string or char.
    for(i=0;i<2;i++)
    msg[i]=msg[i]-97;               // something is wrong.

}
void inverse(){
    int i,j,k;
    float p,q;
    for(i=0;i<2;i++)
    for(j=0;j<2;j++){
    if(i==j)
    b[i][j]=1;
    else
    b[i][j]=0;
    }
    for(k=0;k<2;k++)
    {
        for(i=0;i<2;i++){
            for(i=0;i<2;i++){
                p=c[i][k];
                q=c[k][k];
                for(j=0;j<2;j++){
                    if(i!=k){
                        c[i][j]=c[i][j]*q-p*c[k][j];
                        b[i][j]=b[i][j]*q-p*b[k][j];             
                        }
                }
            }
        }
    }
    for(i=0;i<2;i++){
        for(j=0;j<2;j++)
        b[i][j]=b[i][j]/c[i][i];
    }
    cout<<endl<<"Inverse matrix is"<<endl;
    for(i=0;i<2;i++){
    for(j=0;j<2;j++)
    cout<<b[i][j];
    cout<<endl;
    }

}

int main()
{
    getkeymessage();
    encryption();
    decryption();
    return 0;
}