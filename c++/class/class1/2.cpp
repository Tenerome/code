#include<iostream>
using namespace std;
int main(){
    int a;
    cout<<"input:";
    cin>>a;
    if(a%4==0&&a%100!=0)
        cout<<"��ͨ����";
    else if(a%400==0)
        cout<<"��������";
    else
        cout<<"��������";
}
