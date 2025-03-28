#include <stdio.h>
#include <stdlib.h>
void swap(int *arr,int a,int b)
{
    int tmp;
    tmp = arr[a]; 
    arr[a]=arr[b];
    arr[b]=tmp;
}
int partition(int* arr , int i, int j ){
    if(i>=j)
        return 0;
    int count_smaller=0;
    for(int a = i;a<=j;a++ ){
        if(arr[a]<arr[i]){
            count_smaller ++;
           
        }
    }
    int k = i+count_smaller;
    swap(arr,k,i);
    int d =k+1;
   
    for(int a=i;a<k;a++){
        if(arr[a]>arr[k]){
            while (arr[d]>arr[k]){
                d++;
            }
            swap(arr,d,a);
           
        }    
    }
 return k;  
}

void sort_aux(int* arr, int i, int j ){
   
   
    if(j-i>0){

        int k = partition(arr,i,j);
        sort_aux(arr,i,k-1);
        sort_aux(arr,k+1,j);
           
       
    }
           
}

void quicksort(int *arr,int n){
    sort_aux(arr,0,n);
}
int main(){
    int* arr = malloc(sizeof(int)*8);
    arr[5]=12;
    arr[4]=13;
    arr[3]=14;
    arr[2]=15;
    arr[1]=16;
    arr[0]=17;

    quicksort(arr,5);
    for(int i = 0 ; i < 6;i++){
        printf("%i ",arr[i]);
    }
}
