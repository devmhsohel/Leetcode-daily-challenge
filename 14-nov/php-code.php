class Solution {

    /**
     * @param String $s
     * @return Integer
     */
    function countPalindromicSubsequence($s) {
        $n = strlen($s);
        if ($n < 3) {
            return 0;
        }
        $cnt = 0;
        for ($c = 0; $c < 26; $c++) {
            $i = 0;
            $j = $n - 1;
            while ($i < $j && $s[$i] != chr($c + 97)) {
                $i++;
            }
            while ($i < $j && $s[$j] != chr($c + 97)) {
                $j--;
            }
            if ($i == $j) {
                continue;
            }
            $freq = array_fill(0, 26, 0);
            for ($k = $i + 1; $k < $j; $k++) {
                $freq[ord($s[$k]) - 97]++;
            }
            $cnt += array_sum(array_map(function ($x) { return $x > 0 ? 1 : 0; }, $freq));
        }
        return $cnt;
    }
}