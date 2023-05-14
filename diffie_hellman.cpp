#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<iostream>

using namespace std;

int main(){
    int g=7;
    int p=5;

    int a,b,step1,step2,step3,step4;

    cout<<"Enter number of a : ";
    cin>>a;
    cout<<"Enter number of b : ";
    cin>>b;

    cout<<"Step 1"<<endl;
    step1= (int)pow(g,a)%p;
    cout<<"Alice code : "<<step1<<endl;

    cout<<"Step 2"<<endl;
    step2= (int)pow(g,b)%p;
    cout<<"Bob code : "<<step2<<endl;

    cout<<"Step 3"<<endl;
    step3= (int)pow(step1,b)%p;
    cout<<"Bob code : "<<step3<<endl;

    cout<<"Step 4"<<endl;
    step4= (int)pow(step2,a)%p;
    cout<<"Bob code : "<<step4<<endl;

    if(step3==step4){
        cout<<"Same value";
    }
}
