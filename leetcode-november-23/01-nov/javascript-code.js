/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number[]}
 */
var findMode = function(root) {
    let maxFreq = 0;
    let currFreq = 0;
    let currVal = null;
    let modes = [];

    const traverse = (node) => {
        if (!node) return;

        traverse(node.left);

        if (node.val === currVal) {
            currFreq++;
        } else {
            currVal = node.val;
            currFreq = 1;
        }

        if (currFreq > maxFreq) {
            maxFreq = currFreq;
            modes = [currVal];
        } else if (currFreq === maxFreq) {
            modes.push(currVal);
        }

        traverse(node.right);
    };

    traverse(root);

    return modes;
};