#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size(), n = heightMap[0].size();
        if (m <= 2 || n <= 2) return 0; // no room
        vector<vector<int>> visited(m, vector<int>(n, 0));
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        for (int i = 0; i < m; ++i) {
            pq.push({heightMap[i][0], i, 0});
            pq.push({heightMap[i][n-1], i, n-1});
            visited[i][0] = visited[i][n-1] = 1;
        }
        for (int j = 0; j < n; ++j) {
            pq.push({heightMap[0][j], 0, j});
            pq.push({heightMap[m-1][j], m-1, j});
            visited[0][j] = visited[m-1][j] = 1;
        }
        int res = 0;
        vector<int> dirs = {1,0,-1,0,1};
        while (!pq.empty()) {
            auto cur = pq.top(); pq.pop();
            int h = cur[0], x = cur[1], y = cur[2];
            for (int k = 0; k < 4; ++k) {
                int nx = x + dirs[k], ny = y + dirs[k+1];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n || visited[nx][ny]) continue;
                visited[nx][ny] = 1;
                if (heightMap[nx][ny] < h) { // if neighbor is lower, water is trapped
                    res += h - heightMap[nx][ny];
                }
                pq.push({max(heightMap[nx][ny], h), nx, ny}); // update boundary height
            }
        }
        return res;
    }
};
