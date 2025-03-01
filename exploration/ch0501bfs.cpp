#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <queue>
#include <stack>

using namespace std;


int dx[] = { -1, 1, 0, 0 }; // 상, 하, 좌, 우
int dy[] = { 0, 0, -1, 1 };

int bfs(vector<vector<int>>& grid) {
    int N = grid.size();
    int M = grid[0].size();
    vector<vector<int>> dist(N, vector<int>(M, -1));
    queue<pair<int, int>> q;

    q.push({ 0, 0 });
    dist[0][0] = 1;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (x == N - 1 && y == M - 1)
            return dist[x][y]; // 도착하면 최단 거리 반환

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && ny >= 0 && nx < N && ny < M && grid[nx][ny] == 1 && dist[nx][ny] == -1) {
                q.push({ nx, ny });
                dist[nx][ny] = dist[x][y] + 1;
            }
        }
    }
    return -1; // 도착 불가능
}

int main() {
    vector<vector<int>> grid = {
        {1, 1, 0, 1, 1},
        {1, 0, 0, 1, 1},
        {1, 1, 1, 1, 0},
        {0, 0, 0, 1, 0},
        {1, 1, 1, 1, 1}
    };

    cout << "최단 거리: " << bfs(grid) << endl;
    return 0;
}