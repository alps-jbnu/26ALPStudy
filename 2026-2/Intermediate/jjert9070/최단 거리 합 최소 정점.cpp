#if 0
#include <iostream>
#include <vector>
#include <queue>

std::vector<std::vector<int>>map;
struct Node
{
	int vertex;
	int count;
};

std::vector<int>counts;
int bfs(int start, int target)
{
	std::vector<int>visit(map.size(), 0);
	std::queue<Node>q;
	visit[start] = 1;
	q.push({ start,0 });

	while (!q.empty())
	{
		Node now = q.front();
		for (size_t i = 0; i<map.size(); i++)
		{
			if (visit[i] == 1)
			{
				continue;
			}

			if (map[now.vertex][i] == 1)
			{
				if (i == target)
				{
					return now.count + 1;
				}
				visit[i] = 1;
				q.push({ (int)i, now.count + 1 });
			}
		}

		q.pop();
	}

	return 0;
}


int main()
{
	std::ios::sync_with_stdio(NULL);
	std::cin.tie(0);
	int n;
	int m;
	std::cin >> n >> m;

	map.resize(n, std::vector<int>(n, 0));
	counts.resize(n, 0);
	
	for (size_t i = 0; i < m; ++i)
	{
		int vertex_1;
		int vertex_2;
		std::cin >> vertex_1 >> vertex_2;
		map[vertex_1 - 1][vertex_2 - 1] = 1;
		map[vertex_2 - 1][vertex_1 - 1] = 1;
	}

	int sum = 0;

	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			sum = sum + bfs(i, j);
		}
		counts[i] = sum;
		sum = 0;
	}

	int min = *std::min_element(counts.begin(), counts.end());
	
	for (size_t i = 0; i < counts.size(); i++)
	{
		if (min == counts[i])
		{
			std::cout << i + 1 << '\n';
			break;
		}
	}

	return 0;
}
#endif