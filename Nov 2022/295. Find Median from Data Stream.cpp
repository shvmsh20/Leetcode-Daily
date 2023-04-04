 priority_queue<int> mx_heap;
    priority_queue<int, vector<int>, greater<int>> mn_heap;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(mx_heap.empty()){
            mx_heap.push(num);
        }else if(mn_heap.size()==mx_heap.size()){
            if(num<=mn_heap.top()){
                mx_heap.push(num);
            }else{
                mx_heap.push(mn_heap.top());
                mn_heap.pop();
                mn_heap.push(num);
            }
        }else{
            if(num>=mx_heap.top()){
                mn_heap.push(num);
            }else{
                mn_heap.push(mx_heap.top());
                mx_heap.pop();
                mx_heap.push(num);
            }
        }
    }
    
    double findMedian() {
        if(mx_heap.size()!=mn_heap.size()){
            return (double)mx_heap.top();
        }else{
            int res = mn_heap.top()+mx_heap.top();
            return (double)res/2;
        }
    }