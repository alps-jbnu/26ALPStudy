#include <iostream>
#include <vector>

bool checkZero(std::vector<std::vector<int>>& grid, int n, int x ,int y)
{
    for(size_t i = 0; i < n; i++)
    {
        for(size_t j = 0; j < n; j++)
        {
            if(grid[y + i][x + j] == 1)
            {
                return false;
            }
        }
    }

    return true;
}

bool checkOne(std::vector<std::vector<int>>& grid, int n, int x, int y)
{
    for(size_t i = 0; i < n; i++)
    {
        for(size_t j = 0; j < n; j++)
        {
            if(grid[y + i][x + j] == 0)
            {
                return false;
            }
        }
    }

    return true;
}


void compress(std::vector<std::vector<int>>& grid, int n, int startX, int startY)
{
    if(n == 0)
    {
        return;
    }

    if(checkOne(grid, n, startX, startY) == true || checkZero(grid, n, startX, startY) == true)
    {
        std::cout<<grid[startY][startX];
        return;
    }
    else if(checkOne(grid, n, startX, startY) == false && checkZero(grid, n, startX, startY) == false)
    {
        std::cout<<"(";
        compress(grid, n / 2, startX, startY);
        compress(grid, n / 2, startX + n / 2, startY);
        compress(grid, n / 2, startX, startY + n / 2);
        compress(grid, n / 2, startX + n / 2, startY + n / 2);
        std::cout<<")";
    }
}



int main()
{
    std::ios::sync_with_stdio(NULL);
    std::cin.tie(0);

    int n;
    std::vector<std::vector<int>> grid;
    std::vector<std::string> str_vec;
    std::cin>>n;

    grid.resize(n, std::vector<int>(n, 0));

    str_vec.resize(n);
    for(size_t i = 0; i < n; i++)
    {
        std::cin>>str_vec[i];
    }

    for(size_t i = 0; i < n; i++)
    {
        for(size_t j = 0; j < n; j++)
        {
            grid[i][j] = str_vec[i][j] - '0';
        }
    }

    compress(grid, n, 0, 0);
    std::cout<<'\n';

    return 0;
}