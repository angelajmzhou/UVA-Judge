#include <stdio.h>
#include <stdlib.h>

int main(){
    int i,j,n,p,q,count,weight,cases;
    int *arr;
    scanf("%d",&cases);
    for(i=1;i<=cases;i++){
        scanf("%d %d %d",&n,&p,&q);
        arr = (int *)calloc(n,sizeof(int));
        for(j=0;j<n;j++){
            scanf("%d",&arr[j]);
         }
        count = 0;
        weight = 0;
        for(j=0;count<p && (arr[j]+weight<=q) && j<n;j++){
                weight+=arr[j];
                count++;
         }
        free(arr);
        printf("Case %d: %d\n", i, count);
    }
    return 0;
}