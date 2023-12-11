int findSpecialInteger(vector<int>& arr) {
         int sz = arr.size(), freq = sz / 4;
         for(int indx = 0; indx < sz; indx++){
             if(indx - freq > -1 && arr[indx - freq] == arr[indx]){
                 return arr[indx];
             }
         }
         return -1;
    }