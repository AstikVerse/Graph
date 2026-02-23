#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;
int main(){
int edges, vertex;
cin>>edges >> vertex;
vector<vector<int>>adjmatrix(vertex,vector<int>(vertex,0));
//for undirected unweighted
for(int i = 0;i<edges;i++){
    int u,v;
cin >> u >> v ;
adjmatrix[u][v]=1;
adjmatrix[v][u] =1;
}
//for directed unweighted
for(int i = 0;i<edges;i++){
    int u,v ;
cin >> u >> v ;
adjmatrix[u][v]= 1;
}
//for undirected weighted
for(int i =0;i<edges;i++){
    int u,v,val;
    cin>> u >> v >>val;
    adjmatrix[u][v]= val;
    adjmatrix[v][u] = val;
}
//for directed weighted
for(int i =0;i<edges;i++){
    int u,v,val;
    cin>> u >> v >>val;
    adjmatrix[u][v]= val;
}
for(int i = 0; i < adjmatrix.size();i++){
    for(int j =0;i < adjmatrix[i].size();j++){
       cout << adjmatrix[i][j]; 
    }
   cout<< endl;
}
return 0;
}