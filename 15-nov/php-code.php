class Solution {
    /**
     * @param Integer[] $arr
     * @return Integer
     */
    function maximumElementAfterDecrementingAndRearranging($arr) {
        $len = count($arr);
        sort($arr);
        $arr[0] = 1;
        for ($i = 1; $i < $len; $i++) {
            if ($arr[$i] > $arr[$i - 1] + 1) {
                $arr[$i] = $arr[$i - 1] + 1;
            }
        }
        return $arr[$len - 1];
    }
}