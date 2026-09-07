#if 0
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

typedef std::vector<std::vector<std::pair<long long, int>>> Map;
typedef std::priority_queue < std::pair<long long, int>, std::vector<std::pair<long long, int>>, std::greater<std::pair<long long, int>>> Heap;


void djikstra(int start, int n, Map& map, std::vector<long long>& dist)
{
	std::vector<bool>visit(n, false);
	Heap q;
	std::fill(dist.begin(), dist.end(), INT_MAX);
	dist[start] = 0;
	q.push({ 0, start });

	while (!q.empty())
	{
		int min_index = q.top().second;
		long long cost = q.top().first;
		q.pop();

		if (visit[min_index] == true)
		{
			continue;
		}

		visit[min_index] = true;

		for (int i = 0; i < map[min_index].size(); i++)
		{
			int next = map[min_index][i].second;
			long long next_cost = map[min_index][i].first;

			if (visit[next] == false && dist[min_index] + next_cost < dist[next])
			{
				dist[next] = dist[min_index] + next_cost;
				q.push({ dist[min_index] + next_cost, next });
			}
		}

	}



}

int main()
{
	std::ios::sync_with_stdio(NULL);
	std::cin.tie(0);

	int n;
	int m;
	int start;
	int target;
	Map map;
	std::vector<long long>dist;
	std::cin >> n;
	std::cin >> m;

	map.resize(n);
	dist.resize(n);
	for (int i = 0; i < m; i++)
	{
		int u;
		int v;
		long long e;

		std::cin >> u >> v >> e;

		map[u - 1].push_back({ e, v - 1 });
	}

	std::cin >> start >> target;

	djikstra(start-1, n, map, dist);

	std::cout << dist[target - 1] << '\n';


	return 0;
}
#endif