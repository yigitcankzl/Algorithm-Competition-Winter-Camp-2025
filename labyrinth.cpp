#include <bits/stdc++.h>
using namespace std;
 
bool validCheck(int a, int b, int m, int n) {
    return (a >= 0 && a < m && b >= 0 && b < n);
}
 
int32_t main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int m, n;
    cin >> m >> n;
    vector<vector<bool>> matrix(m, vector<bool>(n));
    int x1, y1, x2, y2;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
 
            char c;
            cin >> c;
 
            matrix[i][j] = (c != '#');
            if (c == 'A') {
                x1 = i;
                y1 = j;
            } else if (c == 'B') {
                x2 = i;
                y2 = j;
            }
        }
    }
 
    int dX[] = {1, -1, 0, 0};
    int dY[] = {0, 0, 1, -1};
    char dir[] = {'D', 'U', 'R', 'L'};
    unordered_map<char, pair<int, int>> mp;
    mp['D'] = {-1, 0};
    mp['U'] = {1, 0};
    mp['R'] = {0, -1};
    mp['L'] = {0, 1};
 
    queue<pair<int, int>> q;
    vector<vector<char>> cameFrom(m, vector<char>(n));
    vector<vector<bool>> visited(m, vector<bool>(n));
    q.push({x1, y1});
    visited[x1][y1] = true;
    while (!q.empty()) {
        int a = q.front().first;
        int b = q.front().second;
        q.pop();
        if (a == x2 && b == y2) {
            break;
        }
        for (int i = 0; i < 4; i++) {
            int nx = a + dX[i];
            int ny = b + dY[i];
            if (validCheck(nx, ny, m, n) && !visited[nx][ny] && matrix[nx][ny]) {
                q.push({nx, ny});
                visited[nx][ny] = 1;
                cameFrom[nx][ny] = dir[i];
            }
        }
    }
 
    if (!visited[x2][y2]) {
        std::cout << "NO";
        return 0;
    }
 
    int x = x2;
    int y = y2;
    string path = "";
    while (x != x1 || y != y1) {
        auto [dx, dy] = mp[cameFrom[x][y]];
        path.push_back(cameFrom[x][y]);
        x += dx;
        y += dy;
    }
 
    reverse(path.begin(), path.end());
    std::cout << "YES\n"
              << path.length() << '\n'
              << path;
    return 0;
}