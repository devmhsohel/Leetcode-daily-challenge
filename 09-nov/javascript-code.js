/**
 * @param {string} s
 * @return {number}
 */
var countHomogenous = function(s) {
    let count = 1, result = 0, prev = s[0], MOD = 1e9 + 7;
    for (let i = 1; i <= s.length; i++) {
        if (s[i] === prev) {
            count++;
        } else {
            result = (result + Math.floor(count * (count + 1) / 2)) % MOD;
            count = 1;
            prev = s[i];
        }
    }
    return result;
};