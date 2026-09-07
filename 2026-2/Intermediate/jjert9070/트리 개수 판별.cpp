#if 0
#include <iostream>
#include <vector>

struct Edge
{
	int vertex1;
	int vertex2;
};

int cycle = 0;
int edgeCount = 0;

int searchParent(std::vector< int >& parent, int x)
{
	int result;

	if (parent[x] == -1)
	{
		return x;
	}

	result = searchParent(parent, parent[x]);

	parent[x] = result;


	return result;
	
}

bool unionFind(std::vector< int >& parent,std::vector< Edge >& resultvec ,int vertex1, int vertex2)
{
	int v1Parent;
	int v2Parent;

	v1Parent = searchParent(parent, vertex1);
	v2Parent = searchParent(parent, vertex2);

	if (v1Parent == v2Parent)
	{
		cycle++;
		return false;
	}

	edgeCount++;
	parent[v1Parent] = v2Parent;
	resultvec.push_back({ vertex1, vertex2 });

	return true;
}


int main()
{
	std::ios::sync_with_stdio(NULL);
	std::cin.tie(0);
	int t = 1;
	while (true)
	{

		int n;
		int m;
		std::vector< Edge >edges;
		std::vector< Edge >resultvec;
		std::vector< int >parent;
		std::cin >> n >> m;
		if (n == 0 && m == 0)
		{
			break;
		}
		edges.assign(m, {});
		parent.assign(n, -1);

		for (size_t i = 0; i < edges.size(); i++)
		{
			int v1;
			int v2;
			std::cin >> v1 >> v2;
			Edge now;
			now.vertex1 = v1 - 1;
			now.vertex2 = v2 - 1;
			edges[i] = now;
		}


		for (size_t i = 0; i < edges.size(); i++)
		{
			unionFind(parent, resultvec, edges[i].vertex1, edges[i].vertex2);
		}


		int result;
		result = n - edgeCount - cycle;

		if (result > 1)
		{
			std::cout << "Case " << t << ": A forest of " << result << " trees." << '\n';
		}
		else if (result == 1)
		{
			std::cout << "Case " << t << ": There is one tree." << '\n';
		}
		else if (result <= 0)
		{
			std::cout << "Case " << t << ": No trees." << '\n';
		}

		edges.clear();
		resultvec.clear();
		parent.clear();

		edgeCount = 0;
		cycle = 0;
		t++;
	}


	return 0;

}
#endif