class Solution:
    def numberOfWays(self, corridor: str) -> int:
        seats = False
        plants = 0
        answer = 1
        corridor = corridor.strip('P')
        if not corridor:  # no seats
            return 0
        for sp in corridor:
            if sp == 'S':
                seats = not seats
                if plants:
                    answer = answer * (plants + 1) % 1000000007
                    plants = 0
            elif not seats:  # between odd and even numbered seats
                plants += 1
                
        if seats:  # odd number of seats
            return 0
        return answer % 1000000007



class Solution:
    def numberOfWays(self, corridor: str) -> int:
        mod = 10**9 + 7  # Define the modulo value for the final result
        res = 1  # Initialize the result variable to 1 (will be updated during iteration)
        prev_seat = 0  # Initialize the variable to track the index of the previous seat
        num_seats = 0  # Initialize the variable to count the number of seats encountered

        for i, c in enumerate(corridor):
            if c == 'S':
                num_seats += 1  # Increment the seat count when 'S' is encountered
                # Check if there are more than 2 consecutive seats and an odd number of seats
                if num_seats > 2 and num_seats % 2 == 1:
                    # Update the answer using the distance between the current seat and the previous seat
                    res *= i - prev_seat
                prev_seat = i  # Update the previous seat index to the current index

        # Return the answer only if there are more than 1 seat and an even number of seats
        return res % mod if num_seats > 1 and num_seats % 2 == 0 else 0




class Solution:
    def numberOfWays(self, corridor: str) -> int:
        ans, seatCount, recentPosition, mod = 1, 0, 0, 10**9 + 7

        for i, char in enumerate(corridor):
            if char == 'S':
                seatCount += 1
                if seatCount > 2 and seatCount % 2 == 1:
                    ans = (ans * (i - recentPosition)) % mod
                recentPosition = i

        return ans if seatCount % 2 == 0 and seatCount > 0 else 0