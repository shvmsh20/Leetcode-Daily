class CustomStack {
public:
    vector<int> st;
    int mxSize, currSize, right;
    CustomStack(int maxSize) {
        st.resize(maxSize);
        mxSize = maxSize;
        currSize = 0;
        right = 0;
    }
    
    void push(int x) {
        if(currSize!=mxSize){
            st[right] = x;
            right++;
            currSize++;
        }
    }
    
    int pop() {
        if(currSize==0){
            return -1;
        }
        int top = st[right-1];
        currSize--;
        right--;
        return top;
    }
    
    void increment(int k, int val) {
        for(int i=0; i<k && i<currSize; i++){
            st[i]+= val;
        }
    }
};