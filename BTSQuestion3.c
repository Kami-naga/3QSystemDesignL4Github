#include <stdio.h>
#define getLen(arr) sizeof(arr)/sizeof(arr[0])
//before
//void printArr(int* a){
//  int i;
//  int len = getLen(a);
//  printf("len:%d\n",getLen(a));
//  printf("the array is now: \n");
//  for(i=0;i<len;i++){
//    printf("%d ", a[i]);
//  }
//  printf("\n");
//  return;
//}

void printArr(int* a, int len){
  int i;
  printf("the array is now: \n");
  for(i=0;i<len;i++){
    printf("%d ", a[i]);
  }
  printf("\n");
  return;
}


int partition(int* a, int start, int end){
  int anchor = a[start]; //just let the first element of the array become anchor
  //let the element which is smaller than anchor stay at left and the bigger ones stay at right
  //use two-pointer technique to implement this algorithm
  int p = start;
  for(int i = start+1;i<=end;i++){
    if(a[i] < anchor){
      p++;
      //swap 2 values(if i & p are the same, swallow copy will happen and will make lots of 0)
      //a[i] = a[i] + a[p];
      //a[p] = a[i] - a[p];
      //a[i] = a[i] - a[p];
      int tmp = a[i];
      a[i] = a[p];
      a[p] = tmp;
    }
  }
//  a[start] = a[start] + a[p];
//  a[p] = a[start] - a[p];
//  a[start] = a[start] - a[p];
//  if start & p are the same, swallow copy will happen and will make lots of 0
  int tmp = a[start];
  a[start] = a[p];
  a[p] = tmp; 
  return p;
}

void quickSort(int* a, int start, int end){
  if(start >= end) return;
  int p = partition(a, start, end); //get the position of the partition element
  printArr(a, end+1);
  quickSort(a, start, p); //do same operation to the left part of the array
  quickSort(a, p+1, end); //do same to right part
}

int main(){
  int a[10] = {5,8,3,7,10,2,9,4,6,1};
  printf("the length of array is %lu\n",getLen(a));
  quickSort(a,0,getLen(a)-1);
  printArr(a, getLen(a));
}

