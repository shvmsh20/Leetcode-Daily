queue<int> q;
    
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
        int itr = q.size()-1;
        while(itr--){
            q.push(q.front());
            q.pop();
        }
            
    }
    
    int pop() {
      int ans  = q.front();
        q.pop();
        return ans;
    }
    
    int top() {
        if(q.empty()){
            return -1;
        }
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }