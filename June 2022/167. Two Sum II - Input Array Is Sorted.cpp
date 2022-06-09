vector<int> twoSum(vector<int>& arr, int target) {
        int i=0 ; 
        int j = arr.size()-1 ; 
        
        
        
        while(i<=j)
        {
            if( arr[i]+arr[j] == target)
            {
                break ; 
            }
            
            if( arr[i]+arr[j] > target)
                j-- ; 
            else{
                i++ ; 
            }
            
            
        }
        
        return {i+1,j+1} ;
    }