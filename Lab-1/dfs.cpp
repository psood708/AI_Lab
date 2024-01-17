#include<bits/stdc++.h>
using namespace std;

void addEdge(map<int, vector<int>>& adj, int v, int w) {
    adj[v].push_back(w);
}

void DFS(map<int, bool>& visited, const map<int, vector<int>>& adj, int v) {
    visited[v] = true;
    cout << v << " ";

    for (int i : adj.at(v)) {
        if (!visited[i]) {
            DFS(visited, adj, i);
        }
    }
}

int main() {
    map<int, vector<int>> adj;
    map<int, bool> visited;

    // Create a graph given in the above diagram
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 3, 7);
    addEdge(adj, 2, 5);
    addEdge(adj, 2, 6);
    addEdge(adj, 5, 8);

    cout << "Following is Depth First Traversal (starting from vertex 2) \n";

    // Function call
    DFS(visited, adj, 0);

    return 0;
}
