#include <cstdio>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

//constants
const int NB_NODES_MAX = 1000;
const int NB_EDGE_MAX = 1000;
const int INF = 2000;


//declare a vector of triplets (node, cost, flow)
typedef struct Pipe {
    int to;
    int cost;
    int flow;
} Pipe;

vector<Pipe> graph[NB_NODES_MAX + 1];

//read the graph
void readGraph(int &nbNodes, int &nbEdges) {
    scanf("%d %d",&nbNodes,&nbEdges);
    for(int i = 0 ; i < nbEdges ; i++) {
        int a,b,f,c;
        scanf("%d %d %d %d",&a,&b,&f,&c);
        graph[a].push_back({b,f,c}); //add the edge a->b with flow f and cost c
        graph[b].push_back({a,f,c}); //add the edge b->a with flow f and cost c
    }
}

// DFS function to find all paths from node `current' to node `end`
void dfs(int current, int end, vector<int> &path, vector<vector<int>> &allPaths, vector<bool> &visited) {
    visited[current] = true;
    path.push_back(current);

    if (current == end) {
        allPaths.push_back(path);
    } else {
        for (const auto &pipe : graph[current]) {
            if (!visited[pipe.to]) {
                dfs(pipe.to, end, path, allPaths, visited);
            }
        }
    }
    // If we are here, it means that the current node is not part of the path.
    path.pop_back();
    visited[current] = false;
}

int main() {
    int n,m;
    readGraph(n,m);
/*
    printf("%d %d\n",n,m);

    printf("Graph:\n");
    for(int i = 1 ; i <= n ; i++) {
        printf("%d: ",i);
        for(auto p : graph[i]) {
            printf("(%d,%d,%d) ",p.to,p.flow,p.cost);
        }
        printf("\n");
    }
*/
    // Find all paths fromjunction 1 to junction n
    vector<vector<int>> allPaths;
    vector<int> path;
    vector<bool> visited(n + 1, false);
    dfs(1, n, path, allPaths, visited);

    // Now we select the path with the maximum flow/cost 
    double max_ratio = 0;
    for (auto &path : allPaths) {
        int min_flow = INF;
        int cost = 0;
        for (int i = 0; i < path.size() - 1; i++) {
            for (const auto &pipe : graph[path[i]]) {
                if (pipe.to == path[i + 1]) {
                    min_flow = min(min_flow, pipe.flow);
                    cost += pipe.cost;
                    break;
                }
            }
        }

        max_ratio = max(max_ratio, static_cast<double>(min_flow) / static_cast<double>(cost));
    }


    //print the path
    /*
    printf("Paths:\n");
    for (auto &path : allPaths) {
        for (auto &node : path) {
            printf("--->%d", node);
        }
        printf("\n");
    }*/

    // Print the final ratio
    printf("%lld\n", static_cast<long long>(max_ratio * 1e6));





    return 0;
}
