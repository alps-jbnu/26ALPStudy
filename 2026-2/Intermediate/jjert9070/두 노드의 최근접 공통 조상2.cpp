#if 0
#include <iostream>
#include <vector>

int lca(std::vector<int>& level, std::vector<int>& parent, std::vector<std::vector<int>>& node,
	std::vector<std::vector<int>>& nodeParent, int vertex1, int vertex2)
{
	int result = 0;
	if (level[vertex1] > level[vertex2])
	{
		int temp;
		temp = vertex2;
		vertex2 = vertex1;
		vertex1 = temp;
	}


	if (!nodeParent[vertex2].empty())
	{
		int i = nodeParent[vertex2].size() - 1;
		for (; i >= 0; i--)
		{
			if (level[vertex2] - level[vertex1] >= (1 << i))
			{
				vertex2 = nodeParent[vertex2][i];
			}

			if (level[vertex2] == level[vertex1])
			{
				break;
			}
		}
	}

	if (vertex1 == vertex2)
	{
		return vertex1;
	}


	

	if (!nodeParent[vertex1].empty() && !nodeParent[vertex2].empty())
	{
		int j;
		j = std::max(nodeParent[vertex1].size(), nodeParent[vertex2].size());
		j = j - 1;

		for (; j >= 0; j--)
		{
			if (j < nodeParent[vertex1].size() && j < nodeParent[vertex2].size())
			{
				if (nodeParent[vertex1][j] != nodeParent[vertex2][j])
				{
					vertex1 = nodeParent[vertex1][j];
					vertex2 = nodeParent[vertex2][j];
				}
			}
		}
	}

	result = nodeParent[vertex1][0];

	return result;
}

std::vector<int>path;
void traval(std::vector<int>& level, std::vector<std::vector<int>>& node, 
	std::vector<std::vector<int>>& nodeParent, int root, int nowLevel)
{
	int i = path.size() - 1;
	int j = 0;
	int index;

	index = i - (1 << j);

	while (index >= 0)
	{
		nodeParent[root].push_back(path[index]);
		j++;
		index = i - (1 << j);
	}

	for (size_t i = 0; i < node[root].size(); i++)
	{
		level[node[root][i]] = nowLevel + 1;
		path.push_back(node[root][i]);
		traval(level, node, nodeParent, node[root][i], nowLevel + 1);
		path.pop_back();
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
		std::vector<std::vector<int>>nodeParent;
		std::vector<int>parent;
		std::vector<int>level;

		std::cin >> n;
		node.resize(n);
		nodeParent.resize(n);
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

		path.push_back(root);
		traval(level, node, nodeParent, root, 0);

		std::cin >> vertex1 >> vertex2;
		result = lca(level, parent, node, nodeParent, vertex1 - 1, vertex2 - 1);

		std::cout << result + 1 << '\n';
		t--;
	}

	return 0;

}
#endif