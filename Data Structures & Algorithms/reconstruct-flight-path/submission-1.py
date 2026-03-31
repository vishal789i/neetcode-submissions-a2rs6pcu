class Solution:
    def findItinerary(self, tickets: List[List[str]]) -> List[str]:
        # Step 1: Build the graph (adjacency list)
        graph = defaultdict(list)
        
        for from_i, to_i in tickets:
            heapq.heappush(graph[from_i], to_i)
        
        # Step 2: Define a recursive function for DFS
        result = []
        
        def dfs(airport):
            # If there are no more flights from the current airport, add it to the result
            while graph[airport]:
                # Visit the lexicographically smallest destination
                next_airport = heapq.heappop(graph[airport])
                dfs(next_airport)
            
            # After visiting all destinations from the current airport, add to result
            result.append(airport)
        
        # Step 3: Start the DFS from "JFK"
        dfs("JFK")
        
        # Step 4: The result is constructed in reverse order, so reverse it
        return result[::-1]