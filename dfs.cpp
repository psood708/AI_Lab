#include<bits/stdc++.h>
using namespace std;

class Graph {
public:
    int vertices;
    vector<vector<char>> adjacencyList;

    Graph(int v) {
        vertices = v;
        adjacencyList.resize(vertices);
    }

    void addEdge(char u, char v) {
        adjacencyList[u - 'A'].push_back(v);
        adjacencyList[v - 'A'].push_back(u);  // For undirected graph
    }

    void DFS(char startVertex) {
        vector<bool> visited(vertices, false);
        vector<char> traversalOrder;  // To store the traversal order
        stack<char> s;

        s.push(startVertex);

        while (!s.empty()) {
            char currentVertex = s.top();
            s.pop();

            if (!visited[currentVertex - 'A']) {
                cout << currentVertex << " ";
                traversalOrder.push_back(currentVertex);
                visited[currentVertex - 'A'] = true;
            }

            for (char neighbor : adjacencyList[currentVertex - 'A']) {
                if (!visited[neighbor - 'A']) {
                    s.push(neighbor);
                }
            }
        }

        cout << "\nTraversal Order: ";
        for (char vertex : traversalOrder) {
            cout << vertex << " ";
        }
    }
};

int main() {
    // Example Usage
    Graph g(11);
    g.addEdge('S', 'A');
    g.addEdge('S', 'H');
    g.addEdge('A', 'B');
    g.addEdge('A', 'C');
    g.addEdge('H', 'I');
    g.addEdge('H', 'J');
    g.addEdge('B', 'D');
    g.addEdge('B', 'E');
    g.addEdge('C', 'G');
    g.addEdge('I', 'K');

    cout << "Depth-First Search starting from vertex 'S': ";
    g.DFS('S');

    return 0;
}
