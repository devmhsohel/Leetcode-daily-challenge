class Graph {
    /**
     * @param Integer $n
     * @param Integer[][] $edges
     */
    function __construct($n, $edges) {
        $this->graph = array_fill(0, $n, []);
        foreach ($edges as $edge) {
            list($u, $v, $w) = $edge;
            $this->graph[$u][] = [$v, $w];
        }
    }
  
    /**
     * @param Integer[] $edge
     * @return NULL
     */
    function addEdge($edge) {
        list($u, $v, $w) = $edge;
        $this->graph[$u][] = [$v, $w];
    }
  
    /**
     * @param Integer $node1
     * @param Integer $node2
     * @return Integer
     */
    function shortestPath($node1, $node2) {
        $pq = new SplPriorityQueue();
        $pq->insert([$node1, 0], 0);
        $dist = array_fill(0, count($this->graph), PHP_INT_MAX);
        $dist[$node1] = 0;
        while (!$pq->isEmpty()) {
            list($u, $d) = $pq->extract();
            if ($u == $node2) {
                return $d;
            }
            if ($d > $dist[$u]) {
                continue;
            }
            foreach ($this->graph[$u] as list($v, $w)) {
                if ($dist[$v] > $d + $w) {
                    $dist[$v] = $d + $w;
                    $pq->insert([$v, $dist[$v]], -$dist[$v]);
                }
            }
        }
        return -1;
    }
}

/**
 * Your Graph object will be instantiated and called as such:
 * $obj = Graph($n, $edges);
 * $obj->addEdge($edge);
 * $ret_2 = $obj->shortestPath($node1, $node2);
 */