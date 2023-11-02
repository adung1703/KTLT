// Nguyen Huu Dung - 20215545
// #include <iostream>
// #include <queue>
// #include <climits>
// using namespace std;

vector<int> dijkstra(const vector< vector< pair<int, int> > >&adj) {
    //# Nguyen Huu Dung - 20215545 #
    int n = adj.size(); // So dinh trong do thi
    vector<int> dist(n, INT_MAX); // Luu tru khoang cach tu dinh 0 den dinh khac, ban dau bang vo cung
    vector<bool> visited(n, false); // Danh dau nhung dinh da duyet, ban dau tat ca deu chua duyet

    // Dinh co khoang cach nho nhat se duoc cua vao hang doi
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[0] = 0; // Dinh 0 la dinh xuat phat
    pq.push(make_pair(0, 0)); 

	// Duyet tung dinh trong hang doi
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        visited[u] = true;

        //Duyet nhung dinh chua duoc duyet
        for (const auto& nei : adj[u]) {
            int v = nei.first;
            int weight = nei.second;

            // Neu co duong di ngan hon den dinh v, cho vao hang doi
            if (!visited[v] && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    return dist;
}

// int main() {
//     int n = 9;
//     vector< vector< pair<int, int> > > adj(n);
//     auto add_edge = [&adj] (int u, int v, int w) {
//         adj[u].push_back({v, w});
//         adj[v].push_back({u, w});
//     };

//     add_edge(0, 1, 4);
//     add_edge(0, 7, 8);
//     add_edge(1, 7, 11);
//     add_edge(1, 2, 8);
//     add_edge(2, 3, 7);
//     add_edge(2, 8, 2);
//     add_edge(3, 4, 9);
//     add_edge(3, 5, 14);
//     add_edge(4, 5, 10);
//     add_edge(5, 6, 2);
//     add_edge(6, 7, 1);
//     add_edge(6, 8, 6);
//     add_edge(7, 8, 7);

//     vector<int> distance = dijkstra(adj);
//     for (int i = 0; i < distance.size(); ++i) {
//         cout << "distance " << 0 << "->" << i << " = " << distance[i] << endl;
//     }

//     return 0;
// } //Nguyen Huu Dung - 20215545
