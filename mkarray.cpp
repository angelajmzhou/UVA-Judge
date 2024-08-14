#include <iostream>
#include <cstdio>
#include <vector>
#include <map>

using namespace std;

int main(){
    int m,n,i,k,v,j,val;
    while(scanf("%d %d", &n, &m)){
        map<int, int> freqMap;
        map<int, vector<int> > posMap;
        for(i=1;i<=n;i++){
            scanf("%d", &val);
            freqMap[val]++;
            posMap[val].push_back(i);
        }
        for(j=0;j<m;j++){
            scanf("%d %d",&k,&v);
            if(freqMap[v]<k){
                printf("0\n");
            }else{
                printf("%d\n", posMap[v][k-1]);
            }
        }
        return 0;
    }

}