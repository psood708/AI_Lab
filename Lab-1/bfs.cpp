 // [ ] (visited)// [ ] (queue)
#include<bits/stdc++.h>
using namespace std;


vector<int> bfs(vector<vector<int>> &aList , int start,int target = -1){
    int n = aList.size();
    // we also need to create an adjacency list
    vector<bool> visited(n,false);
    //traversal order
    vector<int> orderList;
    queue<int> q;
    q.push(start);
    visited[start]=true;
    while(!q.empty()){
        int nxt = q.front();
        q.pop();
        orderList.push_back(nxt);
        for(auto i : aList[nxt]){
            if(!visited[i]){
                q.push(i);
                visited[i] = true;
            }
        }
    }
    if (target!=-1 && visited[target]==false){
        return {};
    }
    return orderList;
}

int main(){
    vector<vector<int>> adj_list = {
        {7,4,1},
        {8},
        {},
        {},
        {},
        {9,6},
        {},
        {5,3,2},
        {},
        {}
    };
    vector<int> order =bfs(adj_list,0);
    cout<<"BFS Traversal Order: ";
       for (auto i : order)  
    {  
        cout << i << " ";  
    }  
    cout << endl;  
  
    return 0;  
}

//////////////////////////////////////////


#include <bits/stdc++.h>
using namespace std;

const int maxA = 5;
const int maxB = 4;

void emptyA(pair<int, int> &state) {
    state.first = 0;
}

void emptyB(pair<int, int> &state) {
    state.second = 0;
}

void fillA(pair<int, int> &state) {
    state.first = maxA;
}

void fillB(pair<int, int> &state) {
    state.second = maxB;
}

void fillAB(pair<int, int> &state) {
    int req = maxA - state.first;
    if (state.second > req) {
        state.first = maxA;
        state.second -= req;
    } else {
        state.first += state.second;
        state.second = 0;
    }
}

void fillBA(pair<int, int> &state) {
    int req = maxB - state.second;
    if (state.first > req) {
        state.second = maxB;
        state.first -= req;
    } else {
        state.second += state.first;
        state.first = 0;
    }
}

bool isGoalState(pair<int, int> state, int target) {
    return state.first == target || state.second == target;
}

void printPath(const vector<pair<int, int>> &path) {
    for (const auto &state : path) {
        cout << "(" << state.first << ", " << state.second << ") ";
    }
    cout << endl;
}

void BFS_WaterJugProblem(int target) {
    queue<vector<pair<int, int>>> q;
    set<pair<int, int>> visited;

    q.push({{0, 0}});
    visited.insert({0, 0});

    while (!q.empty()) {
        vector<pair<int, int>> currentPath = q.front();
        q.pop();
        pair<int, int> currentState = currentPath.back();

        if (isGoalState(currentState, target)) {
            cout << "Path to reach " << target << " liters: ";
            printPath(currentPath);
            return;
        }

        // Generate all possible next states
        vector<pair<int, int>> nextStates = {
            currentState, currentState, currentState, currentState, currentState, currentState};

        emptyA(nextStates[0]);
        emptyB(nextStates[1]);
        fillA(nextStates[2]);
        fillB(nextStates[3]);
        fillAB(nextStates[4]);
        fillBA(nextStates[5]);

        for (const auto &nextState : nextStates) {
            if (visited.find(nextState) == visited.end()) {
                vector<pair<int, int>> newPath = currentPath;
                newPath.push_back(nextState);
                q.push(newPath);
                visited.insert(nextState);
            }
        }
    }

    cout << "Path not found to reach " << target << " liters." << endl;
}

int main() {
    int target;
    cout << "Enter the target amount to measure: ";
    cin >> target;

    BFS_WaterJugProblem(target);

    return 0;
}
