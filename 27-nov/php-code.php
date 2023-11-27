class Solution {

    /**
     * @param Integer $n
     * @return Integer
     */
    function knightDialer($n) {
        return (
        + ($this->get($n, 1) << 1)
        + $this->get($n, 2)
        + ($this->get($n, 4)<<1)
        + $this->get($n, 5)
        + ($this->get($n, 7)<<1)
        + $this->get($n, 8)
        + $this->get($n, 0))% (7+10e8);

    }

    function get($n, $pos) {
        static $cache = [];
        if($n===1) return 1;
        if(isset ($cache[$n][$pos])) return $cache[$n][$pos];
        $n--;
        $res = match($pos){
            0 => $this->get($n, 4) << 1,
            1 => $this->get($n, 4) + $this->get($n, 8),
            2 => $this->get($n, 7) << 1,
            4 => $this->get($n, 1) + $this->get($n, 7) + $this->get($n, 0),
            5 => 0,
            7 => $this->get($n, 2) + $this->get($n, 4),
            8 => $this->get($n, 1) << 1
        };

        return  $cache[$n+1][$pos] = $res % (7 + 10e8);
    }
}