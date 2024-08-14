#include <iostudio>
#include <cstdio>
#include <vector>
#include <map>



int main(){
    int m,n,i,k,v,j,count,found;
    /*
    n=num elements
    m=num queries
    */
    scanf("%d %d", &n, &m);
    int *arr = calloc (n, sizeof(int));
    for(i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }
    while(scanf("%d %d", &k, &v)){
        count=0;
        found=0;
        for(j=0;j<n;j++){
            if (v == arr[j]){
                count++;
                continue;
            }
            else if (count == k){
                printf("%d\n", j);
                found=1;
                break;
            }
        }
        if(!found){
            printf("0\n");
        }
    }
    return 0;
}