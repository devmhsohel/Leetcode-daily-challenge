/**
 * @param {number[]} arr
 * @return {number}
 */
var maximumElementAfterDecrementingAndRearranging = function(arr) {
    const len = arr.length;
    arr.sort((a, b) => a - b);
    arr[0] = 1;
    for (let i = 1; i < len; i++) {
        if (arr[i] > arr[i - 1] + 1) {
            arr[i] = arr[i - 1] + 1;
        }
    }
    return arr[len - 1];
};