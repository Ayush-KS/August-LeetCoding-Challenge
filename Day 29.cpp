// Pancake Sorting

class Solution {
public:
    vector<int> pancakeSort(vector<int>& A) {
        vector<int> output;
        for(int i = 0; i < A.size(); i++) {
            int maxIndex = max_element(A.begin(), A.end() - i) - A.begin();
            
            output.push_back(maxIndex + 1);
            reverse(A.begin(), A.begin() + maxIndex + 1);
            reverse(A.begin(), A.end() - i);
            output.push_back(A.size() - i);
        }
        return output;
    }
};