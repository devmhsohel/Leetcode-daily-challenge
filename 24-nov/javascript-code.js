/**
 * @param {number[]} piles
 * @return {number}
 */
var maxCoins = function(piles) {
    piles.sort((a,b)=>b-a);
    let sum=0;
    for(let i=1;i<piles.length-piles.length/3;i+=2) {
        sum+=piles[i];
    }
    return sum;
};


var maxCoins = function(piles) {
    let max = 0;
    let n = piles.length;

    for (let i of piles) {
        if (max < i) max = i;
    }

    let freq = new Array(max + 1).fill(0);

    for (let i of piles) {
        freq[i]++;
    }

    let coins = 0;
    let chance = Math.floor(n / 3);
    let turn = 1;
    let i = max;

    while (chance !== 0) {
        if (freq[i] > 0) {
            if (turn === 1) turn = 0;
            else {
                chance--;
                turn = 1;
                coins += i;
            }
            freq[i]--;
        } else {
            i--;
        }
    }

    return coins;
};