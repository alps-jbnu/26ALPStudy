#include <iostream>
#include <set>

int main()
{
    std::ios::sync_with_stdio(NULL);
    std::cin.tie(0);
    std::set<int> areas;
    int n;
    int q;
    int nowLocation = 0;
    std::cin>> n >> q;

    for(size_t i = 0; i < n; i++)
    {
        int now;
        std::cin>>now;

        if(now == 1)
        {
            areas.insert(i);
        }
    }

    for(size_t i = 0; i < q; i++)
    {
        int query;
        std::cin>>query;

        if(query == 1)
        {
            int selectArea;
            std::cin>>selectArea;
            if(areas.find(selectArea - 1) == areas.end())
            {
                areas.insert(selectArea - 1);
            }
            else if(areas.find(selectArea - 1) != areas.end())
            {
                areas.erase(selectArea - 1);
            }
        }
        else if(query == 2)
        {
            int x;
            std::cin>>x;
            nowLocation = nowLocation + (x % n);
        }
        else if(query == 3)
        {
            if(areas.empty())
            {
                std::cout<<"-1"<<'\n';
            }
            else
            {
                if(areas.lower_bound(nowLocation) == areas.end())
                {
                    int startLocation = 0;
                    int targetLocation;
                    int length = 0;

                    targetLocation = *(areas.lower_bound(startLocation));

                    length = (n - nowLocation) + (targetLocation - startLocation);

                    std::cout<<length<<'\n';


                }
                else
                {
                    int targetLocation;
                    int length;

                    targetLocation = *(areas.lower_bound(nowLocation));
                    length = targetLocation - nowLocation;

                    std::cout<<length<<'\n';
                }
            }
        }
    }



    return 0;
}