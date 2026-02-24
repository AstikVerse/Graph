#include<iostream>
#include<vector>
#include<queue>
#include<climits>
#include<algorithm>
using namespace std;
//Time Complexity:0(V+2E)
//Space Complexity: 0(V+V)
vector<int>bfs(vector<vector<int>>&adjlist,int v){
    queue<int>q;
    vector<int>ans;
    vector<bool>visited(v,0);
    q.push(0);
    visited[0]=1;
    while(!q.empty()){
 int node = q.front();
        q.pop();
        ans.push_back(node);
      for(int j =0;j<adjlist[node].size();j++){
        if(!visited[adjlist[node][j]]){
            q.push(adjlist[node][j]);
            visited[adjlist[node][j]]=1;
        }
    }
       
      }
      return ans;
    }

int main(){
int edges,vertex;
cin>>edges>>vertex;
vector<vector<int>>adjlist(vertex);
int u,v;
for(int i=0;i<edges;i++){
    cin>> u >> v;
    adjlist[u].push_back(v);
     adjlist[v].push_back(u);   
}
vector<int>org= bfs(adjlist,vertex);
for(int i =0;i<org.size();i++){
    cout<< org[i];
}
return 0;
}