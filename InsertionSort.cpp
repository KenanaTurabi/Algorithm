//Kenana Turabi 11923807
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void insertion_sort(int Arr[],int s){
    for(int i=0;i<s;i++){
        int key = Arr[i];
        int j;
        for(j=i-1;j>=0&&Arr[j]>key;j--){
            Arr[j+1]=Arr[j];
        }
        Arr[j+1]=key;
    }
    cout<<"[";
    for(int k=0;k<s-1;k++){
        cout<<Arr[k]<<",";
    }
    cout<<Arr[s-1]<<"]";
}

int main() {
    int size;
    cin>>size;
    int *Array=new int[size];
    for(int i=0;i<size;i++){
        cin>>Array[i];}
    insertion_sort(Array,size);
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
