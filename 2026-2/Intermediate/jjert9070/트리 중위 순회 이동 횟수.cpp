#if 0
#include <iostream>
#include <vector>

int count = 0;
bool traval(std::vector< std::vector< int > >& nodes, int now, int target)
{
	bool status = false;
	if (nodes[now][0] != -1)
	{
		count++;
		status = traval(nodes, nodes[now][0], target);
		if (status == true)
		{
			return true;
		}
	}

	if (now == target)
	{
		return true;
	}

	if (nodes[now][1] != -1)
	{
		count++;
		status = traval(nodes, nodes[now][1], target);
		if (status == true)
		{
			return true;
		}
	}

	count++;
	return false;
}




std::vector< int > inorderNodes;
void searchleafNode(std::vector< std::vector< int > >& nodes, int now)
{
	if (nodes[now][0] != -1)
	{
		searchleafNode(nodes, nodes[now][0]);
	}

	inorderNodes.push_back(now);

	if (nodes[now][1] != -1)
	{
		searchleafNode(nodes, nodes[now][1]);
	}

}



int main()
{
	std::ios::sync_with_stdio(NULL);
	std::cin.tie(0);
	int n;
	std::vector< std::vector< int > > nodes;
	std::vector< int > parents;
	
	std::cin >> n;

	nodes.resize(n, std::vector<int>(2, -1));
	parents.resize(n, -1);

	for (size_t i = 0; i < n; i++)
	{
		int parentNode;
		int leftChild;
		int rightChild;

		std::cin >> parentNode >> leftChild >> rightChild;

		if (leftChild != -1 && rightChild != -1)
		{
			nodes[parentNode - 1][0] = leftChild - 1;
			nodes[parentNode - 1][1] = rightChild - 1;
			parents[leftChild - 1] = parentNode - 1;
			parents[rightChild - 1] = parentNode - 1;
		}
		else if (leftChild != -1 && rightChild == -1)
		{
			nodes[parentNode - 1][0] = leftChild - 1;
			parents[leftChild - 1] = parentNode - 1;
		}
		else if (leftChild == -1 && rightChild != -1)
		{
			nodes[parentNode - 1][1] = rightChild - 1;
			parents[rightChild - 1] = parentNode - 1;
		}
	}


	int root = 0;
	for (size_t i = 0; i < parents.size(); i++)
	{
		if (parents[i] == -1)
		{
			root = i;
			break;
		}
	}

	searchleafNode(nodes, root);

	traval(nodes, root, inorderNodes[inorderNodes.size() - 1]);

	std::cout << count << '\n';




	return 0;
}
#endif