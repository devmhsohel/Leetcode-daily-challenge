/**
 * @param {number[][]} adjacentPairs
 * @return {number[]}
 */
var restoreArray = function(adjacentPairs) {
    const graph = new Map();

    for (const [u, v] of adjacentPairs) {
        if (graph.get(u) === undefined) graph.set(u, []);
        if (graph.get(v) === undefined) graph.set(v, []);

        graph.get(u).push(v);
        graph.get(v).push(u);

    }
    let root;
    for (const [key, val] of graph) {
        if (val.length === 1) {
            root = key;
            break;
        }
    }

    const res = [], visited = new Set();

    function dfs(root) {
        if (visited.has(root)) return;
        visited.add(root);
        res.push(root);
        for (const adj of graph.get(root)) {
            dfs(adj)
        }
    }
    dfs(root);
    return res;
};