#include<iostream>
#include<vector>
#include<cmath>

using namespace std;
//The problem can be solved by using DFS or BFS (graph oriented)
struct Cow {
    int x, y, p;
    vector<int> adj; // adjascent cows are the reachable cows from this cow
};

int main(){
    int  N;
    cin >> N;
    vector<Cow> cows(N);
    for(int i = 0; i < N; i++){
        cin >> cows[i].x >> cows[i].y >> cows[i].p;
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(i == j) continue;
            int dx = cows[i].x - cows[j].x;
            int dy = cows[i].y - cows[j].y;
            int dist = dx*dx + dy*dy;
            if(dist <= cows[i].p * cows[i].p){
                cows[i].adj.push_back(j);
            }
        }
    }
    // Reachability ---> Apply DFS (here iterative DFS is used, but recursive DFS can also be used)
    int maxCows = 0;
    for(int i=0; i<N; i++){
        vector<bool> visited(N, false);
        vector<int> q;
        q.push_back(i);
        visited[i] = true;
        int count = 0;
        while(!q.empty()){
            int cur = q.back();
            q.pop_back();
            count++;
            for(int j=0; j<cows[cur].adj.size(); j++){
                int next = cows[cur].adj[j];
                if(!visited[next]){
                    visited[next] = true;
                    q.push_back(next);
                }
            }
        }
        maxCows = max(maxCows, count);

    }
    cout << maxCows << endl;

}