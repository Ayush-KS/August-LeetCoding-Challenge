// Longest Palindrome

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mp;
        
        for(char c : s) {
            mp[c]++;
        }
        
        int ans = 0;
        bool odd = false;
        
        for(auto it : mp) {
            ans += it.second;
            if(it.second & 1) {
                odd = true;
                ans--;
            }
        }
        
        if(odd)
            ans++;
        
        return ans;
    }
};