#if 0
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using mapVec = std::vector< std::vector<std::pair<int, int>> >;

void djikstra(int start, mapVec& map, std::vector<int>& dist)
{
	std::priority_queue < std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>>q;
	std::vector<bool>visit(map.size(), false);
	dist.assign(map.size(), INT_MAX);

	visit[start] = true;
	dist[start] = 0;
	for (size_t i = 0; i < map[start].size(); i++)
	{
		dist[map[start][i].second] = map[start][i].first;
		q.push({map[start][i].first, map[start][i].second});
	}
	

	while (!q.empty())
	{
		int min_index = q.top().second;

		q.pop();

		visit[min_index] = true;

		for (size_t i = 0; i < map[min_index].size(); i++)
		{
			int next_index = map[min_index][i].second;
			int next_cost = map[min_index][i].first;

			if (visit[next_index] == true)
			{
				continue;
			}

			if (dist[next_index] > dist[min_index] + next_cost)
			{
				dist[next_index] = dist[min_index] + next_cost;
				q.push({ dist[next_index], next_index });
			}
		}
	}
}


int main()
{
	std::ios::sync_with_stdio(NULL);
	std::cin.tie(0);
	std::vector< std::vector<std::pair<int, int>> >map;
	std::vector< int > dist;
	int N;
	int E;
	int calibrationVertex_1;
	int calibrationVertex_2;


	std::cin >> N >> E;
	map.resize(N);
	dist.resize(N, 0);

	for (size_t i = 0; i < E; i++)
	{
		int vertex_1;
		int vertex_2;
		int weight;
		std::cin >> vertex_1 >> vertex_2 >> weight;

		map[vertex_1 - 1].push_back({ weight, vertex_2 - 1 });
		map[vertex_2 - 1].push_back({ weight, vertex_1 - 1 });
	}

	std::cin >> calibrationVertex_1 >> calibrationVertex_2;

	djikstra(0, map, dist);
	int startTov1 = dist[calibrationVertex_1 - 1];
	int startTov2 = dist[calibrationVertex_2 - 1];

	djikstra(calibrationVertex_1 - 1, map, dist);
	int v1Tov2 = dist[calibrationVertex_2 - 1];
	int v1ToN = dist[N - 1];

	djikstra(calibrationVertex_2 - 1, map, dist);
	int v2Tov1 = dist[calibrationVertex_1 - 1];
	int v2ToN = dist[N - 1];
	int result_1 = startTov1 + v1Tov2 + v2ToN;
	int result_2 = startTov2 + v2Tov1 + v1ToN;

	if (result_1 >= INT_MAX && result_2 >= INT_MAX)
	{
		std::cout << "-1" << '\n';
	}
	else if (result_1 < result_2)
	{
		std::cout << result_1 << '\n';
	}
	else if (result_1 > result_2)
	{
		std::cout << result_2 << '\n';
	}
	else if (result_1 == result_2)
	{
		std::cout << result_1 << '\n';
	}



	return 0;
}
#endif