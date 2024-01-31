#include<bits/stdc++.h>
using namespace std;
const int maxA = 5;
const int maxB = 4;

void emptyA(pair<int,int> state){
    state.first = 0;
}
void emptyB(pair<int,int> state){
    state.second = 0;
}
void fillA(pair<int,int> state){
    state.first = maxA;
}
void fillB(pair<int,int> state){
    state.second = maxB;
}
// here we fill A from B
void fillAB(pair<int,int> state){
    int req = maxA - state.first;
    if(state.second > req){
        state.first = maxA;
        state.second -= req;
    }
    else{
        state.first+=state.second;
        state.second = 0;
    }
   
}
// here we filll B from A
void fillBA(pair<int,int> state){
     int req = maxB - state.second;
    if(state.first > req){
        state.second = maxB;
        state.first -= req;
    }
    else{
        state.second+=state.first;
        state.first = 0;
    }
}

bool isGoal(pair<int,int> state, pair<int,int> target){
    return state.first == target.first && state.second == target.second;
}
void printPath(const vector<pair<int, int>> &path) {
    for (const auto &state : path) {
        cout << "(" << state.first << ", " << state.second << ") ";
    }
    cout << endl;
}

void BFS_waterjug(pair<int,int> target){
    queue<vector<pair<int,int>>> q;
    set<pair<int,int>> visited;

    q.push({{0,0}});
    visited.insert({0,0});

    while (!q.empty()) {
        vector<pair<int, int>> currentPath = q.front();
        q.pop();
        pair<int, int> currentState = currentPath.back();

        if (isGoal(currentState, target)) {
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

    cout << "Path not found to reach "<< target.first<< " "<< target.second << " liters." << endl;


}
int main() {
    pair<int,int> target = {2,0};
    BFS_waterjug(target);
    return 0;
}
// void waterJug(vector<vector<pair<int,int>>> &a_list, pair<int,int> start, pair<int,int> target){
//     visited[]
//     queue <pair<int,int>> q;
//     q.push(start);
//     while(!q.empty()){
//         pair<int,int> curr = q.front();
//         q.pop();
//         // base case
//         if(curr == target)
//         return ;
//         // all possible moves for current state
//         fillA(curr);
//         fillB(curr);
//         fillAB(curr);
//         fillBA(curr);
//         // add the new states to the list of valid states
//         a_list[curr.first][curr.second] = true;
//         // push the new states in the Q only if they are not already present in the Q or
//         // have been visited more than once
       
// }