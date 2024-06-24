#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<climits>

using namespace std;
const int MaxVertices = 500*500;
const int INF = INT_MAX;

map<pair<int,int>, pair<int,int>> Dijkstra(vector<string> grid, int C, int R, pair<int,int> rabbit, pair<int,int> destination){
    vector<pair<int,int>> directions = {{0,1},{0,-1},{1,0},{-1,0}};
    map<pair<int,int>, pair<int,int>> previous;
    map<pair<int,int>, int> distance;
    vector <pair<int,int>> not_visited;

    // put all vertices in the not_visited list
    for(int i = 0 ; i < grid.size() ; i++) {
        for(int j = 0 ; j < grid[i].size() ; j++) {
            not_visited.push_back({i,j});
            distance[{i,j}] = INF;
            previous[{i,j}] = {-1,-1};
        }
    }

    // set the distance of the rabbit to 0
    distance[rabbit] = 0;

    // while there are still vertices to visit
    while(not_visited.size() > 0){
        // find the vertex with the smallest distance
        pair<int,int> u = not_visited[0];
        for(auto v : not_visited){
            if(distance[v] < distance[u]){
                u = v;
            }
        }
        // remove the vertex from the not_visited list
        not_visited.erase(remove(not_visited.begin(), not_visited.end(), u), not_visited.end());

        // if the vertex is the destination, we are done
        if(u == destination){
            break;
        }

        // for each neighbor of the vertex, we have 4 neighbors: up, down, left, right
        for(auto d : directions){
            pair<int,int> v = {u.first + d.first, u.second + d.second};
            // if the neighbor is not in the grid, skip it
            if(v.first < 0 || v.first >= R || v.second < 0 || v.second >= C){
                continue;
            }
            // if the neighbor is a wall, skip it
            if(grid[v.first][v.second] == '#'){
                continue;
            }
            // if the neighbor is not visited, skip it
            if(find(not_visited.begin(), not_visited.end(), v) == not_visited.end()){
                continue;
            }
            // if the distance to the neighbor is smaller than the current distance, update the distance
            if(distance[u] + 1 < distance[v]){
                distance[v] = distance[u] + 1;
                previous[v] = u;
            }
        }
    }
    return previous;

}
int main()
{
    vector<string> grid;
    pair<int, int> rabbit, destination; 
    map<pair<int,int>, pair<int,int>> previous;
    map<pair<int,int>, int> distance;

    int R, C;
    scanf("%d %d",&C,&R);

    bool R_found = false;
    bool D_found = false;

    for(int i = 0 ; i < R ; i++) {
        string s; // s = row i
        cin >> s;
        grid.push_back(s);
        if (!R_found || !D_found){
            for(int j = 0 ; j < C ; j++) {
                // Check if the vertex is a rabbit
                if(s[j] == 'R') {
                    rabbit = {i,j};
                    R_found = true;
                }
                // Check if the vertex is a destination
                if(s[j] == 'D') {
                    destination = {i,j};
                    D_found = true;
                }
                
            }
        }
    }
    previous = Dijkstra(grid, C, R, rabbit, destination);

    string path = "";
    if(previous[destination] == make_pair(-1,-1)){
        printf("No path found\n");
    } else {
        pair<int,int> current = destination;
        while(current != rabbit){
            // Return the path in the form of a string : RRRDDDUUUDDDLLL
            if(previous[current].first == current.first){
                if(previous[current].second < current.second){
                    path = "R" + path;
                } else {
                    path = "L" + path;
                }
            } else {
                if(previous[current].first < current.first){
                    path = "D" + path;
                } else {
                    path = "U" + path;
                }
            }
            current = previous[current];
        }
    }
    printf("%s\n",path.c_str());
    
    return 0;
}