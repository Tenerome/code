#include<iostream>
using namespace std;
int main(){
int a[3][3],i,j;
cout<<"input:";
for(i=0;i<=2;i++)
    for(j=0;j<=2;j++)
        cin>>a[i][j];
cout<<"ԭ����:"<<endl;
for(i=0;i<=2;i++){
     for(j=0;j<=2;j++)
        cout<<a[i][j]<<" ";
     cout<<endl;
}
cout<<"ת�þ���:"<<endl;
for(i=0;i<=2;i++){
     for(j=0;j<=2;j++)
        cout<<a[j][i]<<" ";
     cout<<endl;
}


}
