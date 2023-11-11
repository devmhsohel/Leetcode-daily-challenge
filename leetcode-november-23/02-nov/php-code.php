/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     public $val = null;
 *     public $left = null;
 *     public $right = null;
 *     function __construct($val = 0, $left = null, $right = null) {
 *         $this->val = $val;
 *         $this->left = $left;
 *         $this->right = $right;
 *     }
 * }
 */
class Solution {

    /**
     * @param TreeNode $root
     * @return Integer
     */
    function averageOfSubtree($root) {
        $this->count = 0;
        $this->dfs($root);
        return $this->count;
    }
    
    private function dfs($node) {
        if ($node === null) {
            return [0, 0];
        }
        
        list($left_sum, $left_count) = $this->dfs($node->left);
        list($right_sum, $right_count) = $this->dfs($node->right);
        
        $total_sum = $left_sum + $right_sum + $node->val;
        $total_count = $left_count + $right_count + 1;
        
        if (intdiv($total_sum, $total_count) == $node->val) {
            $this->count++;
        }
        
        return [$total_sum, $total_count];
    }
}