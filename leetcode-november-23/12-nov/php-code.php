class Solution {

    /**
     * @param Integer[][] $routes
     * @param Integer $source
     * @param Integer $target
     * @return Integer
     */
    function numBusesToDestination($routes, $source, $target) {
        if ($source == $target) {
            return 0;
        }
        $maxStop = -1;
        foreach ($routes as $route) {
            foreach ($route as $stop) {
                $maxStop = max($maxStop, $stop);
            }
        }
        if ($maxStop < $target) {
            return -1;
        }
        $n = count($routes);
        $minBusesToReach = array_fill(0, $maxStop + 1, $n + 1);
        $minBusesToReach[$source] = 0;
        $flag = true;
        while ($flag) {
            $flag = false;
            foreach ($routes as $route) {
                $min = $n + 1;
                foreach ($route as $stop) {
                    $min = min($min, $minBusesToReach[$stop]);
                }
                $min++;
                foreach ($route as $stop) {
                    if ($minBusesToReach[$stop] > $min) {
                        $minBusesToReach[$stop] = $min;
                        $flag = true;
                    }
                }
            }
        }
        return ($minBusesToReach[$target] < $n + 1 ? $minBusesToReach[$target] : -1);
    
    }
}