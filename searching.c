#include<stdio.h>
#include<stdlib.h>

int main(){
  int n,i,missing_ele,*arr,sum;
  printf("How many elements");
  scanf("%d",&n);
  arr = (int *)malloc((n-1) * sizeof(int));
  for(i=0;i<(n-1);i++){
   scanf("%d",&arr[i]);
  }
  sum = 0;
  for(i=0;i<(n-1);i++){
   sum = sum + arr[i];
  }
  missing_ele = n*(n+1)/2 - sum;
  printf("%d\n",missing_ele);
}
