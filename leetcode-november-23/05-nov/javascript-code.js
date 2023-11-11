/**
 * @param {number[]} arr
 * @param {number} k
 * @return {number}
 */
var getWinner = function(arr, k) {
    let win_count = 0;
    let winner = arr[0];
    for (let i = 1; i < arr.length; i++) {
        if (arr[i] > winner) {
            winner = arr[i];
            win_count = 0;
        }
        if (++win_count === k) {
            break;
        }
    }
    return winner;
};