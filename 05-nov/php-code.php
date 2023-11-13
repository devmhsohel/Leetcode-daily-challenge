class Solution {

    /**
     * @param Integer[] $arr
     * @param Integer $k
     * @return Integer
     */
    function getWinner($arr, $k) {
        $win_count = 0;
        $winner = $arr[0];
        for ($i = 1; $i < count($arr); $i++) {
            if ($arr[$i] > $winner) {
                $winner = $arr[$i];
                $win_count = 0;
            }
            if (++$win_count === $k) {
                break;
            }
        }
        return $winner;
    }
}