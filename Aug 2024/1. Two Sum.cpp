vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> v, temp;
        temp = nums;
        sort(temp.begin(), temp.end());
        int i=0, j=nums.size()-1, n1, n2;
        while(i<j){
            if(temp[i]+temp[j]==target){
                n1 = temp[i];
                n2 = temp[j];
                break;
            }else if(temp[i]+temp[j]<target){
                i++;
            }else{
                j--;
            }
        }
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==n1 || nums[i]==n2){
                v.push_back(i);
                if(v.size()==2){
                    break;
                }
            }
        }
        return v;
    }