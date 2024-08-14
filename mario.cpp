#include <iostream>
#include <vector>

using namespace std;
/*prob 11764*/
int main(){
    int i,j,t,n,low,high,curr, next;
    cin >> t;
    for (i=1;i<=t;i++){
        low = 0; high = 0;
        cin >> n;
        cin >> curr;
        for (j=1;j<n;j++){
            cin >> next;
            if (curr>next){low++;}
            else if (next>curr){high++;}
            curr = next;
        }
        cout << "Case " << i <<": "<<high<<" "<<low<<endl;
    }
    return 0;
}