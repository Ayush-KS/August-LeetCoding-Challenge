// Implement Rand10() Using Rand7()

class Solution {
public:
    int rand10() {
        int ans;
        do {
            int a = rand7();
            int b = rand7();
            ans = 7*(a - 1) + (b - 1);
        } while(ans > 40);
        
        return 1 + ans%10;
    }
};