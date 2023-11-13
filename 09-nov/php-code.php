class Solution {

    /**
     * @param String $s
     * @return Integer
     */
    function countHomogenous($s) {
        $count = 1;
        $result = 0;
        $prev = $s[0];
        $MOD = 1000000007;

        for ($i = 1; isset($s[$i]); $i++) {
            if ($s[$i] == $prev) {
                $count++;
            } else {
                $result += (($count * ($count + 1)) >> 1) % $MOD; // Using bitwise right shift for division by 2
                $count = 1;
                $prev = $s[$i];
            }
        }

        $result += (($count * ($count + 1)) >> 1) % $MOD; // Using bitwise right shift for division by 2

        return $result % $MOD;
    }
}