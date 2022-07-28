//Kenana Turabi 11923807
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int col=5;//coz num of columns is constant

int check_for_balancing(int Matrix [][col],int numRows){
    for(int r=0;r<numRows-1;r++){//loop about the parents which we will compare with
        //case1
        if(Matrix[r][2]==-1&&Matrix[r][3]==-1){//its a leaf
            continue;//do nothing coz this is a leaf
        }
        //case2
        else if (Matrix[r][2]==-1&&Matrix[r][3]!=-1){// if the node has just right child
            int right =Matrix[r][3];
            for(int i=0;i<numRows;i++){
                if(right==Matrix[i][0])//find the right child
                    if(Matrix[right][1]<Matrix[r][1]) 
                        return 0;//it should be greater than the parent value
            }
        }//end elseif
        
        //case3
        else if(Matrix[r][2]!=-1&&Matrix[r][3]==-1){// if the node has just left child
            int left =Matrix[r][2];
            for(int k=0;k<numRows;k++){
                if(left==Matrix[k][0])//we find the left child
                    if(Matrix[left][1]>Matrix[r][1]) 
                        return 0;//it should be less
                
            }
            
        }//end elseif
        
        //case4
        else if(Matrix[r][2]!=-1&&Matrix[r][3]!=-1){//the node has two childs left and right
            int left =Matrix[r][2];
            int right =Matrix[r][3];
            for(int k=0;k<numRows;k++){
                if(left==Matrix[k][0])//we find the left child
                    if(Matrix[left][1]>Matrix[r][1])
                        return 0;//it should be less than editor
                
            }
            for(int i=0;i<numRows;i++){
                if(right==Matrix[i][0])//find the right child
                    if(Matrix[right][1]<Matrix[r][1]) 
                        return 0;//it should be greater than the parent value
            }
            
        }// end elseif
       
    }//end for
     return 1; //its balance
}//end func
int check_for_node_colors(int Matrix [][col],int rows){
    
            for(int k=0;k<rows;k++){
                
                if(Matrix[k][4]==0){//if parent color is red
                    if(Matrix[k][2]==-1&&Matrix[k][3]!=-1)//the node has only right child
                        if(Matrix[Matrix[k][3]][4]==0)
                            return 0; //the child is red
                    
                    else if(Matrix[k][3]==-1&&Matrix[k][2]!=-1)//the node has only left child
                        if(Matrix[Matrix[k][2]][4]==0)
                            return 0;//the child is red
                    
                    else if(Matrix[k][3]!=-1&&Matrix[k][2]!=-1){//the node has both right and left childs
                        int left=Matrix[k][2];
                        int right =Matrix[k][3];
                        if(Matrix[left][4]==0||Matrix[right][4]==0)//one or both  of them red
                            return 0;
                        
                
                    }
                }//end if color of parent is red
            }//end for
                return 1;
            }//end fun
    

int checkPath(int Matrix[][5],int rows, int num_leafs ){//check if all paths have the same count of black nodes

//num of leavs equal num of paths 
    int CounterForLeaf[num_leafs];//its size is num of paths    
    int index;//index of a leaf then its chain up to the root 
    int cnt=0;//index of array of number of nodees in path
    int count=0; //count of nodes in each path
    
    for(int i=rows-1;i>=0;i--){//loop through matrix
        if(Matrix[i][2]==-1&&Matrix[i][3]==-1){//start from one leaf
            index=i;
            count+=Matrix[index][4];//add its color 
            for(int k=rows-1;k>=0;k--){
                
                if(Matrix[k][2]==Matrix[index][0]){//if the node was a left child
                    count+=Matrix[k][4];//add color of parent
                    index=k;//go up to the parent 
                    k=rows-1;//back to the bottom again
                }//end of if
            
            else if(Matrix[k][3]==Matrix[index][0]){//if the node was a right child
                    count+=Matrix[k][4];//add color of parent
                    index=k;//go up to the parent 
                    k=rows-1;//back to the bottom again
                }//end of elseif
                
            }//end of inner loop
        }//end of if
        else continue;//end if
        CounterForLeaf[cnt]=count;
        cnt++;
        count=0;
        
    }//end of outer loop ---> loop around leafs
    
    
    int tmp=CounterForLeaf[0];
    //compare the array elements to checl if they are equal
    for(int j=1;j<num_leafs;j++){
        if(tmp==CounterForLeaf[j]) continue;
        else return 0;
        
    }
    
     return 1;
}//end of func

int main() {
    int num_rows;
    int numLeaf =0;
    cin>>num_rows;
    int tree[num_rows][5];
    int Flag0=1;//check root flag
    int Flag2=1;//balancing flag
    int Flag1=1;//compare flag
    int Flag3=1;//color Flag
    int ind=0;//index1 for reading tree into matrix
    int ind2=0;//index2 for counting num of leavs


    
    while(ind<num_rows){  //read tree as matrix

        for(int j=0;j<5;j++){
            cin>>tree[ind][j];
        }
        ind++;
    }
    
    
    while(ind2<num_rows){ //count num of leavs
    if(tree[ind2][2]==-1 && tree[ind2][3]==-1)
         {numLeaf++;} 
        ind2+=1;
    }
    
    Flag0=tree[0][4];//check start node (root color)
    Flag1=checkPath(tree,num_rows,numLeaf);//check if the number of black nodes of all paths is equal
    Flag2=check_for_balancing(tree,num_rows);//check balancing
    Flag3=check_for_node_colors(tree,num_rows);//check color 
    if(Flag0==0||Flag1==0||Flag2==0||Flag3==0)cout<<0;//check hole flags
    else cout<<1;
    
    return 0;
}
