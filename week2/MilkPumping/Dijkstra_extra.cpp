#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// Constants
const int NB_NODES_MAX = 1000;
const int INF = 1000000;

// Structure to represent an edge (or pipe)
struct Pipe {
    int to;
    int cost;
    int flow;
};

vector<Pipe> graph[NB_NODES_MAX + 1];

// Structure to represent a state in the priority queue
struct State {
    int node;
    int minFlow;
    int totalCost;
    double ratio;
    bool operator<(const State& other) const {
        return ratio < other.ratio; // We want the max ratio, so use less than operator
    }
};

//read the graph
void readGraph(int &nbNodes, int &nbEdges) {
    scanf("%d %d", &nbNodes, &nbEdges);
    for(int i = 0; i < nbEdges; i++) {
        int a, b, f, c;
        scanf("%d %d %d %d", &a, &b, &c, &f);
        graph[a].push_back({b, c, f});
        graph[b].push_back({a, c, f});
    }
}

double findMaxFlowCostRatio(int start, int end, int n) {
    priority_queue<State> pq;
    vector<int> maxFlow(n + 1, 0);
    vector<int> minCost(n + 1, INF);

    pq.push({start, INF, 0, numeric_limits<double>::max()});

    while (!pq.empty()) {
        State current = pq.top();
        pq.pop();

        if (current.node == end) {
            return static_cast<double>(current.minFlow) / current.totalCost;
        }

        for (const auto& pipe : graph[current.node]) {
            int newMinFlow = min(current.minFlow, pipe.flow);
            int newTotalCost = current.totalCost + pipe.cost;

            double newRatio = static_cast<double>(newMinFlow) / newTotalCost;
            if (newMinFlow > maxFlow[pipe.to] || (newMinFlow == maxFlow[pipe.to] && newTotalCost < minCost[pipe.to])) {
                maxFlow[pipe.to] = newMinFlow;
                minCost[pipe.to] = newTotalCost;
                pq.push({pipe.to, newMinFlow, newTotalCost, newRatio});
            }
        }
    }
    return 0.0; // In case there's no path from start to end but normally it always exists
}



int main() {
    int n, m;
    readGraph(n, m);

    // Find the maximum flow/cost ratio from junction 1 to junction n
    double max_ratio = findMaxFlowCostRatio(1, n, n);

    // Print the final ratio scaled by 1e6
    printf("%lld\n", static_cast<long long>(max_ratio * 1e6));

    return 0;
}
