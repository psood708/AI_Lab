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

