// Stream of Characters

class trieNode {
    public:
    trieNode** children = new trieNode*[26];
    bool isTerminal;
    
    trieNode() {
        isTerminal = false;
        for(int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
    }
};

void insertWord(trieNode* root, string str, int i) {
    if(i < 0) {
        root -> isTerminal = true;
        return;
    }
    int child = str[i] - 'a';
    
    if(!(root -> children[child])) {
        root -> children[child] = new trieNode();
    }
    insertWord(root -> children[child], str, i - 1);
}

class StreamChecker {
public:
    trieNode* root;
    string str;
    
    StreamChecker(vector<string>& words) {
        root = new trieNode();
        for(string str : words) {
            insertWord(root, str, str.size() - 1);
        }
    }
    
    bool query(char letter) {
        str += letter;
        
        trieNode* temp = root;
        
        for(int i = str.size() - 1; i >= 0 && temp; i--) {
            int child = str[i] - 'a';
            temp = temp -> children[child]; 
            if(temp && temp -> isTerminal)
                return true;
        }
        
        return false;
    }
};