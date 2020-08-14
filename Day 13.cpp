// Iterator for Combination

class CombinationIterator {
public:
    vector<bool> v; 
    int n;
    bool possible = true;
    string s;
    int len;
    
    CombinationIterator(string s, int len) {
        this ->s = s;
        this -> len = len;
        n = s.size();
        v.resize(n, 0);
        for(int i = 0; i < len; i++) {
            v[i] = 1;
        }
    }
    
    string next() {
        string ret = "";
        for(int i = 0; i < n; i++) {
            if(v[i])
                ret += s[i];
        }
        
        if(v[n - 1]) {
            int cnt = 0;
            int i = n - 1;
            while(i >= 0 && v[i]) {
                v[i] = 0;
                cnt++;
                i--;
            }
            if(cnt == len) {
                possible = false;
            } else {
                while(i >= 0 && !v[i]) {
                    i--;
                }
                v[i++] = 0;
                v[i++] = 1;
                while(cnt--) {
                    v[i++] = 1;
                }
            }
        } else {
            for(int i = n - 1; i >= 0; i--) {
                if(v[i]) {
                    v[i + 1] = 1;
                    v[i] = 0;
                    break;
                }
            }
        }
        
        
        return ret;
    }
    
    bool hasNext() {
        return possible;
    }
};