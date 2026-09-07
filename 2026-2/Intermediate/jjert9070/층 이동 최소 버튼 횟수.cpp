#if 0
#include <iostream>
#include <vector>
#include <queue>



std::vector < int > buildingFloor;
std::vector < int > visited;

struct Info
{
	int x;
	int count;
};
std::queue < Info > q;
int direct[2];

int BFS()
{
	while (!q.empty())
	{
		Info now = q.front();
		if (buildingFloor[now.x] == 1)
		{
			return now.count;
		}

		for (size_t i = 0; i < 2; i++)
		{
			if (now.x + direct[i] < 0 || now.x + direct[i] >= buildingFloor.size())
			{
				continue;
			}
			if (visited[now.x + direct[i]] == 1)
			{
				continue;
			}
			visited[now.x + direct[i]] = 1;
			q.push({now.x + direct[i], now.count+1});
		}
		q.pop();

	}

	return -1;
}


int main()
{
	std::ios::sync_with_stdio(NULL);
	std::cin.tie(NULL);
	int F, S, G, U, D;
	int result;
	std::cin >> F >> S >> G >> U >> D;

	buildingFloor.resize(F, 0);
	visited.resize(F, 0);

	visited[S - 1] = 1;
	q.push({S-1, 0});
	direct[0] = U;
	direct[1] = -1 * D;
	buildingFloor[G - 1] = 1;
	result = BFS();

	if (result == -1)
	{
		std::cout << "use the stairs" << '\n';
	}
	else
	{
		std::cout << result << '\n';
	}



	return 0;
}
#endif