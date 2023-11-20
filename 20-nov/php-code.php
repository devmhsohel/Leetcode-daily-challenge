class Solution {

    /**
     * @param String[] $garbage
     * @param Integer[] $travel
     * @return Integer
     */
    function garbageCollection($garbage, $travel) {
        $time1 = strlen($garbage[0]);
        $time2 = 0;
        $t1 = $t2 = $t3 = 0;
        for($i=1;$i<count($garbage);$i++){
            $time1 += strlen($garbage[$i]);
            $t1+=$travel[$i-1];
            $t2+=$travel[$i-1];
            $t3+=$travel[$i-1];
            if (strpos($garbage[$i],"P")!==false){$time2 += $t1; $t1=0;}
            if (strpos($garbage[$i],"G")!==false){$time2 += $t2; $t2=0;}
            if (strpos($garbage[$i],"M")!==false){$time2 += $t3; $t3=0;} 
        }
        return $time1 + $time2;
    }
}