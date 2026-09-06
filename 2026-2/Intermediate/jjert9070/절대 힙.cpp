#if 0
#include <iostream>
#include <queue>

int main()
{
	std::ios::sync_with_stdio(NULL);
	std::cin.tie(0);
	//std::deque<int> resultdeque;

	std::priority_queue<int, std::vector<int>,
		decltype([](int& select_1, int& select_2)
			{
				if (abs(select_1) != abs(select_2))
				{
					if (abs(select_1) > abs(select_2))
					{
						return true;
					}
					return false;
				}
				else if (abs(select_1) == abs(select_2))
				{
					if (select_1 > select_2)
					{
						return true;
					}
					return false;
				}

			})> q;



	int n;
	int input_;
	int result;
	std::cin >> n;
	for (size_t i = 0; i < n; i++)
	{
		std::cin >> input_;
		if (input_ == 0)
		{
			if (q.empty())
			{
				//resultdeque.push_back(0);
				std::cout << "0" << '\n';
				continue;
			}
			result = q.top();
			std::cout << result << '\n';
			q.pop();
			//resultdeque.push_back(result);
		}
		else
		{
			q.push(input_);
		}
		
	}

	//std::cout << std::endl;
	//for (size_t i = 0; i < resultdeque.size(); i++)
	//{
	//	std::cout << resultdeque[i] << std::endl;
	//}






	return 0;

}
#endif