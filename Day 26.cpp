// Fizz Buzz

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans;
        for(int i = 1; i <= n; i++) {
            string currString;
            if(!(i%3)) {
                currString += "Fizz";
            } 
            if(!(i%5)) {
                currString += "Buzz";
            }
            if((i%3) && (i%5)) {
                currString += to_string(i);
            }
            ans.push_back(currString);
        }
        return ans;
    }
};