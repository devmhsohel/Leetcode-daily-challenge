/**
 * @param {string} s
 * @return {string}
 */
var sortVowels = function(s) {
    var vowels = ['A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'];
    var count = Array(10).fill(0);

    var sArray = s.split('');

    for (var i = 0; i < sArray.length; i++) {
        for (var j = 0; j < 10; j++) {
            if (sArray[i] === vowels[j]) {
                count[j]++;
                sArray[i] = '*';
                break;
            }
        }
    }

    var j = 0;
    while (j < 10 && !count[j]) {
        j++;
    }

    if (j === 10) {
        return sArray.join('');
    }

    for (var i = 0; i < sArray.length; i++) {
        if (sArray[i] === '*') {
            sArray[i] = vowels[j];
            count[j]--;
            while (j < 10 && !count[j]) {
                j++;
            }

            if (j === 10) {
                return sArray.join('');
            }
        }
    }

    return sArray.join('');
};