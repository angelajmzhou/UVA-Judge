#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n,i;
    while(cin>>n && n){
        vector<int> ages(n);
        for(i=0; i<n; i++){
            cin>>ages[i];
        }
        sort(ages.begin(), ages.end());
        cout<<ages[0];
        for(i=1;i<n;i++){
            cout<<" "<<ages[i];
        }
        cout<<endl;
    }
    return 0;
}