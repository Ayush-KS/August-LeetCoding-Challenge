// Distribute Candies to People

class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> op(num_people);
        int i = 1;
        
        while(candies > 0) {
            op[((i-1) % num_people)] += min(i, candies);
            candies -= min(i, candies);
            i++;
        }
        
        return op;
    }
};