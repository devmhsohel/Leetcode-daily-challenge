class Solution {
    /**
     * @param String $s
     * @return String
     */
    function sortVowels($s) {
        $vowels = ['A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'];
        $count = array_fill(0, 10, 0);
        $sArray = str_split($s);
        for ($i = 0; $i < count($sArray); $i++) {
            for ($j = 0; $j < 10; $j++) {
                if ($sArray[$i] === $vowels[$j]) {
                    $count[$j]++;
                    $sArray[$i] = '*';
                    break;
                }
            }
        }
        $j = 0;
        while ($j < 10 && !$count[$j]) {$j++;}
        if ($j === 10) {return implode('', $sArray);}
        for ($i = 0; $i < count($sArray); $i++) {
            if ($sArray[$i] === '*') {
                $sArray[$i] = $vowels[$j];
                $count[$j]--;
                while ($j < 10 && !$count[$j]) {$j++;}
                if ($j === 10) {return implode('', $sArray);}
            }
        }
        return implode('', $sArray);
    }
}