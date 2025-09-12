# Solution for Snake in Matrix in cpp
# You can copy code manually from LeetCode
class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
  int i=0,j=0,k=0;
  vector<vector<int>>arr(n,vector<int>(n,0));
  int t=0;
  for(int m=0;m<n;m++){
    for(int l=0;l<n;l++){
        arr[m][l]=t;
        t++;
    }
  }
  while(k<commands.size()){
        if(commands[k]=="RIGHT"){
       
       if(j<n-1)    j++;

       } 
        if(commands[k]=="DOWN"){
       
       if(i<n-1)    i++;
       } 
        if(commands[k]=="UP"){
       
       if(i>0)    i--;
       } 
        if(commands[k]=="LEFT"){
       
       if(j>0)    j--;
       } 
       k++;
    }
    return  arr[i][j];
    }
};
