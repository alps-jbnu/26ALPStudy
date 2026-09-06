#if 0
#include <iostream>
#include <vector>

std::vector<bool>visit;


int total = 0;
int result = 0;
int distance(std::vector<std::vector<std::pair<int, int>>>& map, int start, int arrive)
{
	if (start == arrive)
	{
		result = total;
		return result;
	}

	for (size_t i = 0; i < map[start].size(); i++)
	{
		if (visit[map[start][i].second] == false)
		{
			visit[map[start][i].second] = true;
			total = total + map[start][i].first;
			result = distance(map, map[start][i].second, arrive);
			total = total - map[start][i].first;
			visit[map[start][i].second] = false;
		}
	}

	return result;
}


int main()
{
	std::ios::sync_with_stdio(NULL);
	std::cin.tie(0);
	int n;
	int m;
	std::vector<std::vector<std::pair<int, int>>>map;
	std::cin >> n >> m;
	map.resize(n);
	visit.resize(n, false);

	for (size_t i = 0; i < n-1; i++)
	{
		int vertex1;
		int vertex2;
		int weight;
		std::cin >> vertex1 >> vertex2 >> weight;

		map[vertex1 - 1].push_back({ weight, vertex2 - 1 });
		map[vertex2 - 1].push_back({ weight, vertex1 - 1 });
	}

	for (size_t i = 0; i < m; i++)
	{
		int start;
		int arrive;

		std::cin >> start >> arrive;
		visit[start - 1] = true;
		int result_dist = distance(map, start - 1, arrive - 1);
		total = 0;
		result = 0;
		std::fill(visit.begin(), visit.end(), false);
		std::cout << result_dist << '\n';
	}


	return 0;
}
#endif