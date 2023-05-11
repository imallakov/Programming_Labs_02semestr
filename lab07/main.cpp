#include <iostream>
#include <queue>
#include <vector>

#define INF 1e9

using namespace std;

int main() {
    int n, m;
    cout << "Enter the number of points and ways : ";
    cin >> n >> m;
    vector<pair<int, int>> adj[n + 1];
    int distance[n + 1];
    int x = 1, y = 1;
    priority_queue<pair<int, int>> q;
    bool processed[n + 1];
    for (int i = 0; i < n + 1; ++i) processed[i] = false;
    cout << "Enter the information about ways:\nstart point, end point, weight:\n";
    for (int i = 1; i <= m; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].emplace_back(b, w);
        adj[b].emplace_back(a, w);
    }
    cout << "Enter the start point : ";
    cin >> x;
    cout << "Enter the end point : ";
    cin >> y;

    for (int i = 1; i <= n; i++) distance[i] = INF;
    distance[x] = 0;
    q.emplace(0, x);
    while (!q.empty()) {
        int a = q.top().second;
        q.pop();
        if (!processed[a]) {
            processed[a] = true;
            for (auto u : adj[a]) {
                int b = u.first, w = u.second;
                if (distance[a] + w < distance[b]) {
                    distance[b] = distance[a] + w;
                    q.emplace(-distance[b], b);
                }
            }
        }
    }
    cout << "Shortes path from point " << x << " to point " << y << " is equal to " << distance[y];
}

/*
5 6
1 2 5
1 5 1
1 4 9
2 3 2
3 4 6
4 5 2
 */