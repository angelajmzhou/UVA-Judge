#include <iostream>
#include <vector>
#include <iomanip>
/*prob 10370*/
using namespace std;

int main(){
    int c, i, j, n, g;
    double total, avg;
    cin>>c;
    for (i=0;i<c;i++){
        cin>>n;
        total=0;
        vector<double> grades(n);
        for (j=0;j<n;j++){
            cin>>g;
            grades[j] = g;
            total+=g;
        }
        avg = total/n;
        total = 0;
        for(j=0; j<grades.size();j++){
            if(grades[j]>avg){
                total++;
            }
        }
        avg = (total/n)*100.0;
        cout<<fixed<<setprecision(3)<<avg<<'%'<<endl;
        grades.clear();
    }
    return 0;
}