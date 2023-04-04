int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int count = 0, i=0, j=people.size()-1;
        while(i<j){
            if(people
[i]+people[j]<=limit){
                i++;
                j--;
                count++;
            }else{
                j--;
                count++;
            }
        }
        if(i==j){
            count++;
        }
        return count;
    }