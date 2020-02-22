#include <iostream>
#include <vector>
#include <utility>
#include <string>

int main() {
		
	// recieve |V| and |E|
	int V, E; std::cin >> V >> E;

	// adjacency list
	std::vector<std::vector<std::pair<int, int>>> G(V);

	for(int i = 0; i < E; i++) {
		// recieve edges
		int u, v, d; std::cin >> u >> v >> d;
		u--; v--;
		G[u].push_back({v, d});
		G[v].push_back({u, d});
	}
	
	// recieve freqencies
	std::vector<int> freq(V);
	for(int i = 0; i < V; i++) std::cin >> freq[i];
	
	int Tmax; std::cin >> Tmax;

	for(int t = 0; t < Tmax; t++) {

		// the number of new order
		int Nnew; std::cin >> Nnew;
		for(int j = 0; j < Nnew; j++) {
			int new_id, dst; std::cin >> new_id >> dst;
		}
	
		// the number of items transfered into the car at time t.
		int Nput; std::cin >> Nput;
		for(int j = 0; j < Nput; j++) {
			int put_id; std::cin >> put_id;
		}

    // insert your code here to get more meaningful output
		// you have to output a command here
		std::cout << -1 << std::endl; // stay

		std::string verdict; std::cin >> verdict;
		if(verdict == "NG") {
			return 1;
		}

		// the number of orders that have been delivered at time t.
		int Nachive; std::cin >> Nachive;
		for(int j = 0; j < Nachive; j++) {
			int achive_id; std::cin >> achive_id;
		}
		
	}

	return 0;
}
