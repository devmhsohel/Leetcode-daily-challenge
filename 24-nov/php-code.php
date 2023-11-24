class Solution {

    /**
     * @param Integer[] $piles
     * @return Integer
     */
    function maxCoins($piles) {
        sort($piles);
        $len = count($piles);
        $res = 0;
        $r = $len - 1;
        for ($i = 0; $i < $len / 3; $i++){
            $res += $piles[$r - 1];
            $r -= 2;
        }

        return $res;
    }
}








class Solution {

    /**
     * @param Integer[] $piles
     * @return Integer
     */
    function maxCoins($piles) {
        $n = count($piles) / 3;
        $k = 0;
        rsort($piles);
        for ($i = 1; $n;$i+=2){
            $k += $piles[$i];
            $n--;
        }
        return $k;
    }
}











function maxCoins($piles) {
    $sorted = $helpAr = array();
    $min = min($piles);
    $max = max($piles);
    $cnt = count($piles);
// fill the arra for counting sort
    foreach($piles as $pil){
        $helpAr[$pil] = (isset($helpAr[$pil])) ? $helpAr[$pil]+1 : 1;
    }
    unset($piles); // we don't need $piles anymore
    for ($i=$min; $i<=$max; $i++) {
        if (isset($helpAr[$i])) {
            for ($j=0; $j<$helpAr[$i]; $j++) {
                $sorted[] = $i;
            }
        }
    }
    $res = 0;
    for ($k = $cnt-2;$k>$cnt/3-1;$k--){
        $res += $sorted[$k];
        $k--;
    }
    return $res;
}














function maxCoins($piles) {
        rsort($piles);
        $to = count($piles) / 3;
        $s = 0;
        for ($i = 0; $i < count($piles) - $to; $i++) {
            if ($i % 2 == 1) {
                $s += $piles[$i];
            }
        }
        return $s;
    }