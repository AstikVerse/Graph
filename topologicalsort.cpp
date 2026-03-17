#include<iostream>
#include<vector>
#include<stack>
#include<climits>
#include<algorithm>
using namespace std;
void dfs(int node,vector<int>&ans,vector<int>&visited,vector<vector<int>>&adjlist){
visited[node]=1;
for(int i =0;i<adjlist[node].size();i++){
    if(!visited[adjlist[node][i]]){
        dfs(adjlist[node][i],ans,visited,adjlist);
    }
}
ans.push_back(node);
}

int main(){
    int edges ,vertex ;
cin >> edges >> vertex ;
    vector<vector<int>>adjlist(vertex);
    vector<int>ans;
    // Input edges
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        adjlist[u].push_back(v);
    }
    vector<int>visited(vertex,0);
    for(int i=0; i<vertex;i++){
        if(!visited[i]){
            dfs(i,ans,visited,adjlist);
        }
    }
    reverse(ans.begin(),ans.end());
    for(int i =0;i<ans.size();i++){
        cout<< ans[i]<<" ";
    }
    return 0;
}