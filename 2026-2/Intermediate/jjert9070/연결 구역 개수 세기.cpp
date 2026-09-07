#if 0
#include <iostream>
#include <vector>
#include <queue>

std::vector<std::vector<int>> map;
int direct[4][2] =
{
	0,-1,
	0,1,
	-1,0,
	1,0,
};


struct Node
{
	int x;
	int y;
};

std::queue<Node> q;
std::vector<std::vector<int>> visited;

void bfs()
{
	while (!q.empty())
	{
		Node now = q.front();
		for (size_t i = 0; i < 4; i++)
		{
			if (now.x + direct[i][0] < 0 || now.x + direct[i][0] > map[0].size() - 1 || now.y < 0 || now.y + direct[i][1] > map.size() - 1)
			{
				continue;
			}

			if (visited[now.y + direct[i][1]][now.x + direct[i][0]] == 1)
			{
				continue;
			}

			if (map[now.y + direct[i][1]][now.x + direct[i][0]] == 1)
			{
				Node next;
				next.x = now.x + direct[i][0];
				next.y = now.y + direct[i][1];
				visited[next.y][next.x] = 1;
				q.push(next);
			}
		}
		q.pop();
	}

}


int main()
{
	int T;


	int count = 0;

	std::cin >> T;

	while (T > 0)
	{
		int width, height, occupied;
		std::cin >> width >> height >> occupied;
		visited.resize(height, std::vector<int>(width, 0));
		map.resize(height, std::vector<int>(width, 0));
		for (size_t i = 0; i < occupied; i++)
		{
			int xCord, yCord;

			std::cin >> xCord >> yCord;
			map[yCord][xCord] = 1;

		}


		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				if (j < 0 || j > width || i < 0 || i >height)
				{
					continue;
				}

				if (map[i][j] == 1 && visited[i][j] == 0)
				{
					visited[i][j] = 1;
					q.push({ j, i });
					bfs();
					count++;
				}

			}

		}

		std::cout << count << std::endl;
		count = 0;
		map.clear();
		visited.clear();
		while (!q.empty())
		{
			q.pop();
		}

		T--;
	}


	bfs();



	return 0;
}
#endif