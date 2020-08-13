// Pascal's Triangle II

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> output;
        output.push_back(1);
        for(int i = 1; i <= rowIndex; i++) {
            int temp = output[0];
            for(int j = 1; j < output.size(); j++) {
                int newTemp = output[j];
                output[j] = output[j] + temp;
                temp = newTemp;
            }
            output.push_back(1);
        }
        
        return output;
    }
};