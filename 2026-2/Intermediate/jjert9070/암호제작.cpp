#if 0
#include <iostream>
#include <algorithm>
char* str;
int* flag;
int count = 0;
std::string result = "";
int consonantsCount = 0;
int vowelCount = 0;

void dfs(int level, int L, int C)
{
	if (level == C)
	{
		for (size_t i = 0; i < C; i++)
		{
			if (*(flag + i) == 1)
			{
				count++;
				result += str[i];

			}
		}
		
		if (count == L)
		{
			// 모음 판별
			for (char ch : result)
			{

				bool isConsonants = true;

				for (char vowel : {'a', 'e', 'i', 'o', 'u'})
				{
					if (ch == vowel)
					{
						isConsonants = false;
						vowelCount++;
						break;
					}
				}

				if (isConsonants == true)
				{
					consonantsCount++;
				}
			}
		}

		if (vowelCount >= 1 && consonantsCount >= 2 && count == L)
		{
			std::sort(result.begin(), result.end());
			std::cout << result << std::endl;
		}

		result.clear();
		consonantsCount = 0;
		vowelCount = 0;
		count = 0;
		return;
	}

	for (int i = 1; i >= 0; i--)
	{
		flag[level] = i;
		dfs(level + 1, L, C);
		flag[level] = 0;
	}

}


int main()
{
	int L, C;
	std::cin >> L >> C;

	flag = new int[C];
	str = new char[C];

	for (size_t i = 0; i < C; i++)
	{
		std::cin >> str[i];
	}
	std::sort(str, str + C);
	dfs(0, L, C);

	delete[] flag;
	delete[] str;

	return 0;

}
#endif