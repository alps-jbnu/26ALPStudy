#include <iostream>
#include <vector>

std::vector<int> row;
std::vector<std::vector<int>> map;
std::vector<int> visited;
int count;

void preorder_traversal(int now, int level)
{
    if(level > count)
    {
        return;
    }

    std::cout<<(char)(now + 'A');
    
    for(size_t i = 0; i < count; i++)
    {
        if(map[now][i] == 1)
        {
            preorder_traversal(i, level+1);
        }
    }
}

void inorder_traversal(int now, int level)
{
    if(level > count)
    {
        return;
    }

    for(size_t i = 0; i < count; i++)
    { 
        if(map[now][i] == 1)
        {
            inorder_traversal(i, level+1);
            if(visited[now] == 0)
            {
                std::cout<<(char)(now + 'A');
                visited[now] = 1;
            }
        }
    }
}

void postorder_traversal(int now, int level)
{
    if(level > count)
    {
        return;
    }

    for(size_t i = 0; i < count; i++)
    {
        if(map[now][i] == 1)
        {
            postorder_traversal(i, level+1);        
        }
    }

    std::cout<<(char)(now + 'A');
}


int main()
{
    char parent, left, right;
    std::cin >> count;
    row.resize(count, 0);
    map.resize(count, row);
    visited.resize(count, 0);
    for(size_t i = 0; i < count; i++)
    {
        std::cin >> parent >> left >> right;
        if(left != '.' )
        {
            map[parent-'A'][left-'A'] = 1;
        }
        if(right != '.')
        {
            map[parent-'A'][right-'A'] = 1;
        }
    }

    preorder_traversal(0, 0);
    std::cout<<std::endl;


    inorder_traversal(0, 0);
    std::cout<<std::endl;

    postorder_traversal(0, 0);
    std::cout<<std::endl;

    return 0;
}