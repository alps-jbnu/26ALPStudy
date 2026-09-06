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



std::vector< std::vector<int> >map;
std::vector< std::vector<int> >visited;
std::queue< Node >q;

std::vector< std::vector<int> > direct =
{
	{-1,0},
	{1,0},
	{0,-1},
	{0,1},
};


int bfs(int targetX, int targetY)
{
	int count = 0;
	int flag = 0;
	while (!q.empty())
	{
		
		Node now = q.front();
		if (now.x == targetX && now.y == targetY)
		{
			int value = now.time + 1;
			return value;
		}
		for (size_t i = 0; i < 4; i++)
		{
			if (now.x + direct[i][0] < 0 || now.x + direct[i][0] > map[0].size() - 1 || now.y + direct[i][1] < 0 || now.y + direct[i][1] > map.size() - 1)
			{
				continue;
			}
			if (visited[now.y + direct[i][1]][now.x + direct[i][0]] == 1)
			{
				continue;
			}
			if (map[now.y + direct[i][1]][now.x + direct[i][0]] == 1)
			{
				if (count < 1)
				{
					map[now.y + direct[i][1]][now.x + direct[i][0]] = 0;
					count++;
					flag = 1;
				}
				if (flag == 0)
				{
					continue;
				}
				else if (flag == 1)
				{
					flag = 0;
				}
			}
			Node next;
			next.x = now.x + direct[i][0];
			next.y = now.y + direct[i][1];
			next.time = now.time + 1;
			visited[now.y + direct[i][1]][now.x + direct[i][0]] = 1;
			q.push(next);
		}
		q.pop();
	}

	return -1;
}





int main()
{
	std::ios::sync_with_stdio(NULL);
	std::cin.tie(NULL);
	int height;
	int width;
	int result;

	std::cin >> height >> width;
	map.resize(height, std::vector<int>(width, 0));
	visited.resize(height, std::vector<int>(width, 0));

	for (size_t i = 0; i < height; i++)
	{
		for (size_t j = 0; j < width; j++)
		{
			char ch_;
			std::cin >> ch_;
			map[i][j] = ch_ - '0';
		}
	}

	q.push({ 0,0, 0});
	map[0][0] = 0;
	map[height - 1][width - 1] = 0;
	visited[0][0] = 1;
	result = bfs(width-1, height-1);
	visited[0][0] = 0;
	std::cout << result << '\n';


	return 0;
}
#endif