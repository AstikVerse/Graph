class Solution {
    private:
bool dfs(int node,vector<vector<int>>&adjlist,vector<int>&visited,int destination){
 if(node==destination){
    return true;
 }
 visited[node]=1;
 for(auto adjNode: adjlist[node]){
    if(!visited[adjNode]){
 if(dfs(adjNode,adjlist,visited,destination)){
        return true;
    }
    }
 }
 return false;
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>>adjlist(n);
        for(int i =0 ;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adjlist[u].push_back(v);
            adjlist[v].push_back(u);
        }
        vector<int>visited(n,0);
        return dfs(source,adjlist,visited,destination);
    }
};