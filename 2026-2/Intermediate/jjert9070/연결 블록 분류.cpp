#if 0
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

std::vector< std::vector<int> > map;
std::vector< std::vector<int> > visited;

struct Coord
{
	int x;
	int y;
};

std::queue< Coord >q;
std::priority_queue<int, std::vector<int>, std::greater<int> > clusters;

int direct[4][2] =
{
	0, -1,
	0, 1,
	-1, 0,
	1, 0,
};




int cluster()
{
	int count = 0;
	while (!q.empty())
	{
		Coord now = q.front();
		if (map[now.y][now.x] == 1)
		{
			count++;
		}

		for (size_t i = 0; i < 4; i++)
		{
			if (now.x + direct[i][0] < 0 || now.x + direct[i][0] >= map[0].size() || now.y + direct[i][1] < 0 || now.y + direct[i][1] >= map.size())
			{
				continue;
			}

			if (visited[now.y + direct[i][1]][now.x + direct[i][0]] == 1)
			{
				continue;
			}

			if (map[now.y + direct[i][1]][now.x + direct[i][0]] == 1)
			{
				visited[now.y + direct[i][1]][now.x + direct[i][0]] = 1;
				Coord next;
				next.x = now.x + direct[i][0];
				next.y = now.y + direct[i][1];
				q.push(next);
			}
		}
		q.pop();
	}
	return count;
}



int main()
{
	int n;
	std::cin >> n;
	map.resize(n, std::vector<int>(n, 0));
	visited.resize(n, std::vector<int>(n, 0));

	std::for_each(map.begin(), map.end(),
		[](std::vector<int>& row)
		{
			std::for_each(row.begin(), row.end(),
				[](int& col)
				{
					char ch;
					std::cin >> ch;
					col = ch - '0';
				});
		});

	int clusterCount = 0;
	for (int i = 0; i < map.size(); i++)
	{
		for (int j = 0; j < map[0].size(); j++)
		{
			if (map[i][j] == 1 && visited[i][j] == 0)
			{
				visited[i][j] = 1;
				q.push({ j,i });
				int result = cluster();
				clusterCount++;
				clusters.push(result);
			}
		}
	}

	std::cout << clusterCount << '\n';
	while (!clusters.empty())
	{
		int ret = clusters.top();
		std::cout << ret << '\n';
		clusters.pop();
	}


	return 0;

}
#endif