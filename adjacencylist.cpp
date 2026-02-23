#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;
void adjlistingweighteddirected(){
   int edges ,vertex ;
cin >> edges >> vertex ;
    vector<vector<pair<int>>> adjlist(vertex+1);
    // Input edges
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        adjlist[u].push_back(v);      // directed
        adjlist[v].push_back(u);   // uncomment for undirected
    } 
}
int main(){
int edges ,vertex ;
cin >> edges >> vertex ;
vector<int>adjlist;
    vector<vector<int>>adjlist(vertex);
    // Input edges
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        adjlist[u].push_back(v);      // directed
        adjlist[v].push_back(u);   // uncomment for undirected
    }

    // Print adjacency list
    for (int i = 1; i < vertex; i++) {
        cout << i << " -> ";
        for (int v : adjlist[i]) {
            cout << v << " ";
        }
        cout << endl;
    }
return 0;
}