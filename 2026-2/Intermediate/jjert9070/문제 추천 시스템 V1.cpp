#include <iostream>
#include <map>

void deleteNodes(std::map<int, int>& nodes, int problemNumber)
{
    if(nodes.empty())
    {
        return;
    }

    int targetKey;

    for(auto& select : nodes)
    {
        if(select.second == problemNumber)
        {
            targetKey = select.second;
            break;
        }
    }







}

void pushNodes(std::map<int, int>& nodes, const std::pair<int, int> inputNode)
{
    nodes.insert(inputNode);
}


std::pair<int, int> getMax(const std::map<int, int>& nodes)
{
    if(nodes.empty())
    {
        return {};
    }

    std::pair<int, int> result;

    result = *nodes.rbegin();

    return result;
}




std::pair<int, int> getMin(const std::map<int, int>& nodes)
{
    if(nodes.empty())
    {
        return {};
    }

    std::pair<int, int> result;

    result = *nodes.begin();

    return result;
}


std::pair<int, int> recommendation(std::map<int, int>& nodes, int x)
{
    std::pair<int, int> result;
    if(x == 1)
    {
        result = getMax(nodes);
    }
    else if(x == -1)
    {
        result = getMax(nodes);
    }

    return result;
}

int main()
{
    int n;

    int m;




    std::map<int, int> nodes;

    std::cin>>n;

    for(size_t i = 0; i < n; i++)
    {
        int p;
        int l;

        std::cin>>p>>l;
        nodes.insert({l, p});
    }



    for(size_t i = 0; i < m; i++)
    {
        std::string command;
        std::cin>>command;

        if(command.compare("recommend") == 0)
        {
            std::pair<int, int> result;
            int x;

            std::cin>>x;

            result = recommendation(nodes, x);
            std::cout<<result.second<<'\n';
        }
        else if(command.compare("add"))
        {
            int p;
            int l;
            std::cin>>p>>l;

            pushNodes(nodes, {l, p});
        }
        else if(command.compare("solved") == 0)
        {
            int p;
            std::cin>>p;


        }
    }


}