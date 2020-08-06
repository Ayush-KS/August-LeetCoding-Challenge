// Add and Search Word - Data structure design

class node {
    constructor() {
        this.isTerminal = false;
        this.children = Array(26).fill(null);
    }
}

var WordDictionary = function() {
    this.root = new node();
};

WordDictionary.prototype.addWord = function(word) {
    var temp = this.root;
    for(let i = 0; i < word.length; i++) {
        let ind = word.charCodeAt(i) - 97;
        if(temp.children[ind] == null) {
            temp.children[ind] = new node;
        }
        temp = temp.children[ind];
    }
    temp.isTerminal = true;
};

function helper(word, temp, ind) {
    if(temp == null)
        return false;
    
    if(ind == word.length)
        return temp.isTerminal;
    
    if(word[ind] == '.') {
        for(let i = 0; i < 26; i++) {
            if(helper(word, temp.children[i], ind + 1))
                return true;
        }
        return false;
    } else {
        return helper(word, temp.children[word.charCodeAt(ind) - 97], ind + 1);
    }
}

WordDictionary.prototype.search = function(word) {
    temp = this.root;
    return helper(word, temp, 0);
};