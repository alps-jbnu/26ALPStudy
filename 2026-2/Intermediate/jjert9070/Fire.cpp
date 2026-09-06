#if 0
#include <iostream>
#include <vector>
#include <queue>

struct Node
{
	int x;
	int y;
	int time;
};

int direct[4][2] =
{
	1, 0,
	-1, 0,
	0, 1,
	0, -1
};
std::queue <Node> q;

std::vector < std::vector<char> > map;
std::vector < std::vector<int> > fireMap;
std::vector < std::vector<int> > visited;
std::vector < Node > fires;

int start_x;
int start_y;

int fire_start_x;
int fire_start_y;
int width;
int height;

void fire()
{
	int fireCount = fires.size();
	for (size_t i = 0; i < fireCount; i++)
	{
		for (size_t j = 0; j < 4; j++)
		{
			if (fires[i].x + direct[j][0] < 0 || fires[i].x + direct[j][0] >= width || fires[i].y + direct[j][1] < 0 || fires[i].y + direct[j][1] >= height)
			{
				continue;
			}
			if (fireMap[fires[i].y + direct[j][1]][fires[i].x + direct[j][0]] == 1)
			{
				continue;
			}

			if (map[fires[i].y + direct[j][1]][fires[i].x + direct[j][0]] == '#')
			{
				continue;
			}

			fireMap[fires[i].y + direct[j][1]][fires[i].x + direct[j][0]] = 1;
			fires.push_back({ fires[i].x + direct[j][0], fires[i].y + direct[j][1], 0 });
		}
	}
}

void humanbfs()
{
	int count = 0;
	q.push({ start_x, start_y, 0});
	visited[start_y][start_x] = 1;

	while (!q.empty())
	{
		Node now = q.front();
		if (count <= now.time)
		{
			count = now.time;
			fire();
		}


		if ((now.x == 0 || now.x == width - 1 || now.y == 0 || now.y == height - 1))
		{
			std::cout << now.time + 1 << std::endl;
			return;
		}

		q.pop();

		for (size_t i = 0; i < 4; i++)
		{
			if (now.x + direct[i][0] < 0 || now.x + direct[i][0] >= width || now.y + direct[i][1] < 0 || now.y + direct[i][1] >= height)
			{
				continue;
			}

			if (visited[now.y + direct[i][1]][now.x + direct[i][0]] == 1)
			{
				continue;
			}

			if (fireMap[now.y + direct[i][1]][now.x + direct[i][0]] == 1)
			{
				continue;
			}

			if (map[now.y + direct[i][1]][now.x + direct[i][0]] == '#')
			{
				continue;
			}

			if (map[now.y + direct[i][1]][now.x + direct[i][0]] == '.')
			{
				Node next;
				next.x = now.x + direct[i][0];
				next.y = now.y + direct[i][1];
				next.time = now.time + 1;
				visited[next.y][next.x] = 1;
				q.push(next);
				
			}
		}
	}
	std::cout << "IMPOSSIBLE" << std::endl;

}

int main()
{
	int n;

	std::cin >> n;

	
	while (n > 0)
	{
		std::cin >> width >> height;
		map.resize(height, std::vector<char>(width, 0));
		visited.resize(height, std::vector<int>(width, 0));
		fireMap.resize(height, std::vector<int>(width, 0));

		for (size_t i = 0; i < height; i++)
		{
			for (size_t j = 0; j < width; j++)
			{
				std::cin >> map[i][j];
				if (map[i][j] == '@')
				{
					start_x = j;
					start_y = i;
				}

				if (map[i][j] == '*')
				{
					fire_start_x = j;
					fire_start_y = i;
					fires.push_back({ fire_start_x, fire_start_y });
					fireMap[i][j] = 1;
				}
			}
		}
		humanbfs();
		map.clear();
		visited.clear();
		fireMap.clear();
		fires.clear();
		while (!q.empty())
		{
			q.pop();
		}
		n--;
	}

	return 0;
}
#endif