// Random Point in Non-overlapping Rectangles

class Solution {
public:
    vector<double> prob;
    vector<vector<int>> rect;
    Solution(vector<vector<int>>& rects) {
        rect = rects;
        vector<int> w (rects.size());
        for(int i = 0 ; i < rects.size(); i++) {
            w[i] = (abs(rects[i][0] - rects[i][2]) + 1) * (abs(rects[i][1] - rects[i][3]) + 1);
        }
        discrete_distribution<> d(w.begin(), w.end());
        prob = d.probabilities();
    }
    
    vector<int> pick() {
        double p = (double)rand() / RAND_MAX;
        double cumulativeProbability = 0.0;
        int i = 0;
        for (double curr : prob) {
            cumulativeProbability += curr;
            if (p <= cumulativeProbability) {
                break;
            }
            i++;
        }
        
        int absc, ord;
        absc = abs(rect[i][2] - rect[i][0]) + 1;
        ord = abs(rect[i][3] - rect[i][1]) + 1;
        
        int x = min(rect[i][0], rect[i][2]) + (rand() % absc);
        int y = min(rect[i][1], rect[i][3]) + (rand() % ord);
        
        return {x, y};
    }
};
