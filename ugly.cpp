#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;
int main(){
    int i;
    long top;
    priority_queue<long, vector<long>, greater<long> > minheap;
    unordered_set<long> numbers;
    minheap.push(1);
    numbers.insert(1);
    for(i=1;i<=1500;i++){
        top = minheap.top();
        if(numbers.find(top*2) == numbers.end()){
            minheap.push(top*2);
            numbers.insert(top*2);
        }
        if(numbers.find(top*3) == numbers.end()){
            minheap.push(top*3);
            numbers.insert(top*3);

        }
        if(numbers.find(top*5) == numbers.end()){
            minheap.push(top*5);
            numbers.insert(top*5);

        }
        minheap.pop();
    }

    cout<<"The 1500'th ugly number is "<<top<<"."<<endl;
    return 0;
}