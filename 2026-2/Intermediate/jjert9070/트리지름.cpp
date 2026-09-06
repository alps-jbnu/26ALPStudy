#if 0
#include <iostream>
#include <vector>
#include <algorithm>

struct Edge
{
	int now;
	int child;
	int weight;
};

std::vector<int> row;
std::vector<std::vector<int>> map;
std::vector<int> visited;
int sum = 0;
int max = 0;
int flag = 0;


void dfs(int now, int nodeCount)
{
	for (int i = 0; i < nodeCount; i++)
	{
		if (map[now][i] >= 1 && visited[i] == 0)
		{
			flag = 1;
			break;
		}
	}


	if (flag == 0)
	{
		if (sum >= max)
		{
			max = sum;
		}

		return;
	}

	flag = 0;



	for (int i = 0; i < nodeCount; i++)
	{
		if (map[now][i] >= 1 && visited[i] == 0)
		{
			sum += map[now][i];
			visited[i] = 1;
			dfs(i, nodeCount);
			visited[i] = 0;
			sum -= map[now][i];
		}
	}


}


int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);

	std::vector<Edge> vec;
	int nodeCount;
	int now;
	int child;
	int weight;
	std::cin >> nodeCount;
	for (int i = 0; i < nodeCount - 1; i++)
	{
		std::cin >> now >> child >> weight;
		vec.push_back({ now, child, weight });
	}

	row.resize(nodeCount, 0);
	map.resize(nodeCount, row);
	visited.resize(nodeCount, 0);

	std::for_each(vec.begin(), vec.end(),
		[](Edge& select)
		{
			map[select.now - 1][select.child - 1] = select.weight;
			map[select.child - 1][select.now - 1] = select.weight;
		});

	for (int i = 0; i < nodeCount; i++)
	{
		visited[i] = 1;
		dfs(i, nodeCount);
		visited[i] = 0;
	}
	
	std::cout << max << '\n';

	return 0;
}
#endif