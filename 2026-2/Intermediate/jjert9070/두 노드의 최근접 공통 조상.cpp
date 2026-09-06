#if 0
#include <iostream>
#include <vector>


int lca(std::vector<int>&level, std::vector<int>&parent, std::vector<std::vector<int>>&node, int vertex1, int vertex2)
{
	int result = 0;
	while (true)
	{
		if (level[vertex1] > level[vertex2])
		{
			vertex1 = parent[vertex1];
		}
		else if (level[vertex1] < level[vertex2])
		{
			vertex2 = parent[vertex2];
		}
		else if (level[vertex1] == level[vertex2])
		{
			break;
		}
	}


	while (vertex1 != vertex2)
	{
		vertex1 = parent[vertex1];
		vertex2 = parent[vertex2];
	}

	result = vertex1;
	return result;
}




void traval(std::vector<int>& level, std::vector<std::vector<int>>&node, int root, int nowLevel)
{
	for (size_t i = 0; i < node[root].size(); i++)
	{
		level[node[root][i]] = nowLevel + 1;
		traval(level, node, node[root][i], nowLevel + 1);
	}
}

int main()
{
	std::ios::sync_with_stdio(NULL);
	std::cin.tie(0);

	int t;
	std::cin >> t;
	while (t > 0)
	{
		int n;
		int result;
		int vertex1;
		int vertex2;
		std::vector<std::vector<int>>node;
		std::vector<int>parent;
		std::vector<int>level;

		std::cin >> n;
		node.resize(n);
		parent.resize(n, -1);
		level.resize(n, 0);

		for (size_t i = 0; i < n - 1; i++)
		{
			int parentNode;
			int childNode;

			std::cin >> parentNode >> childNode;

			node[parentNode - 1].push_back(childNode - 1);
			parent[childNode - 1] = parentNode - 1;
		}

		int root = 0;
		for (size_t i = 0; i < parent.size(); i++)
		{
			if (parent[i] == -1)
			{
				root = i;
				break;
			}
		}

		std::cin >> vertex1 >> vertex2;
		traval(level, node, root, 0);
		result = lca(level, parent, node, vertex1 - 1, vertex2 - 1);

		std::cout << result + 1 << '\n';
		t--;
	}

	return 0;

}
#endif