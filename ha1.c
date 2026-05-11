#include<stdio.h>
#include<stdlib.h>
mergesort(a,low,mid,high){
if(low<high){
    mid=(low+high)/2;
    mergesort(a,low,mid);
    mergesort(a,mid+1,high);
    merge(a,low,mid,high);
}
}
merge(a,low,mid.high){
int b[];
i=low,j=mid+1,k=l
while(i<=mid && j<=high){
    if(a[i]<a[j]){
        b[k]=a[i];
        i++;
    }
    else{
        b[k]=a[j];
        j++;
    }
    k++
}
while(i<=mid){
    b[k++]=a[i];
    i++;
}
while(j<=high){
    b[k++]=a[j];
    j++;
}
for(l=0;l<i;i++){
    a[i]=b[i];
}
}
int main(){
    int i,j,n;
    printf("enter array size:");
    sacnf("%d",&n);
    printf("enter array elements:");
}



