#if 0
#include <iostream>
#include <vector>
#include <queue>
#include <climits>

struct Edge
{
	int vertex_1;
	int vertex_2;
};

struct Node
{
	int vertex;
	int count;
};


std::vector<Edge>edges;
std::vector<std::vector<int>>map;
std::vector<int>scores;


int bfs(int start, int target)
{
	if (start == target)
	{
		return 0;
	}
	std::queue<Node>q;
	std::vector<int>visit(map.size(), 0);
	visit[start] = 1;
	q.push({ start, 0 });

	while (!q.empty())
	{
		Node now = q.front();

		for (size_t i = 0; i < map.size(); i++)
		{
			if (map[now.vertex][i] == 1 && visit[i] == 0)
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
	std::cin >> n;
	map.resize(n, std::vector<int>(n, 0));
	scores.resize(n, 0);
	int vertex_1 = 0;
	int vertex_2 = 0;


	while (true)
	{
		std::cin >> vertex_1;
		std::cin >> vertex_2;
		if (vertex_1 == -1 && vertex_2 == -1)
		{
			break;
		}
		edges.push_back({ vertex_1, vertex_2 });
	}

	for (size_t i = 0; i < edges.size(); i++)
	{
		map[edges[i].vertex_1 - 1][edges[i].vertex_2 - 1] = 1;
		map[edges[i].vertex_2 - 1][edges[i].vertex_1 - 1] = 1;
	}

	int result = 0;
	int max = INT_MIN;
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			result = bfs(i, j);
			if (result > max)
			{
				max = result;
			}
		}
		scores[i] = max;
		max = INT_MIN;
	}

	int min_score = *std::min_element(scores.begin(), scores.end());

	int min_score_count = 0;

	for (size_t i = 0; i < scores.size(); i++)
	{
		if (scores[i] == min_score)
		{
			min_score_count++;
		}
	}

	std::cout << min_score << " " << min_score_count << '\n';

	for (size_t i = 0; i < scores.size(); i++)
	{
		if (scores[i] == min_score)
		{
			std::cout << i+1 << " ";
		}
	}

	std::cout << '\n';






	return 0;
}
#endif