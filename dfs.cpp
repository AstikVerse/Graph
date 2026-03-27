#include<iostream>
#include<vector>
#include<stack>
#include<climits>
#include<algorithm>
using namespace std;
void dfs(int node,vector<int>&ans,vector<int>&visited,vector<vector<int>>&adjlist){
visited[node]=1;
ans.push_back(node);
for(int i =0;i<adjlist[node].size();i++){
    if(!visited[adjlist[node][i]]){
        dfs(adjlist[node][i],ans,visited,adjlist);
    }
}
}

int main(){
    int edges ,vertex ;
cin >> edges >> vertex ;
    vector<vector<int>>adjlist(vertex);
    // Input edges
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        adjlist[u].push_back(v);
    }
vector<int>visited;
vector<int>ans;
dfs(0,ans,visited,adjlist);
stack<int>s;
visited[0]=1;
s.push(0);
while(!s.empty()){
int node = s.top();
s.pop();
ans.push_back(node);

}
return 0;
}