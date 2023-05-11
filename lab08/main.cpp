#include <iostream>
#define INF 1e6
using namespace std;

int main() {
    int n, m;
    cout << "Enter the number of points and ways : ";
    cin >> n >> m;
    int adj[n + 1][m + 1];
    for (int i = 0; i < n + 1; ++i)
        for (int j = 0; j < m + 1; ++j) adj[i][j] = INF;

    cout << "Enter the information about ways:\nstart point, end point, weight:\n";
    for (int i = 1; i <= m; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a][b] = w;
        adj[b][a] = w;
    }
    for (int i = 1; i <= n; ++i) {
        adj[i][i] = 0;
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (int k = 1; k <= n; ++k) {
                adj[j][k] = min(adj[j][k], adj[i][j] + adj[i][k]);
                adj[k][j] = adj[j][k];
            }
        }
    }

    for (int i = 1; i < n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            cout << "Length of shortest path betwen nodes " << i << " and " << j << " is equal to " << adj[i][j]
                 << endl;
        }
    }
}