#if 0
#include <iostream>
#include <deque>
#include <algorithm>

std::deque<int> arr;

int main()
{
	std::ios::sync_with_stdio(NULL);
	std::cin.tie(0);
	int t;
	std::cin >> t;
	while (t > 0)
	{
		std::string func;
		std::cin >> func;
		int length;
		std::cin >> length;
		arr.resize(length, 0);

		char left;
		char right;
		int flag = 0;
		std::cin >> left;
		for (size_t i = 0; i < length; i++)
		{
			if (left == 0)
			{
				arr.clear();
				arr.resize(0, 0);
				break;
			}
			std::cin >> arr[i] >> right;
		}

		for (size_t i = 0; i < func.size(); i++)
		{
			if (func[i] == 'R')
			{
				std::reverse(arr.begin(), arr.end());
			}
			else if (func[i] == 'D')
			{
				if (arr.empty())
				{
					std::cout << "error" << std::endl;
					flag = 1;
					break;
				}
				else
				{
					arr.pop_front();
				}
			}
		}

		if (flag == 0)
		{
			std::cout << "[";
			for (size_t i = 0; i < arr.size(); i++)
			{
				std::cout << arr[i];
				if (i == arr.size() - 1)
				{
					break;
				}
				else
				{
					std::cout << ",";
				}
			}
			std::cout << "]";
			std::cout << std::endl;
		}
		else if (flag == 1)
		{
			flag = 0;
		}
		t--;
	}


	return 0;
}
#endif
