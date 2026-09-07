#if 0
#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>
#include <queue>

void djikstra(int start, std::vector< std::pair<int, int> >* map, std::vector<int>& dist, int n)
{
	std::vector<bool>visit(n, false);
	std::priority_queue< std::pair< int, int >, std::vector< std::pair<int, int> >, std::greater<std::pair<int, int> > >q;
	dist.assign(n, INT_MAX);
	dist[start] = 0;
	visit[start] = true;


	for (size_t i = 0; i < map[start].size(); i++)
	{
		dist[map[start][i].second] = map[start][i].first;
		q.push({ map[start][i].first, map[start][i].second });
	}

	while (!q.empty())
	{
		int min_index = q.top().second;
		q.pop();

		visit[min_index] = true;

		for (size_t i = 0; i < map[min_index].size(); i++)
		{
			int next = map[min_index][i].second;
			int next_cost = map[min_index][i].first;

			if (visit[next] == false && dist[min_index] + next_cost < dist[next] )
			{
				dist[next] = dist[min_index] + next_cost;
				q.push({dist[next], next});
			}
		}

	}

	std::for_each(dist.begin(), dist.end(),
		[](int& select)
		{
			if (select == INT_MAX)
			{
				select = -1;
			}
		});

}


int main()
{
	std::vector< std::pair<int, int> >* map;
	std::vector<int>dist;
	int n;
	int m;
	int x;

	std::cin >> n >> m >> x;
	
	map = new std::vector< std::pair<int, int> >[n];
	for (size_t i = 0; i < m; i++)
	{
		int vertex_1;
		int vertex_2;
		int weight;

		std::cin >> vertex_1 >> vertex_2 >> weight;

		map[vertex_1 - 1].push_back({ weight, vertex_2 - 1 });
	}



	std::vector<int> result(n, 0);
	for (size_t i = 0; i < n; i++)
	{
		djikstra(i, map, dist, n);
		result[i] = result[i] + dist[x - 1];
		djikstra(x - 1, map, dist, n);
		result[i] = result[i] + dist[i];
	}

	for (size_t i = 0; i < result.size(); i++)
	{
		std::cout << result[i] << " ";
	}
	std::cout << '\n';

	int max = *std::max_element(result.begin(), result.end());

	std::cout << max << '\n';


	return 0;
}
#endif