#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool dfs(int node, vector<vector<int>> &adjlist, vector<int> &visited, vector<int> &parent, vector<int> &route)
{
    visited[node] = 1;
    for (auto adjNode : adjlist[node])
    {
        if (!visited[adjNode])
        {
            parent[adjNode] = node;
            if (dfs(adjNode, adjlist, visited, parent, route))
            {
                return true;
            }
        }
        else
        {
            if (parent[node] != adjNode)
            {
                int n = node;
                route.push_back(adjNode);
                while (n != adjNode)
                {
                    route.push_back(n);
                    n = parent[n];
                }
                route.push_back(adjNode);
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int ne, nv;
    cin >> nv >> ne;
    bool ans = false;
    vector<vector<int>> edges(ne, vector<int>(2, 0));
    for (int i = 0; i < ne; i++)
    {
        cin >> edges[i][0] >> edges[i][1];
    }
    vector<vector<int>> adjlist(nv + 1);
    for (int i = 0; i < ne; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
    vector<int> visited(nv + 1, 0);
    vector<int> parent(nv + 1, -1);
    vector<int> route;
    for (int i = 1; i < visited.size(); i++)
    {
        if (!visited[i])
        {
            if (dfs(i, adjlist, visited, parent, route))
            {
                ans = true;
                cout << route.size() << endl;
                reverse(route.begin(), route.end());
                for (int i = 0; i < route.size(); i++)
                {
                    cout << route[i] << " ";
                }
                //     cout << route[0];
                break;
            }
        }
    }
    if (!ans)
    {
        cout << "IMPOSSIBLE";
    }
    return 0;
}