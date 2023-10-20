
class NestedIterator {
public:
    vector<int> res;
    int index=0;
    void util(vector<NestedInteger> &nestedList){
        int n = nestedList.size();
        vector<NestedInteger> temp;
        for(int i=0; i<n; i++){
            if(nestedList[i].isInteger()){
                res.push_back(nestedList[i].getInteger());
            }else{
                temp = nestedList[i].getList();
                util(temp);
            }
        }
    }
    NestedIterator(vector<NestedInteger> &nestedList) {
        util(nestedList);
    }
    
    int next() {
        int ans = res[index];
        index++;
        return ans;
    }
    
    bool hasNext() {
        if(index==res.size()){
            return false;
        }else{
            return true;
        }
    }
};