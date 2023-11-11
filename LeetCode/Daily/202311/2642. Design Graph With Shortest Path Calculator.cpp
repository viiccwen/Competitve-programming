#define pii pair<int ,int>
class Graph {
public:
    vector<vector<pii>> adList;
    Graph(int n, vector<vector<int>>& edges) {
        adList.resize(n);

        for(auto edge : edges) adList[edge[0]].emplace_back(edge[1], edge[2]);
    }
    
    void addEdge(vector<int> edge) {
        adList[edge[0]].emplace_back(edge[1], edge[2]);
    }
    
    int shortestPath(int node1, int node2) {
        return dijkstra(node1, node2);
    }

private:
    int dijkstra(int start, int end) {
        int n = adList.size();
        vector<int> dis(n, INT_MAX);
        dis[start] = 0;

        priority_queue<pii, vector<pii>, greater<>> pq;
        pq.push({0, start});

        while(!pq.empty()) {
            int cost = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(cost > dis[node]) continue;

            if(node == end) return cost;

            for(auto edge : adList[node]) {
                int neighbor = edge.first;
                int edgeLen = edge.second;
                int newCost = edgeLen + dis[node];

                if(dis[neighbor] > newCost) {
                    dis[neighbor] = newCost;
                    pq.push({newCost, neighbor});
                }
            }

        }
        
        return (dis[end] == INT_MAX) ? -1 : dis[end];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */