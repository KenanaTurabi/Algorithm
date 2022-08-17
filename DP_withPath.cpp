/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

void Print_Optimal_Stones_Power(int i, int j, int n, int* bracket,int& index,int arr[]){
     if (i == j) {
        cout << "stone"<< index++<<"--> power = "<<arr[i++]<<" ";
        return;
    }
        //cout<< "(";

    Print_Optimal_Stones_Power(i, *((bracket + i * n) + j), n,
                     bracket, index,arr);
    Print_Optimal_Stones_Power(*((bracket + i * n) + j) + 1, j, n,
                     bracket, index,arr);          
            cout<< "\n";
             
    return ;
}


int calaculatePower(int p,int q,int r,int stonesPower[],int num){
    int bracket[num][num];
    int sum=0;
    int qq;
    int maxVal;
    int j;
    int** matrix = new int*[num];
   for (int i = 0; i < num; ++i)
    matrix[i] = new int[num];

    for (int i=0;i<num;i++){
        matrix[i][i]=p*stonesPower[i]*stonesPower[i]+q*stonesPower[i]+r;
    }
    
    for(int d=2;d<=num;d++){
        for(int i=0;i<num-d+1;i++){
            j=i+d-1;
             for(int p=i;p<=j;p++){
                sum+=stonesPower[p];
              }
              maxVal=p*sum*sum+q*sum+r;
              sum=0;
            for(int k=i;k<j;k++){
                qq=matrix[i][k]+matrix[k+1][j];
                if(qq>maxVal)
                maxVal=qq;
                matrix[i][j]=maxVal;
                bracket[i][j]=k;
                
            }
        }
        
    }
   
        int index =1;
 
    cout << "The Optimal Sequence is : "<<"\n";
    Print_Optimal_Stones_Power(0, num - 1, num, (int*)bracket, index,stonesPower);
        return  matrix[0][num-1];
}
int main()
{
   int numstones;
   cin>>numstones;
   
   
    int p;
    int q;
    int r;
    int rows;
    int cols;
    
    int* stonesPower=new int [numstones];
 
    
    cin>>p>>q>>r;
    for(int i=0;i<numstones;i++) cin>>stonesPower[i];
    int power=calaculatePower(p,q,r,stonesPower,numstones);
    cout<<power;
    return 0;
}
