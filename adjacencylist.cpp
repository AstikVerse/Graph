#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;
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