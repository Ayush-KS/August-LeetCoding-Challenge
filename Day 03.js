// Valid Palindrome

var isPalindrome = function(s) {
    var str = "";
    for(let c of s) {
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            if(c >= 'A' && c <= 'Z');
            str += c.toLowerCase();
        }
    }
    return str == str.split("").reverse().join("");
};