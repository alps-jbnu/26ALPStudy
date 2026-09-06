#if 0
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>



std::vector<std::vector<int>> map;

std::vector<std::vector<int>> direct =
{
	{0,-1},
	{0,1},
	{-1,0},
	{1,0}
};


struct Coord
{
	int x;
	int y;
};
std::queue<Coord> outerq;
std::vector< std::vector<int> > outerVisited;
std::queue<Coord> innerq;
std::vector< std::vector<int> > innerVisited;




void innerBFS()
{
	while (!innerq.empty())
	{
		Coord now = innerq.front();

		for (size_t i = 0; i < direct.size(); i++)
		{
			if (now.x + direct[i][0] < 0 || now.x + direct[i][0] >= map[0].size() || now.y + direct[i][1] < 0 || now.y + direct[i][1] >= map.size())
			{
				continue;
			}

			if ((map[now.y + direct[i][1]][now.x + direct[i][0]] > 0) && (innerVisited[now.y + direct[i][1]][now.x + direct[i][0]]) == 0)
			{
				innerVisited[now.y + direct[i][1]][now.x + direct[i][0]] = 1;
				
				Coord next;
				next.x = now.x + direct[i][0];
				next.y = now.y + direct[i][1];
				innerq.push(next);
			}
		}

		innerq.pop();
	}
}

int outerBFS()
{
	int count = 0;
	while (!outerq.empty())
	{
		Coord now = outerq.front();

		if (map[now.y][now.x] > 0 && innerVisited[now.y][now.x] == 0)
		{
			innerq.push({ now.x, now.y });
			innerVisited[now.y][now.x] = 1;
			innerBFS();
			count++;
			while (!innerq.empty())
			{
				innerq.pop();
			}
		}

		for (size_t i = 0; i < direct.size(); i++)
		{
			if (now.x + direct[i][0] < 0 || now.x + direct[i][0] >= map[0].size() || now.y + direct[i][1] < 0 || now.y + direct[i][1] >= map.size())
			{
				continue;
			}

			if (outerVisited[now.y + direct[i][1]][now.x + direct[i][0]] == 1)
			{
				continue;
			}

			Coord next;
			outerVisited[now.y][now.x] = 1;
			next.x = now.x + direct[i][0];
			next.y = now.y + direct[i][1];
			outerq.push(next);
		}

		outerq.pop();
	}
	return count;
}

void pourWater(int level)
{
	for (size_t i = 0; i < map.size(); i++)
	{
		for (size_t j = 0; j < map[0].size(); j++)
		{
			if (map[i][j] <= level)
			{
				map[i][j] = -1;
			}
		}
	}

}


int main()
{
	std::ios::sync_with_stdio(NULL);
	std::cin.tie(NULL);
	int n;
	std::cin >> n;

	map.resize(n, std::vector<int>(n, 0));
	outerVisited.resize(n, std::vector<int>(n, 0));
	innerVisited.resize(n, std::vector<int>(n, 0));
	std::for_each(map.begin(), map.end(),
		[](std::vector<int>& row)
		{
			std::for_each(row.begin(), row.end(),
				[](int& col)
				{
					std::cin >> col;
				});
		});
	int max = INT_MIN;
	int maxLevel = INT_MIN;

	for (size_t i = 0; i < map.size(); i++)
	{
		if (maxLevel < *std::max_element(map[i].begin(), map[i].end()))
		{
			maxLevel = *std::max_element(map[i].begin(), map[i].end());
		}
	}


	for (size_t i = 0; i < maxLevel; i++)
	{
		outerq.push({ 0,0 });
		pourWater(i);
		int result = outerBFS();
		if (max < result)
		{
			max = result;
		}

		outerVisited.assign(n, std::vector<int>(n, 0));
		innerVisited.assign(n, std::vector<int>(n, 0));
		while (!outerq.empty())
		{
			outerq.pop();
		}
		while (!innerq.empty())
		{
			innerq.pop();
		}
	}

	std::cout << max << '\n';

	return 0;
}
#endif