/**
 * @param {string} corridor
 * @return {number}
 */
var numberOfWays = function(corridor) {
    const mod = 1000000007;  // Define the modulo value for the final result
    let res = 1;  // Initialize the result variable to 1 (will be updated during iteration)
    let prevSeat = 0;  // Initialize the variable to track the index of the previous seat
    let numSeats = 0;  // Initialize the variable to count the number of seats encountered

    for (let i = 0; i < corridor.length; i++) {
        const c = corridor.charAt(i);
        if (c === 'S') {
            numSeats += 1;  // Increment the seat count when 'S' is encountered
            // Check if there are more than 2 consecutive seats and an odd number of seats
            if (numSeats > 2 && numSeats % 2 === 1) {
                // Update the answer using the distance between the current seat and the previous seat
                res = res * (i - prevSeat) % mod;
            }
            prevSeat = i;  // Update the previous seat index to the current index
        }
    }

    // Return the answer only if there are more than 1 seat and an even number of seats
    return numSeats > 1 && numSeats % 2 === 0 ? res : 0;    
};



class Solution:
    def numberOfWays(self, corridor):
        seat, res, plant = 0, 1, 0
        for i in corridor:
            if i=='S':
                seat += 1
            else:
                if seat == 2:
                    plant += 1
            if seat == 3:
                res = res*(plant+1) % (10**9 + 7)
                seat , plant = 1 , 0
        if seat != 2:
            return 0
        return res










/**
 * @param {string} corridor
 * @return {number}
 */
var numberOfWays = function(corridor) {
    let ans = 1, seatCount = 0, recentPosition = 0, mod = 1000000007;

    for (let i = 0; i < corridor.length; ++i) {
        if (corridor[i] === 'S') {
            ++seatCount;
            if (seatCount > 2 && seatCount % 2 === 1) {
                ans = (ans * (i - recentPosition)) % mod;
            }
            recentPosition = i;
        }
    }

    return (seatCount % 2 === 0 && seatCount > 0) ? ans : 0;
};