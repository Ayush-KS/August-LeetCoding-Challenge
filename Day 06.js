// Find All Duplicates in an Array

var findDuplicates = function(nums) {
    var ret = [];
    
    for(let i = 0; i < nums.length; i++) {
        if(nums[Math.abs(nums[i]) - 1] > 0) {
            nums[Math.abs(nums[i]) - 1] *= -1;
        } else {
            ret.push(Math.abs(nums[i]));
        }
    }
    
    return ret;
};