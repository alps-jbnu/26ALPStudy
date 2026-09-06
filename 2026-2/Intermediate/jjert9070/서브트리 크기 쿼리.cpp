#if 0
#include <iostream>
#include <vector>

int subtreeCount(std::vector<std::vector<int>>& nodes, std::vector<int>&subtreeNodeCount, std::vector<bool>&visit, int root)
{
	int count = 1;

	for (size_t i = 0; i < nodes[root].size(); i++)
	{
		if (visit[nodes[root][i]] == false)
		{
			visit[nodes[root][i]] = true;
			count = count + subtreeCount(nodes, subtreeNodeCount, visit, nodes[root][i]);
		}
	}

	subtreeNodeCount[root] = count;
	
	return count;
}


int main()
{
	std::ios::sync_with_stdio(NULL);
	std::cin.tie(0);
	int n;
	int r;
	int q;
	std::vector<std::vector<int>>nodes;
	std::vector<int>subtreeNodeCount;
	std::vector<bool>visit;

	std::cin >> n >> r >> q;

	nodes.resize(n);
	subtreeNodeCount.resize(n, 0);
	visit.resize(n, false);

	for (size_t i = 0; i < n-1; i++)
	{
		int v1;
		int v2;
		std::cin >> v1 >> v2;
		nodes[v1 - 1].push_back(v2 - 1);
		nodes[v2 - 1].push_back(v1 - 1);
	}

	visit[r - 1] = true;
	subtreeCount(nodes, subtreeNodeCount, visit, r - 1);

	for (size_t i = 0; i < q; i++)
	{
		int query;
		std::cin >> query;
		std::cout << subtreeNodeCount[query - 1] << '\n';
	}


	return 0;
}
#endif