class Solution {

    /**
     * @param Integer $sx
     * @param Integer $sy
     * @param Integer $fx
     * @param Integer $fy
     * @param Integer $t
     * @return Boolean
     */
    function isReachableAtTime($sx, $sy, $fx, $fy, $t) {
        $xd = abs($sx - $fx);
        $yd = abs($sy - $fy);

        if ($xd == 0 && $yd == 0 && $t == 1) {
            return false;
        }

        return $t >= max($xd, $yd);
    }
}