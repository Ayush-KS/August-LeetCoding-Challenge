// Desing HashSet

class node { 
    constructor(val) 
    { 
        this.val = val; 
        this.next = null
    } 
} 

var MyHashSet = function() {
    this.size = 20000;
    this.arr = Array(this.size).fill(null);
};

MyHashSet.prototype.add = function(key) {
    var mod = key % this.size;
    if(this.arr[mod] == null) {
        this.arr[mod] = new node(key);
    } else {
        var curr = this.arr[mod];
        while(curr.next) {
            if(curr.val == key)
                return;
            curr = curr.next;
        }
        if(curr.val == key)
            return;
        curr.next = new node(key);
    }
};

MyHashSet.prototype.remove = function(key) {
    var mod = key % this.size;
    var curr = this.arr[mod];
    
    if(!curr)
        return;
    if(curr.val == key) {
        this.arr[mod] = curr.next;
        return;
    }
    while(curr.next) {
        if(curr.next.val == key) {
            curr.next = curr.next.next;
            return;
        }
        curr = curr.next;
    }
};

MyHashSet.prototype.contains = function(key) {
    var mod = key % this.size;
    var curr = this.arr[mod];
    while(curr) {
        if(curr.val == key)
            return true;
        curr = curr.next;
    }
    return false;
};