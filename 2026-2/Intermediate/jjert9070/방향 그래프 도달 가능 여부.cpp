#if 0
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

struct Node
{
	int vertex;
	int length;
};

std::vector<bool> dfsVisit;
int dfs(std::vector< std::vector<int> >& map, int now, int end, int level)
{
	int count = 0;
	if (level > 0 && now == end)
	{
		return 1;
	}

	for (size_t i = 0; i < map.size(); i++)
	{
		
		if (map[now][i] == 1 && dfsVisit[i] == false)
		{
			dfsVisit[i] = true;
			count += dfs(map, i, end, level+1);

		}

	}

	return count;
}


Node bfs(std::vector< std::vector<int> >& map, int start_vertex, int end_vertex)
{
	if (start_vertex == end_vertex)
	{
		dfsVisit.assign(map.size(), false);
		int result = dfs(map, start_vertex, end_vertex, 0);
		if (result > 0)
		{
			return { start_vertex, 1 };
		}
	}

	std::vector<bool> visit(map.size(), false);
	std::queue<Node>q;
	visit[start_vertex] = 1;
	q.push({ start_vertex, 1});

	while (!q.empty())
	{
		Node now = q.front();

		for (int i = 0; i < map.size(); i++)
		{
			if (visit[i] == true)
			{
				continue;
			}

			if (map[now.vertex][i] == 1)
			{
				visit[i] = true;
				Node next;
				next.vertex = i;
				next.length = now.length + 1;
				
				if (i == end_vertex)
				{
					return {i, next.length};
				}
				
				q.push(next);
			}

		}

		q.pop();


	}

	return {-1,0};
}

int main()
{
	std::ios::sync_with_stdio(NULL);
	std::cin.tie(0);

	std::vector< std::vector<int> >map;
	int n;
	std::cin >> n;
	map.resize(n, std::vector<int>(n, 0));
	dfsVisit.resize(n, false);
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			std::cin >> map[i][j];

		}
	}

	std::vector< std::vector<int> >resultMap(n, std::vector<int>(n, 0));
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			Node result = bfs(map, i, j);
			if (result.length == 0)
			{
				continue;
			}
			resultMap[i][j] = 1;

		}
	}

	std::cout << '\n';


	
	std::for_each(resultMap.begin(), resultMap.end(),
		[](auto& row)
		{
			std::for_each(row.begin(), row.end(),
				[](auto& col)
				{
					std::cout << col << " ";
				});
			std::cout << '\n';
		});


	return 0;


}
#endif