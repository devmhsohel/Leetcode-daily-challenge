class Solution {
    /**
     * @param Integer[] $nums
     * @param Integer[] $l
     * @param Integer[] $r
     * @return Boolean[]
     */
    function checkArithmeticSubarrays($nums, $l, $r) {
        $len = count($l);
        $res = [];
        for ($i = 0; $i < $len; $i++) {
            $arr = array_slice($nums, $l[$i], $r[$i] - $l[$i] + 1);
            sort($arr);
            $res []= $this->checkArithmetic($arr);
        }
        return $res;
    }
    function checkArithmetic($arr) {
        $len = count($arr);
        $gap = $arr[1] - $arr[0];
        for ($i = 1; $i < $len - 1; $i++) {
            if ($arr[$i + 1] - $arr[$i] != $gap) {
                return false;
            }
        }
        return true;
    }
}