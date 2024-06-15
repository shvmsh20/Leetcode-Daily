int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int, int>> projects;
        int n = profits.size();
        for(int i=0; i<n; i++){
            projects.push_back({capital[i], profits[i]});
        }
        sort(projects.begin(), projects.end());
        priority_queue<int> pq;
        int i=0;
        while(k){
            while(i<n && w>=projects[i].first){
                pq.push(projects[i].second);
                i++;
            }
            if(pq.empty()){
                break;
            }
            int mxProfit = pq.top();
            pq.pop();
            w+= mxProfit;
            k--;
        }
        return w;
    }