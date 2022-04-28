int dx[4] = {0, 0, -1, 1};
    int dy[4] = {1, -1, 0, 0};

    bool isvalid(int x, int y, int n, int mid)
    {
        return (x >= 0 && x < n && y >= 0 && y < mid);
    }
    bool bfs(vector<vector<int>> heights, int k)
    {
        queue<pair<int, int>> q;
        q.push({0, 0});
        vector<vector<bool>> visited(101, vector<bool>(101, false));
        visited[0][0] = 1;

        while (!q.empty())
        {
            pair<int, int> curr = q.front();
            q.pop();
            int cx = curr.first;
            int cy = curr.second;
            if (cx == heights.size() - 1 && cy == heights[0].size() - 1)
                return true;
            for (int i = 0; i < 4; i++)
            {
                int x = dx[i] + cx;
                int y = dy[i] + cy;
               
                if (isvalid(x, y, heights.size(), heights[0].size()) && !visited[x][y])
                {
                    if (abs(heights[cx][cy] - heights[x][y]) <= k)
                    {
                        visited[x][y] = true;
                        q.push({x, y});
                    }
                }
            }
        }
        return false;
    }

    int minimumEffortPath(vector<vector<int>>& heights) {
        int low = 0;
        int high = 1e6;
        int ans = -1;


        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            
            if (bfs(heights, mid))
            {
                
                ans = mid;
                high = mid - 1;
    
            }
            else
            {
                low = mid + 1;
                
            }
        }
        return ans;
    }