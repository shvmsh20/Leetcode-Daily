class FoodRatings {
public:
struct cmp{
    bool operator() (const pair<int, string> &p1, const pair<int, string> &p2)const
    {
        if(p1.first!=p2.first){
            return p1.first>p2.first;
        }else{
            return p1.second<p2.second;
        }
    }
};
unordered_map<string, set< pair<int, string>, cmp > > cuisineToFood;
unordered_map<string, string> foodToCuisine;
unordered_map<string, int> foodToRating;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        
        for(int i=0; i<foods.size(); i++){
            cuisineToFood[cuisines[i]].insert({ratings[i], foods[i]});
            foodToCuisine[foods[i]] = cuisines[i];
            foodToRating[foods[i]] = ratings[i];
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuisine = foodToCuisine[food];
        int oldRating = foodToRating[food];
        cuisineToFood[cuisine].erase({oldRating, food});
        cuisineToFood[cuisine].insert({newRating, food});
        foodToRating[food] = newRating;
    }
    
    string highestRated(string cuisine) {
        pair<int, string> p = *(cuisineToFood[cuisine].begin());
        return p.second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */