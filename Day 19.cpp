// Goat Latin

class Solution {
public:
    
    bool isVowel(char c) {
        return c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U';
    }
    
    string toGoatLatin(string s) {
        stringstream check(s);
        string temp;
        vector<string> v;
        
        while(getline(check, temp, ' ')) {
            v.push_back(temp);
        }
        
        string op = "";
        for(int i = 0; i < v.size(); i++) {
            if(i) {
                op += " ";
            }
            temp = v[i];
            if(!isVowel(temp[0])) {
                temp = temp.substr(1) + temp[0];
            } 
            temp += "ma";
            temp += string(i + 1, 'a');
            op += temp;
        }
        
        return op;
    }
};