#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n,i,j,flip,temp;
    while(cin>>n){
        flip=0;
        vector<int> nums(n);
        for(i=0;i<n;i++){
            cin>>nums[i];
        }
        for(i=0;i<n;i++){
            for(j=0;j<n-i-1;j++){
                if(nums[j]>nums[j+1]){
                    temp = nums[j];
                    nums[j]=nums[j+1];
                    nums[j+1]=temp;
                    flip++;
                }
            }
        }
        cout<<"Minimum exchange operations : "<<flip<<endl;
    }
    return 0;
}