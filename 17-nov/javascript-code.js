/**
 * @param {string[]} nums
 * @return {string}
 */
var findDifferentBinaryString = function(nums) {
    return nums.map((num, idx) => (num[idx] === '0' ? '1' : '0')).join('');
};