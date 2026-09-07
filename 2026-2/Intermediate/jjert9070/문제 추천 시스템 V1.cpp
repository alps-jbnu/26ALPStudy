#include <iostream>
#include <map>
#include <unordered_map>


void deleteNode(std::map<int, std::pair<int, int>>& nodes, int root, int problemNumber)
{
	if (nodes.find(root) == nodes.end())
	{
		return;
	}

	int problemIndex;
	problemIndex = root;

	for (auto& select : nodes)
	{
		if (select.second.first == problemNumber)
		{
			problemIndex = select.first;
		}
	}

	nodes.erase(problemIndex);

}

std::pair<int, int> getMax(std::map<int, int>& nodes)
{
	if (nodes.empty())
	{
		return {};
	}

	std::pair<int, int> result;

	result = *nodes.begin();

	return result;
}




std::pair<int, int> recommendation(std::map<int, int>& nodes, int root, int x)
{
	if (nodes.empty())
	{
		return {};
	}
	std::pair<int, int> result = {};

	if (x == 1)
	{
		
	}
	else if (x == -1)
	{
		
	}

	return result;
}


void pushNode(std::map<int, int>& nodes, std::pair<int, int> inputNode)
{
	nodes.insert(inputNode);
}



int main()
{
	int n;
	int m;
	std::map<int, int> nodes;

	std::cin >> n;


	for (size_t i = 0; i < n; i++)
	{
		int problemNumber;
		int difficulty;

		std::cin >> problemNumber >> difficulty;
		pushNode(nodes, { problemNumber, difficulty });
	}

	std::cin >> m;


	for (size_t i = 0; i < m; i++)
	{
		std::string command;
		std::cin >> command;

		if (command.compare("recommend") == 0)
		{
			int x;
			std::pair<int, int> result;
			
			std::cin >> x;

			result = recommendation(nodes, 1, x);
			std::cout << result.first << '\n';
		}
		else if (command.compare("add") == 0)
		{
			int p;
			int l;

			std::cin >> p >> l;

			pushNode(nodes, { l, p });
		}
		else if (command.compare("solved") == 0)
		{
			int p;

			std::cin >> p;

			deleteNode(nodes, 1, p);

		}
		
	}
	




	return 0;

}