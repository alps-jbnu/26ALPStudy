#if 0
#include <iostream>
#include <vector>
#include <queue>

std::vector< std::vector< std::vector< int > > >map;

struct Node
{
	int x;
	int y;
	int z;
	int time;
};

std::queue< Node >q;

int direct[6][3] =
{
	1, 0, 0,
	-1, 0, 0,
	0, 1, 0,
	0, -1, 0,
	0, 0, 1,
	0, 0, -1,
};

std::vector<Node> raw;

int count;
int bfs()
{
	if (count == 0)
	{
		return 0;
	}


	int flag = 0;
	while (!q.empty())
	{
		Node now = q.front();



		for (size_t i = 0; i < 6; i++)
		{
			int nextX = now.x + direct[i][0];
			int nextY = now.y + direct[i][1];
			int nextZ = now.z + direct[i][2];

			if (nextX < 0 || nextX >= map[0][0].size() || nextY < 0 || nextY >= map[0].size() || nextZ < 0 || nextZ >= map.size())
			{
				continue;
			}

			if (map[nextZ][nextY][nextX] == -1)
			{
				continue;
			}

			if (map[nextZ][nextY][nextX] == 1)
			{
				continue;
			}

			if (map[nextZ][nextY][nextX] == 0)
			{
				map[nextZ][nextY][nextX] = 1;
					
				for (size_t i = 0; i < raw.size(); i++)
				{
					if (map[raw[i].z][raw[i].y][raw[i].x] == 1)
					{
						flag = 1;
					}
					else
					{
						flag = 0;
						break;
					}
				}

				if (flag == 1)
				{
					return now.time + 1;
				}
				
				q.push({ nextX, nextY, nextZ, now.time + 1});	
			}
			
		}
		q.pop();
	}

	return -1;
}

int main()
{
	int M, N, H;

	std::cin>>M>>N>>H;

	map.resize(H, std::vector< std::vector< int > >(N, std::vector< int >(M, 0)));

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M; k++)
			{
				std::cin >> map[i][j][k];
				if (map[i][j][k] == 1)
				{
					q.push({k,j,i,0});
				}
				if (map[i][j][k] == 0)
				{
					raw.push_back({ k,j,i,0 });
					count++;
				}
			}
		}
	}

	int result = bfs();
	std::cout << result << '\n';


	return 0;
}
#endif