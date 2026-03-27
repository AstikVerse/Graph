#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;
int main(){
int m,n;
cin>> n>> m;
vector<vector<char>>mat;
for(int i =0;i<n;i++){
    for(int j =0;j<m;j++){
        cin>> mat[i][j];
    }
}
vector<vector<int>>adjlist(n);

return 0;
}