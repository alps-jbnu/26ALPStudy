#if 0
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

struct Node
{
	unsigned long money;
	unsigned long day;
};

std::vector<Node> nodes;
// 최소 힙
std::priority_queue<
	Node, 
	std::vector<Node>, 
	decltype([](Node& select_1, Node& select_2)
	{

	})
> schedule;

int days[10001] = {};
unsigned int total = 0;


int main()
{
	std::ios::sync_with_stdio(NULL);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	unsigned long n;

	std::cin >> n;

	for (int i = 0; i < n; i++)
	{
		unsigned long d, p;
		std::cin >> p >> d;
		nodes.push_back({ p, d });
	}

	std::for_each(nodes.begin(), nodes.end(),
		[](Node& select)
		{
			schedule.push(select);
		});


	while (!schedule.empty())
	{
		Node now = schedule.top();
		schedule.pop();

		if (days[now.day] == 1)
		{
			continue;
		}

		total = total + now.money;
		days[now.day] = 1;
	}

	std::cout << total << '\n';




	return 0;
}
#endif