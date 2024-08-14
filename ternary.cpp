#include <iostream>
#include <cmath>
// problem 11185
using namespace std;

int main(){
    long int n,i,j;
    short int s[1000000];
    while(cin>>n && n>=0){
        if(n==0){
            cout<<0<<endl;
            continue;
        }
        i=0;
        while(n>0){
            s[i] = (n%3);
            n/=3;
            i++;
        }
        for(j=i-1; j>=0; j--){
            cout<<s[j];
        }
        cout<<endl;
    }
    return 0;
}