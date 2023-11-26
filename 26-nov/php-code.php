class Solution {

    function largestSubmatrix($matrix) {
        $m = count($matrix);
        $n = count($matrix[0]);

        for ($i = 1; $i < $m; ++$i) {
            for ($j = 0; $j < $n; ++$j) {
                if ($matrix[$i][$j] == 1) {
                    $matrix[$i][$j] = $matrix[$i - 1][$j] + 1;
                }
            }
        }

        $ans = 0;

        foreach ($matrix as &$row) {
            sort($row);

            for ($j = $n - 1, $k = 1; $j >= 0 && $row[$j] > 0; --$j, ++$k) {
                $s = $row[$j] * $k;
                $ans = max($ans, $s);
            }
        }

        return $ans;
    }
}