#include <iostream>

using namespace std;

int calaculatePower(int p,int q,int r,int stonesPower[],int num){
    int sum=0;
    int qq;
    int maxVal;
    int j;
   // for(int j=0;j<num;j++)cout <<stonesPower[j];
    
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
            }
        }
        
    }
        //for(int i=0;i<num;i++)
        //for(int j=0;j<num;j++) cout<<matrix[i][j]<<" ";
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
    // for(int i=0;i<numstones;i++) cout<<stonesPower[i];
    int power=calaculatePower(p,q,r,stonesPower,numstones);
    cout<<power;
    return 0;
}
