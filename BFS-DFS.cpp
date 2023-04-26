#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

// Graph adjacency list
vector<vector<int>> graph = {
    {1, 2},     // Node 0 is connected to nodes 1 and 2
    {3, 4},     // Node 1 is connected to nodes 3 and 4
    {5},        // Node 2 is connected to node 5
    {},         // Node 3 has no neighbors
    {5},        // Node 4 is connected to node 5
    {}          // Node 5 has no neighbors
};

// Breadth-First Search
void bfs(int start) {
    queue<int> q;
    set<int> visited;

    q.push(start);
    visited.insert(start);

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        cout << current << " ";

        for (int neighbor : graph[current]) {
            if (visited.find(neighbor) == visited.end()) {
                q.push(neighbor);
                visited.insert(neighbor);
            }
        }
    }
    cout << endl;
}

// Depth-First Search
void dfs(int node, set<int>& visited) {
    cout << node << " ";
    visited.insert(node);

    for (int neighbor : graph[node]) {
        if (visited.find(neighbor) == visited.end()) {
            dfs(neighbor, visited);
        }
    }
}

int main() {
    cout << "BFS: ";
    bfs(0);
    
    cout << "DFS: ";
    set<int> visited;
    dfs(0, visited);
    cout << endl;

    return 0;
}
