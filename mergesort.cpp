//11923807 Kenana Turabi
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


    
void merge(int arr[], int l,int m,int r){
    int i,j,k;
    int tArray[r-l+1]; //tmp array
     i=l;k=0;j=m+1;//initializing --> index of the arrays
    
    while( i<=m && j<=r){ //comparasion
        
            if(arr[i]<arr[j]){
                tArray[k]=arr[i];
                i++;k++;
            }
            else{
                tArray[k]=arr[j];
                j++;k++;
            }
        }
    while(i<=m){ //the rest
        tArray[k]=arr[i];
        k++;i++;
    }
    while(j<=r){// the rest
        tArray[k]=arr[j];
        k++;
        j++;
    }
    for(i=l;i<=r;i++){ //copy the tmp into the main array
        arr[i]=tArray[i-l];
    }
}

void mergeSort(int arr[],int left,int right){
    int mid;
    if(right>left){   
        mid=(left+right)/2;
        mergeSort(arr,left,mid);
        mergeSort(arr,mid+1,right);
        merge(arr,left,mid,right);
    }
        
    }

void printArray(int arr[],int size){
    cout<<"[";
    for(int i=0;i<size-1;i++){ //print size-1 elements
        cout<<arr[i]<<",";
    }
    cout<< arr[size-1]<<"]";
}

int main(){
    int s ;
    cin >> s;
    int a[s];
    for(int i=0;i<s;i++){
        cin>>a[i];
    }
    mergeSort(a,0,s-1);
    printArray(a,s);

    return 0;
}
