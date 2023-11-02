//Nguyen Huu Dung - 20215545
#include <iostream>
#include <vector>

using namespace std;
//Thuat toan duyet do thi theo chieu sau
void dfs(const vector<vector<int>>& graph, int current, int length, int k, int& count, vector<bool>& visited) {
//graph la ma tran ke, current la dinh bat dau, length la chieu dai duong di, count dem so canh, visited danh dau dinh da tham

    visited[current] = true; //dinh hien tai da tham 

    if (length == k) { //Neu duong di da co k canh
        count++; //Tang bien dem len
    }
    else if (length < k) { //Neu duong di co it hon k canh
        for (int neighbor : graph[current]) { //Duyet cac dinh ke voi dinh hien tai
            if (!visited[neighbor]) {
                dfs(graph, neighbor, length + 1, k, count, visited);
            }
        }
    }

    visited[current] = false; //Sau khi duyet xong thi dua ve trang thai cu
} //Ham dfs se thay doi bien count tra ve so duong di chieu dai k bat dau tu dinh current

//Dem so duong di
int countPaths(const vector<vector<int>>& graph, int n, int k) { 
    int count = 0;
    vector<bool> visited(n + 1, false);

    for (int start = 1; start <= n; ++start) {
        dfs(graph, start, 0, k, count, visited); //Duyet dfs tung dinh mot
    }

    return count;
}

int main() {
    int n, k;
    cout << "Input: " << endl;
    cin >> n >> k;

    vector<vector<int>> graph(n + 1); 

    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v); //Chua cac dinh ke voi u
        graph[v].push_back(u); //Chua cac dinh ke voi v
    }

    int result = countPaths(graph, n, k)/2; //Do do thi la vo huong nen moi duong di da bi xet 2 lan
    cout << "Output: \n" << result << endl;

    return 0;
} //Nguyen Huu Dung - 20215545

