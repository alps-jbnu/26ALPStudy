#if 0
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>
std::vector<std::vector<int>>map;
std::vector<std::vector<int>>input_map;
std::vector<int>inputs;
std::vector<int>board;

void djikstra(int start)
{
	std::vector<int>visit(map.size(), 0);

	for (size_t i = 0; i < map.size(); i++)
	{
		if (i == start)
		{
			visit[start] = 1;
			board[i] = 0;
		}
		else if (map[start][i] == 1 && visit[i] == 0)
		{
			board[i] = 1;
		}
	}

	while (true)
	{
		int min_index = -1;
		int min_value = INT_MAX;
		for (size_t i = 0; i < board.size(); i++)
		{
			if (board[i] == -1)
			{
				continue;
			}

			if (visit[i] == 0 && board[i] < min_value)
			{
				min_value = board[i];
				min_index = i;
			}
		}

		if (min_value == INT_MAX && min_index == -1)
		{
			break;
		}

		visit[min_index] = 1;
		for (size_t i = 0; i < map.size(); i++)
		{
			if (visit[i] == 0 && map[min_index][i] == 1)
			{
				if (board[i] == -1)
				{
					board[i] = board[min_index] + map[min_index][i];
				}
				else if (board[i] != -1 && board[min_index] + map[min_index][i] < board[i])
				{
					board[i] = board[min_index] + map[min_index][i];
				}
			}
		}

	}
}

int main()
{
	std::ios::sync_with_stdio(NULL);
	std::cin.tie(0);
	int n;
	int k;
	int m;
	std::cin >> n >> k >> m;

	map.resize(n, std::vector<int>(n, 0));
	input_map.resize(n, std::vector<int>(n, 0));
	inputs.resize(k, 0);

	board.resize(n, -1);

	for (size_t i = 0; i < m; i++)
	{
		int vertex;
		for (size_t j = 0; j < k; j++)
		{
			std::cin >> vertex;
			inputs[j] = vertex - 1;
		}

		for (size_t u = 0; u < k-1; u++)
		{
			input_map[inputs[u]][inputs[u + 1]] = 1;
		}
		input_map[inputs[0]][inputs[k-1]] = 1;
		input_map[inputs[k-1]][inputs[0]] = 1;

		std::fill(inputs.begin(), inputs.end(), 0);
	}

	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			map[i][j] = input_map[i][j] | input_map[j][i];
		}
	}



	djikstra(0);



	if (board[n-1] == -1)
	{
		std::cout << "-1" << '\n';
	}
	else
	{
		std::cout << board[n - 1] + 1 << '\n';
	}


	return 0;


}
#endif
