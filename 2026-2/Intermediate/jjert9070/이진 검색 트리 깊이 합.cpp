#if 0
#include <iostream>
#include <unordered_map>


int insertNodeRecur(std::unordered_map<int, int>& nodes, int inputNode, int root, int level)
{
	int result = 0;
	if (nodes.find(root) == nodes.end())
	{
		nodes[root] = inputNode;
		return level;
	}

	if (nodes[root] <= inputNode)
	{
		result = insertNodeRecur(nodes, inputNode, root * 2 + 1, level + 1);
	}
	else if (nodes[root] > inputNode)
	{
		result = insertNodeRecur(nodes, inputNode, root * 2, level + 1);
	}

	return result;
}

int main()
{
	std::ios::sync_with_stdio(NULL);
	std::cin.tie(0);

	int n;
	int result = 0;
	std::cin >> n;
	std::unordered_map<int, int> nodes;

	for (size_t i = 0; i < n; i++)
	{
		int inputNode;
		std::cin >> inputNode;
		result = result + insertNodeRecur(nodes, inputNode, 1, 1);
	}

	std::cout << result << '\n';

	return 0;

}
#endif