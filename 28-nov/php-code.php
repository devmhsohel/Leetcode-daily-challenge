class Solution {
    /**
     * @param String $corridor
     * @return Integer
     */
    function numberOfWays($corridor) {
        $ans = 1;
        $seatCount = 0;
        $recentPosition = 0;
        $mod = 1000000007;

        for ($i = 0; $i < strlen($corridor); ++$i) {
            if ($corridor[$i] === 'S') {
                ++$seatCount;
                if ($seatCount > 2 && $seatCount % 2 === 1) {
                    $ans = ($ans * ($i - $recentPosition)) % $mod;
                }
                $recentPosition = $i;
            }
        }

        return ($seatCount % 2 === 0 && $seatCount > 0) ? $ans : 0;
    }
}