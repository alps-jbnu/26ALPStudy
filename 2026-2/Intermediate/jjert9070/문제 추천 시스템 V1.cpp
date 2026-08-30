#include <iostream>
#include <unordered_map>
#include <map>


void pushNode(std::map<std::pair<int, int>, bool>& nodes, std::unordered_map<int, std::pair<int, int>>& keyMap, std::pair<int, int> inputKey)
{
    nodes.insert({inputKey, true});
    keyMap[inputKey.second] = inputKey; 
}


void deleteNodes(std::map<std::pair<int, int>, bool>& nodes, std::unordered_map<int, std::pair<int, int>>& keyMap, int problemNumber)
{
    if(nodes.empty())
    {
        return;
    }

    nodes.erase(keyMap.at(problemNumber));
    keyMap.erase(problemNumber);

}




std::pair<int, int> getMax(const std::map<std::pair<int, int>, bool>& nodes)
{
    if(nodes.empty())
    {
        return {};
    }

    std::pair<int, int> result;

    result = (*nodes.rbegin()).first;

    return result;
}




std::pair<int, int> getMin(const std::map<std::pair<int, int>, bool>& nodes)
{
    if(nodes.empty())
    {
        return {};
    }

    std::pair<int, int> result;

    result = (*nodes.begin()).first;

    return result;
}


std::pair<int, int> recommendation(std::map<std::pair<int, int>, bool>& nodes, int x)
{
    std::pair<int, int> result;
    if(x == 1)
    {
        result = getMax(nodes);
    }
    else if(x == -1)
    {
        result = getMin(nodes);
    }

    return result;
}


int main()
{
    std::ios::sync_with_stdio(NULL);
    std::cin.tie(0);
    int n;

    int m;

    std::map<std::pair<int, int>, bool> nodes;
    std::unordered_map<int, std::pair<int, int>> keyMap;

    std::cin>>n;

    for(size_t i = 0; i < n; i++)
    {
        int p;
        int l;

        std::cin>>p>>l;
        pushNode(nodes, keyMap, {l, p});

    }


    std::cin>>m;

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
        else if(command.compare("add") == 0)
        {
            int p;
            int l;
            std::cin>>p>>l;
            pushNode(nodes, keyMap, {l, p});

            
        }
        else if(command.compare("solved") == 0)
        {
            int p;
            std::cin>>p;
            deleteNodes(nodes, keyMap, p);
        }
    }

    return 0;
}