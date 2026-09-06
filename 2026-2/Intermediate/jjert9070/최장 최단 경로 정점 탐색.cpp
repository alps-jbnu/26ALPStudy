#if 0
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

void djikstra(int start, int n, std::vector< std::pair<int, int> >* map, std::vector< int >& dist)
{
	std::vector<bool>visit(n, false);

	dist[start] = 0;
	visit[start] = true;
	for (size_t i = 0; i < map[start].size(); i++)
	{
		dist[map[start][i].first] = map[start][i].second;
	}

	while (true)
	{
		int min_value = INT_MAX;
		int min_index = -1;
		for (size_t i = 0; i < dist.size(); i++)
		{
			if (visit[i] == false && dist[i] < min_value)
			{
				min_value = dist[i];
				min_index = i;
			}
		}


		if (min_index == -1 && min_value == INT_MAX)
		{
			break;
		}

		visit[min_index] = true;

		for (size_t i = 0; i < map[min_index].size(); i++)
		{
			if (visit[map[min_index][i].first] == false && dist[map[min_index][i].first] > dist[min_index] + map[min_index][i].second)
			{
				dist[map[min_index][i].first] = dist[min_index] + map[min_index][i].second;
			}
		}
	}
}


int main()
{
	std::ios::sync_with_stdio(NULL);
	std::cin.tie(NULL);
	
	int n;
	int m;

	std::vector< std::pair<int, int> >* map;
	std::vector< int >dist;
	std::cin >> n >> m;

	map = new std::vector< std::pair<int, int> >[n];
	dist.resize(n, INT_MAX);


	for (size_t i = 0; i < m; i++)
	{
		int vertex_1;
		int vertex_2;

		std::cin >> vertex_1 >> vertex_2;
		map[vertex_1 - 1].push_back({ vertex_2 - 1, 1 });
		map[vertex_2 - 1].push_back({ vertex_1 - 1, 1 });
	}

	djikstra(0, n, map, dist);


	std::for_each(dist.begin(), dist.end(),
		[](int& select)
		{
			if (select == INT_MAX)
			{
				select = -1;
			}

		});

	std::vector<int>::iterator max_distance_it = std::max_element(dist.begin(), dist.end());

	int max_distance_index = max_distance_it - dist.begin();

	int count = 0;
	for (size_t i = 0; i < dist.size(); i++)
	{
		if (dist[i] == *max_distance_it)
		{
			count++;
		}
	}

	std::cout << max_distance_index + 1 << " " << *max_distance_it << " " <<count<< '\n';


	return 0;

}
#endif