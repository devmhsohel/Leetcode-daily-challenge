class Solution {

    /**
     * @param Integer[] $target
     * @param Integer $n
     * @return String[]
     */
    function buildArray($target, $n) {
        $stack = [];
        $result = [];
        for ($i = 1; $i <= $n; $i++) {
            if (empty($target)) {
                break;
            }
            if ($i == $target[0]) {
                array_push($stack, $i);
                array_push($result, "Push");
                array_shift($target);
            } else {
                array_push($stack, $i);
                array_push($result, "Push");
                array_pop($stack);
                array_push($result, "Pop");
            }
        }
        return $result;
    }
}