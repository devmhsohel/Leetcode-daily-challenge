/**
 * @param {number[][]} routes
 * @param {number} source
 * @param {number} target
 * @return {number}
 */
var numBusesToDestination = function(routes, source, target) {
    if (source === target) {
        return 0;
    }

    // Create a graph where each bus stop is a node and each route is an edge
    const stopToRoutes = new Map();
    for (let i = 0; i < routes.length; i++) {
        for (const stop of routes[i]) {
            if (!stopToRoutes.has(stop)) {
                stopToRoutes.set(stop, []);
            }
            stopToRoutes.get(stop).push(i);
        }
    }

    // Initialize BFS queue with the source bus stop and the number of buses taken
    const queue = [[source, 0]];
    const visitedStops = new Set([source]);
    const visitedRoutes = new Set();

    while (queue.length > 0) {
        const [currentStop, busesTaken] = queue.shift();

        if (currentStop === target) {
            return busesTaken;
        }

        // Explore all buses that go through the current stop
        for (const routeIndex of stopToRoutes.get(currentStop) || []) {
            if (!visitedRoutes.has(routeIndex)) {
                visitedRoutes.add(routeIndex);
                for (const nextStop of routes[routeIndex]) {
                    if (!visitedStops.has(nextStop)) {
                        visitedStops.add(nextStop);
                        queue.push([nextStop, busesTaken + 1]);
                    }
                }
            }
        }
    }

    return -1
};