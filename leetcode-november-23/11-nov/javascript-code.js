// /**
//  * @param {number} n
//  * @param {number[][]} edges
//  */
// var Graph = function(n, edges) {
//     this.graph = Array.from({length: n}, () => []);
//     for (const [u, v, w] of edges) {
//         this.graph[u].push([v, w]);
//     }
// };

// /** 
//  * @param {number[]} edge
//  * @return {void}
//  */
// Graph.prototype.addEdge = function(edge) {
//     const [u, v, w] = edge;
//     this.graph[u].push([v, w]);
// };

// /** 
//  * @param {number} node1 
//  * @param {number} node2
//  * @return {number}
//  */
// Graph.prototype.shortestPath = function(node1, node2) {
//     const pq = [[0, node1]];
//     const dist = Array(this.graph.length).fill(Infinity);
//     dist[node1] = 0;
//     while (pq.length) {
//         const [d, u] = pq.shift();
//         if (u === node2) {
//             return d;
//         }
//         if (d > dist[u]) {
//             continue;
//         }
//         for (const [v, w] of this.graph[u]) {
//             if (dist[v] > d + w) {
//                 dist[v] = d + w;
//                 pq.push([dist[v], v]);
//             }
//         }
//         pq.sort((a, b) => a[0] - b[0]);
//     }
//     return -1;
// };

// /** 
//  * Your Graph object will be instantiated and called as such:
//  * var obj = new Graph(n, edges)
//  * obj.addEdge(edge)
//  * var param_2 = obj.shortestPath(node1,node2)
//  */

class Graph {
    // O(n³), O(n²)
    constructor(n, edges) {
        this.n = n;
        this.dist = Array(n).fill().map(() => new Uint32Array(n).fill(-1));
        for(var i=0; i<n; ++i) this.dist[i][i] = 0;
        for(var [u,v,c] of edges) this.dist[u][v] = c;
        for(var k=0; k<this.n; ++k) this.#forLoop(k,k,0);
    }

    // O(n²), O(1)
    addEdge([u,v,c]) {
        if(this.dist[u][v] <= c) return;
        this.dist[u][v] = c;
        this.#forLoop(u,v,c);
    }

    // O(1), O(1)
    shortestPath(u,v) {
        return this.dist[u][v] === 4294967295 ? -1 : this.dist[u][v];
    }

    // Private method (Repeated code in two functions)
    #forLoop(u,v,c) {
        for(var i=0; i<this.n; ++i)
            for(var j=0; j<this.n; ++j)
                this.dist[i][j] = Math.min(
                    this.dist[i][j], this.dist[i][u] + c + this.dist[v][j]
                );
    }
}