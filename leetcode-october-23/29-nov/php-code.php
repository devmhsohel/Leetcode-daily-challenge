class Solution {

    /**
     * @param Integer $buckets
     * @param Integer $minutesToDie
     * @param Integer $minutesToTest
     * @return Integer
     */
    function poorPigs($buckets, $minutesToDie, $minutesToTest) {
        $pigs = 0;
    while (pow(($minutesToTest / $minutesToDie + 1), $pigs) < $buckets) {
        $pigs++;
    }
    return $pigs;
    }
}