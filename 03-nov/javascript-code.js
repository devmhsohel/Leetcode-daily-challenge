/**
 * @param {number[]} target
 * @param {number} n
 * @return {string[]}
 */
var buildArray = function(target, n) {
    let stack = [];
    let result = [];
    for (let i = 1; i <= n; i++) {
        if (target.length === 0) {
            break;
        }
        if (i === target[0]) {
            stack.push(i);
            result.push("Push");
            target.shift();
        } else {
            stack.push(i);
            result.push("Push");
            stack.pop();
            result.push("Pop");
        }
    }
    return result;
};