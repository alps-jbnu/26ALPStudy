#if 0
#include <iostream>
#include <vector>
#include <algorithm>

std::vector< int > visited;
std::vector< std::vector<int> > map;

int dfs(int now)
{
	int count = 1;

	for (size_t i = 0; i < map.size(); i++)
	{
		if (visited[i] == 1)
		{
			continue;
		}

		if (map[now][i] == 1)
		{
			visited[i] = 1;
			count += dfs(i);
		}
	}

	return count;
}



int main()
{
	int n;
	int m;

	std::cin >> n;
	std::cin >> m;


	map.resize(n, std::vector<int>(n,0));
	visited.resize(n, 0);
	for (size_t i = 0; i < m; i++)
	{
		int vertex_1;
		int vertex_2;
		std::cin >> vertex_1 >> vertex_2;
		map[vertex_2 - 1][vertex_1 - 1] = 1;
	}

	std::vector<int>counts;
	counts.resize(n, 0);
	for (size_t i = 0; i < n; i++)
	{
		visited[i] = 1;
		counts[i] = dfs(i);
		std::fill(visited.begin(), visited.end(), 0);
	}

	int max = *std::max_element(counts.begin(), counts.end());

	for (size_t i = 0; i < n; i++)
	{
		if (max == counts[i])
		{
			std::cout << i + 1 << " ";
		}
	}
	std::cout << '\n';


	return 0;
}
#endif