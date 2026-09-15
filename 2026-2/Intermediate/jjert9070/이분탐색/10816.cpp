#include <iostream>
#include <vector>
#include <algorithm>

int firstCard(std::vector<int>& cards, int target)
{
    int startIndex = 0;
    int endIndex = cards.size() - 1;
    int midIndex;
    int result;

    while(startIndex <= endIndex)
    {
        midIndex = (startIndex + endIndex) / 2;

        if(cards[midIndex] < target)
        {
            startIndex = midIndex + 1;
        }
        else if(cards[midIndex] >= target)
        {
            endIndex = midIndex - 1;
        }
    }

    return startIndex;
}

int lastCard(std::vector<int>& cards, int target)
{
    int startIndex = 0;
    int endIndex = cards.size() - 1;
    int midIndex;
    int result;

    while(startIndex <= endIndex)
    {
        midIndex = (startIndex + endIndex) / 2;

        if(cards[midIndex] <= target)
        {
            startIndex = midIndex + 1;
        }
        else if(cards[midIndex] > target)
        {
            endIndex = midIndex - 1;
        }
    }

    return startIndex;
}


int main()
{
    std::ios::sync_with_stdio(NULL);
    std::cin.tie(0);
    
    int n;
    int m;
    std::vector<int> cards;
    std::vector<int> query;

    std::cin>>n;
    cards.resize(n);

    for(size_t i = 0; i < n; i++)
    {
        std::cin>>cards[i];
    }

    std::sort(cards.begin(), cards.end());

    std::cin>>m;
    query.resize(m);

    for(size_t i = 0; i < query.size(); i++)
    {
        std::cin>>query[i];
    }

    for(size_t i = 0; i < query.size(); i++)
    {
        int result = lastCard(cards, query[i]) - firstCard(cards, query[i]);
        std::cout<<result<<" ";
    }

    std::cout<<'\n';

    return 0;

}