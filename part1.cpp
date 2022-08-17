#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int calaculatePower(int p,int q,int r,int stonesPower[],int i,int j){
    int sum=0;
    int maxVal=0;
    int power=0;
    
    for(int p=i;p<=j;p++){
    sum+=stonesPower[p];
    }
    maxVal=p*sum*sum+q*sum+r;

    if(i==j){
    power= p*stonesPower[i]*stonesPower[i]+q*stonesPower[i]+r;
    return power;
    }
    
    for(int k=i;k<j;k++){
    sum=calaculatePower( p, q, r, stonesPower, i, k)+calaculatePower( p, q, r, stonesPower, k+1, j);
    if(sum>maxVal)
    maxVal=sum;
        
    }
    return maxVal;
}

int main()
{
    int numstones;
    int p;
    int q;
    int r;
    int* stonesPower=new int [numstones];
    cin>>numstones>>p>>q>>r;
    for(int i=0;i<numstones;i++) cin>>stonesPower[i];
    int power=calaculatePower(p,q,r,stonesPower,0,numstones-1);
    cout<<power;
    return 0;
}

