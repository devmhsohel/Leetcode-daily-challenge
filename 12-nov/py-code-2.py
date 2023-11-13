class Solution:
    def numBusesToDestination(self, routes: List[List[int]], source: int, target: int) -> int:
        if source == target:
            return 0

        # Create a graph where each bus stop is a node and each route is an edge
        stop_to_routes = defaultdict(list)
        for i, route in enumerate(routes):
            for stop in route:
                stop_to_routes[stop].append(i)

        # Initialize BFS queue with the source bus stop and the number of buses taken
        queue = deque([(source, 0)])
        visited_stops = set([source])
        visited_routes = set()

        while queue:
            current_stop, buses_taken = queue.popleft()

            if current_stop == target:
                return buses_taken

            # Explore all buses that go through the current stop
            for route_index in stop_to_routes[current_stop]:
                if route_index not in visited_routes:
                    visited_routes.add(route_index)
                    for next_stop in routes[route_index]:
                        if next_stop not in visited_stops:
                            visited_stops.add(next_stop)
                            queue.append((next_stop, buses_taken + 1))

        return -1