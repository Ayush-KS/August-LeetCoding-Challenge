// Vertical Order Traversal of a Binary Tree

var verticalTraversal = function(root) {
    if (root == null) {
        return [];
    }
    
    const queue = [];
    
    queue.push([root, 0, 0]);
    const list = [];
    while(queue.length > 0) {
        const [node, row, column] = queue.shift();
        
        
        if (node) {
            queue.push([node.left, row + 1, column - 1])
            queue.push([node.right, row + 1, column + 1])
            list.push([node.val, row, column]);
        }
    }
  
  const compare = (a, b) => {
    if (a[2] - b[2] === 0 ) {
      
      if (a[1] - b[1] === 0) {
        return a[0] - b[0];
      }
    }
    
    return a[2] - b[2]
  }
  
   list.sort(compare)
  
  const map = new Map();
  for(let i = 0; i < list.length; i++) {
    const [value, row, column] = list[i]
    
    if (map.has(column)) {
      map.get(column).push(value)
    } else {
      map.set(column, [value]);
    }
  }
  
  return [...map.values()]
};