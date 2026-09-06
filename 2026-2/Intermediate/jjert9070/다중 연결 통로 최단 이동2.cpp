#if 0
#include <iostream>
#include <vector>
#include <climits>
#include <queue>

std::vector< int > djikstra(int nodeCount, std::vector<std::pair<int, int>>* vertex, int start)
{
	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>>q;
	std::vector< int >board(nodeCount, INT_MAX);
	std::vector< bool > visit(nodeCount, false);
	visit[start] = true;
	board[start] = 0;
	q.push({ start, 0 });

	while (!q.empty())
	{
		int now = q.top().first;
		int weight = q.top().second;
		q.pop();
		for (size_t i = 0; i < vertex[now].size(); i++)
		{
			if (weight + vertex[now][i].second < board[vertex[now][i].first])
			{
				board[vertex[now][i].first] = weight + vertex[now][i].second;
				q.push(std::make_pair(vertex[now][i].first, weight + vertex[now][i].second));
			}
		}
	}

	return board;
}

int main()
{
	std::ios::sync_with_stdio(NULL);
	std::cin.tie(0);
	int n;
	int k;
	int m;
	std::cin >> n >> k >> m;
	auto* vertex = new std::vector<std::pair<int, int>>[n];
	std::vector<int>inputs(k, 0);

	for (size_t i = 0; i < m; i++)
	{
		for (size_t j=0 ; j < k; j++)
		{
			int vertex;
			std::cin >> vertex;
			inputs[j] = vertex;
		}

		for (size_t u=0 ; u < k-1; u++)
		{
			vertex[inputs[u + 1] - 1].push_back({ inputs[u] - 1, 1 });
			vertex[inputs[u] - 1].push_back({ inputs[u + 1] - 1, 1 });
		}

		vertex[inputs[0] - 1].push_back({inputs[k - 1] - 1, 1});
		vertex[inputs[k - 1] - 1].push_back({ inputs[0] - 1, 1 });
		
	}

	auto result = djikstra(n, vertex, 0);


	if (result[n - 1] == INT_MAX)
	{
		std::cout << "-1" << '\n';
	}
	else
	{
		std::cout << result[n - 1] + 1 << '\n';
	}


	delete[]vertex;

	return 0;
}
#endif