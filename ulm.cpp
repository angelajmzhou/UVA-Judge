#include <iostream>
using namespace std;

int main(){
    int m, n, i, cities, pos;
    bool ideal; 
    while(cin>>n && n){
        m = 2;
        while(true){
            //"downshift" after 1st cut
            cities = n-1;
            pos = (m-1)%cities; 
            ideal = true;
                while(cities>1){
                    if(pos==0){ // Ulm is 0. 
                        ideal = false;
                        break;
                    }
                    cities--;
                    pos = (pos+m-1)%cities;
                }
                if(ideal){
                    cout<<(m)<<endl;
                    break;
                }
            m++;
        }
    }
    return 0;
}