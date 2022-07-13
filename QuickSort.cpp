//11923807  Kenana Turabi
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void swap(int arr[],int a,int b){
     int tmp = arr[a];
     arr[a] = arr[b];
     arr[b] =tmp;
}

int partion(int a[],int s,int e){
   int pivot=a[e];// i have picked the last element as pivot 
   int i=s-1;//point at the last element less than pivot
   //int j=s;//for transfering
   
    for(int j=s;j<e;j++){// while the size of array more than one element
        if(a[j]<pivot){
            i++;
            swap(a,i,j);     
        }
    }
    swap(a,i+1,e);
    return i+1;
    
}
void quickSort(int a[],int start,int end){
    if(start<end){
    int p=partion(a,start,end);
    quickSort(a,start,p-1);
    quickSort(a,p+1,end);
    }
    
}
void printArray(int array[],int size){
    cout<<"[";
     for(int l=0;l<size-1;l++){
        cout<<array[l]<<",";
    }
    cout<<array[size-1]<<"]";
}

int main()
{
    int s ;
    cin>>s;
    int arr[s];
    for(int k=0;k<s;k++){
        cin>>arr[k];
    }
    quickSort(arr,0,s-1);
    printArray(arr,s);
    
    return 0;
}



