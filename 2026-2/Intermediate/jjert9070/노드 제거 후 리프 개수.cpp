#if 0
#include <iostream>
#include <vector>

std::vector<int>parents;
std::vector<bool>statusvec;
void delNode(std::vector<std::vector<int>>& map, int now)
{
	for (size_t i = 0; i < map.size(); i++)
	{
		if (map[now][i] == 1)
		{
			map[now][i] = -1;
			statusvec[i] = false;
			delNode(map, i);
		}
	}
}



void deleteNode(std::vector<std::vector<int>>& map, int now, int target)
{
	if (target == now)
	{
		std::fill(map.begin(), map.end(), std::vector<int>(map.size(), -1));
		statusvec[now] = false;
		return;
	}


	int parentNode = parents[target];
	delNode(map, target);
	map[parentNode][target] = -1;
	statusvec[target] = false;
}


int leafCount(std::vector<std::vector<int>>& map, int now)
{
	int count = 0;
	bool status = false;

	if (statusvec[now] == false)
	{
		return 0;
	}

	for (size_t i = 0; i < map.size(); i++)
	{
		if (map[now][i] == -1)
		{
			status = true;
		}
		else if (map[now][i] == 1)
		{
			status = false;
			break;
		}
	}

	if (status == true)
	{
		return 1;
	}

	for (size_t i = 0; i < map.size(); i++)
	{
		if (map[now][i] == 1)
		{
			count = count + leafCount(map, i);
		}
	}

	return count;
}



int main()
{
	std::ios::sync_with_stdio(NULL);
	std::cin.tie(0);

	std::vector<std::vector<int>> map;
	int n;
	int target;
	int result;
	std::cin >> n;
	parents.resize(n, 0);
	statusvec.resize(n, true);
	map.resize(n, std::vector<int>(n, -1));

	for (size_t i = 0; i < n; i++)
	{
		std::cin >> parents[i];
	}
	int root;
	for (size_t i = 0; i < n; i++)
	{
		if (parents[i] == -1)
		{
			root = i;
			continue;
		}
		map[parents[i]][i] = 1;
	}

	std::cin >> target;
	deleteNode(map, root, target);
	result = leafCount(map, root);
	std::cout << result << '\n';

	return 0;
}
#endif