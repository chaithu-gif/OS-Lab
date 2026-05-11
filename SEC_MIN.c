#include<stdio.h>
int main(){
    int n,a[100];
    printf("\n enter the number of elements:\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("\n element:%d:",i+1);
        scanf("%d",&a[i]);
    }
    int larg=-99999;
    int sec_larg=-9999;
    for(int i=0;i<n;i++){
        if(a[i]>larg){
            sec_larg=larg;
            larg=a[i];
        }
        else if(a[i]>sec_larg && a[i]!=larg){
            sec_larg=a[i];
        }
    }
    printf("\n se_largest element is %d",sec_larg);
    return 0;
}
