/**
 * @param {string} s
 * @return {number}
 */
// var countPalindromicSubsequence = function(s) {
    
// };

const countPalindromicSubsequence = s => {
    let n = 0, i, j
    for ( let a of 'abcdefghijklmnopqrstuvwxyz' )
        for ( let b of 'abcdefghijklmnopqrstuvwxyz' )
            i = s.indexOf(a), j = s.indexOf(b,i+1),
            n += i < j && j < s.indexOf(a,j+1)
    return n
}