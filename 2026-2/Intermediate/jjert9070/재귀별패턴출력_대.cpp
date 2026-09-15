#include <iostream>
#include <vector>

std::vector<std::vector<char>> getShape()
{
    std::vector<std::vector<char>> pattern;

    pattern.resize(3, std::vector<char>(3, ' '));

    for(size_t i = 0; i < 3; i++)
    {
        pattern[0][i] = '*';
    }

    pattern[1][0] = '*';
    pattern[1][2] = '*';

    for(size_t i = 0; i < 3; i++)
    {
        pattern[2][i] = '*';
    }


    return pattern;
}


std::vector<std::vector<char>> output(std::vector<std::vector<char>>& input_pattern,int start, int end)
{
    std::vector<std::vector<char>> pattern;

    if(start == end)
    {
        return input_pattern;
    }

    pattern.assign(start * 3, std::vector<char>(start * 3, ' '));

    for(size_t i = 0; i < 3; i++)
    {
        for(size_t j = 0; j < input_pattern.size(); j++)
        {
            for(size_t m = 0; m < input_pattern.size(); m++)
            {
                pattern[j][input_pattern.size() * i + m] = input_pattern[j][m];
            }
        }
    }

    for(size_t j = 0; j < input_pattern.size(); j++)
    {
        for(size_t m = 0; m < input_pattern.size(); m++)
        {
            pattern[input_pattern.size() + j][0 + m] = input_pattern[j][m];
        }
    }

    for(size_t j = 0; j < input_pattern.size(); j++)
    {
        for(size_t m = 0; m < input_pattern.size(); m++)
        {
            pattern[input_pattern.size() + j][2 * input_pattern.size() + m] = input_pattern[j][m];
        }
    }

    for(size_t i = 0; i < 3; i++)
    {
        for(size_t j = 0; j < input_pattern.size(); j++)
        {
            for(size_t m = 0; m < input_pattern.size(); m++)
            {
                pattern[2*input_pattern.size() + j][input_pattern.size() * i + m] = input_pattern[j][m];
            }
        }
    }

    return output(pattern, start * 3, end);
}

void printGrid(std::vector<std::vector<char>>& grid)
{
    for(size_t i = 0; i < grid.size(); i++)
    {
        for(size_t j = 0; j < grid.size(); j++)
        {
            std::cout<<grid[i][j];
        }
        std::cout<<'\n';
    }

}



int main()
{
    std::ios::sync_with_stdio(NULL);
    std::cin.tie(0);
    std::vector<std::vector<char>> grid;
    std::vector<std::vector<char>> pattern;
    int n;
    std::cin>>n;

    grid.resize(n, std::vector<char>(n, ' '));

    pattern = getShape();
    grid = output(pattern, 3, n);

    printGrid(grid);



    return 0;
}