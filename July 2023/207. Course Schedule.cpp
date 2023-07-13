bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> dep(numCourses);
        vector<vector<int>> graph(numCourses);
        for(auto x: prerequisites){
            dep[x[0]]++;
            graph[x[1]].push_back(x[0]);
        }
        queue<int> q;
        int n = 0;
        for(int i=0; i<numCourses; i++){
            if(dep[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int sz = q.size();
            for(int i=0; i<sz; i++){
                int node = q.front();
                n++;
                q.pop();
                for(int y: graph[node]){
                    dep[y]--;
                    if(dep[y]==0){
                        q.push(y);
                    }
                }

            }
        }
        return n==numCourses;
    }