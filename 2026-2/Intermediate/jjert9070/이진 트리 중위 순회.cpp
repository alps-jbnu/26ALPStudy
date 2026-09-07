#if 0
#include <iostream>
#include <vector>
#include <algorithm>

int index = 0;
int getMaxWidth(std::vector<std::vector<int>>&map2, int level)
{
	int leftIndex;
	int rightIndex;
	int result;
	int left = 0;
	int right = map2[level].size() - 1;

	while (true)
	{
		if (left >= right)
		{
			break;
		}

		if (map2[level][left] != 1)
		{
			left++;
		}
		if (map2[level][right] != 1)
		{
			right--;
		}

		if (map2[level][left] == 1 && map2[level][right] == 1)
		{
			break;
		}
	}

	result = right - left + 1;


	return result;
}

void traval(std::vector<std::pair<int, int>>&map, std::vector<std::vector<int>>&map2, int root, int level)
{

	if (level >= map2.size() || root == -1)
	{
		return;
	}

	traval(map, map2, map[root].first, level + 1);
	map2[level][index++] = 1;
	traval(map, map2, map[root].second, level + 1);
}



int getDepth(std::vector<std::pair<int, int>>&map,int now, int level)
{
	int left = 0;
	int right = 0;
	if (now == -1)
	{
		return level;
	}

	left = getDepth(map, map[now].first, level+1);
	right = getDepth(map, map[now].second, level + 1);
	return std::max(left, right);
}

int main()
{
	std::vector<std::pair<int, int>>map;
	std::vector<std::vector<int>>map2;
	std::vector<int>width_vec;
	int n;
	int depth;
	int width;
	std::cin >> n;
	map.resize(n);

	for (size_t i = 0; i < n; i++)
	{
		int node;
		int left;
		int right;

		std::cin >> node >> left >> right;
		if (left == -1 && right != -1)
		{
			map[node - 1] = {-1, right - 1};
		}
		else if (left != -1 && right == -1)
		{
			map[node - 1] = {left - 1, -1};
		}
		else if (left != -1 && right != -1)
		{
			map[node -1] = {left-1, right-1};
		}
		else if (left == -1 && right == -1)
		{
			map[node-1] = {-1, -1};
		}
	}

	depth = getDepth(map, 0, 0);
	map2.resize(depth, std::vector<int>(n, 0));
	width_vec.resize(depth, 0);
	traval(map, map2, 0, 0);


	for (size_t i = 0; i < depth; i++)
	{
		width_vec[i] = getMaxWidth(map2, i);
	}


	int max_level = *std::max_element(width_vec.begin(), width_vec.end());

	for (size_t i = 0; i < width_vec.size(); i++)
	{
		if (max_level == width_vec[i])
		{
			std::cout << i + 1 << " " << width_vec[i];
			break;
		}
	}

	std::cout << '\n';

	return 0;
}
#endif
