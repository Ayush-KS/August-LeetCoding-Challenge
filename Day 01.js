// Detect Capital

var detectCapitalUse = function(word) {
    return word == word.toUpperCase() || word == word[0] + word.slice(1).toLowerCase();
};