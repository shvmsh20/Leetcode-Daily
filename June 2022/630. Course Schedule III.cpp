static bool cmp(vector<int> &a, vector<int> &b){
        if(a[1]!=b[1]){
            return a[1]<b[1];
        }
        return a[0]<b[0];
    }
    int scheduleCourse(vector<vector<int>>& courses) {
        int n = courses.size();
        int curr=0, count=0;
        sort(courses.begin(), courses.end(), cmp);
        priority_queue<int> pq;
        for(int i=0; i<n; i++){
            vector<int> v = courses[i];
            
            if(curr+v[0]<=v[1]){
                count++;
                curr = curr+v[0];
                pq.push(v[0]);
            }else if(!pq.empty() && pq.top()>=v[0] && curr-pq.top()+v[0]<=v[1]){
                int d = pq.top();
                pq.pop();
                pq.push(v[0]);
                curr = curr-d+v[0];
                }
            }
        
        return count;
    }


//Better written
static bool cmp(vector<int> &a, vector<int> &b){
        if(a[1]!=b[1]){
            return a[1]<b[1];
        }
        return a[0]<b[0];
    }
    int scheduleCourse(vector<vector<int>>& courses) {
        int n = courses.size();
        int curr=0;
        sort(courses.begin(), courses.end(), cmp);
        priority_queue<int> pq;
        for(int i=0; i<n; i++){
            vector<int> v = courses[i];
            
            if(curr+v[0]<=v[1]){
                curr = curr+v[0];
                pq.push(v[0]);
            }else if(!pq.empty() && pq.top()>v[0]){
                // no need to check curr-pq.top()-v[0]<=v[1] becoz
                // we are replacing a larger duration with smaller duration course
                // so it always remains inside or on deadline
                int d = pq.top();
                pq.pop();
                pq.push(v[0]);
                curr = curr-d+v[0];
                }
            }
        
        return pq.size();
    }    