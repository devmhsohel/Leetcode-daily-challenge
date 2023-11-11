/**
 * @param {number} sx
 * @param {number} sy
 * @param {number} fx
 * @param {number} fy
 * @param {number} t
 * @return {boolean}
 */
var isReachableAtTime = function(sx, sy, fx, fy, t) {
    let xd = Math.abs(sx - fx), yd = Math.abs(sy - fy);

    if (xd === 0 && yd === 0 && t === 1) {
        return false;
    }

    return t >= Math.max(xd, yd);
};