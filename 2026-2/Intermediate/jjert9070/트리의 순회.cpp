#if 0
#include <iostream>
#include <vector>

std::vector<int> row;
std::vector<std::vector<int>> map;

void preorder(int now)
{
	if (now == -1)
	{
		return;
	}

	std::cout << (char)(now + 'A');
	preorder(map[now][0]);
	preorder(map[now][1]);
	
}

void inorder(int now)
{
	if (now == -1)
	{
		return;
	}

	inorder(map[now][0]);
	std::cout << (char)(now + 'A');
	inorder(map[now][1]);
}

void postorder(int now)
{
	if (now == -1)
	{
		return;
	}

	postorder(map[now][0]);
	postorder(map[now][1]);
	std::cout << (char)(now + 'A');

}


int main()
{
	std::ios::sync_with_stdio(NULL);
	std::cin.tie(0);

	int nodeCount;
	std::cin >> nodeCount;
	row.resize(2, 0);
	map.resize(nodeCount, row);

	for (int i = 0; i < nodeCount; i++)
	{
		
		char parent, leftChild, rightChild;

		std::cin >> parent >> leftChild >> rightChild;

		if (leftChild != '.' && rightChild == '.')
		{
			map[parent - 'A'][0] = leftChild - 'A';
			map[parent - 'A'][1] = -1;
		}
		else if (leftChild == '.' && rightChild != '.')
		{
			map[parent - 'A'][0] = -1;
			map[parent - 'A'][1] = rightChild - 'A';
		}
		else if (leftChild != '.' && rightChild != '.')
		{
			map[parent - 'A'][0] = leftChild - (int)'A';
			map[parent - 'A'][1] = rightChild - (int)'A';
		}
		else if (leftChild == '.' && rightChild == '.')
		{
			map[parent - 'A'][0] = -1;
			map[parent - 'A'][1] = -1;
		}


	}


	preorder(0);
	std::cout << '\n';
	inorder(0);
	std::cout << '\n';
	postorder(0);
	std::cout << '\n';



	return 0;
}
#endif