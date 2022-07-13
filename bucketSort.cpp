#include<iostream>
using namespace std;
int findMaxDigitsNumber(int arr[], int size)
{
    int maxNum=arr[0];//suppose the first element is the max
    int digitsMaxNumber=0;// number of digits in the max num 
    for(int j=1;j<size;j++)
    {
        if(arr[j]>maxNum)
            maxNum=arr[j];
    }
    while(maxNum>0)
    {
        digitsMaxNumber++;
        maxNum=maxNum/10;
    }
   
    return digitsMaxNumber;
}


void bucketSort(int arr[],int *bucket[],int size)
{
    int tmpForIndex[10];//to mov inside the colums (internal list) to store the values from the main array
    int k;
    int p;//index to fill the main array 
    int divideVal=1;
    int count;//#digits from the max num
    count=findMaxDigitsNumber(arr,size);
  
    for(int m=0;m<count;m++)
    {
        for(int i=0;i<10;i++)
            tmpForIndex[i]=0;//initially it full with zeros
        
        for(int i=0;i<size;i++)
        {
            k=(arr[i]/divideVal)%10; //to get one digit
            bucket[k][tmpForIndex[k]]=arr[i];
            tmpForIndex[k]++;
        }
     
        p=0;
        for(int i=0;i<10;i++)//loop as the number of buckets(0-9 digits)
        {
            for(k=0;k<tmpForIndex[i];k++)
            {
                arr[p]=bucket[i][k];
                p++;
            }
        }
        divideVal*=10; //a7ad then 3sharat then me2at 
    }
}
 void printArray(int a[],int s){
     cout<<"[";
     for(int j=0;j<s-1;j++){
         cout<<a[j]<<",";
     }
     cout<<a[s-1]<<"]";
 }

int main(){
    int size,*arr;
    int *bucket[10];//number of digits[0-9]
   cin>>size;
    arr=new int[size+1];
    for(int i=0;i<size;i++)
    cin>> arr[i];
    for(int i=0;i<10;i++)
        bucket[i]=new int[size];//each bucket from the buckets has array with the size of the main array
    
    bucketSort(arr,bucket,size);
    printArray(arr,size);
    
    return 0;
}