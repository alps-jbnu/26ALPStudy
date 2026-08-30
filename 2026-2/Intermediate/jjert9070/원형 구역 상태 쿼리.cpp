#include <iostream>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(NULL);
    std::cin.tie(0);
    std::vector<int> areas;
    int n;
    int q;
    int nowLocation = 0;
    std::cin>> n >> q;

    areas.resize(n);

    for(size_t i = 0; i < n; i++)
    {
        int now;
        std::cin>>now;

        areas[i] = now;
    }

    for(size_t i = 0; i < q; i++)
    {
        int query;
        std::cin>>query;

        if(query == 1)
        {
            int selectArea;
            std::cin>>selectArea;
            if(areas[selectArea - 1] == 0)
            {
                areas[selectArea - 1] = 1;
            }
            else if(areas[selectArea - 1] == 1)
            {
                areas[selectArea - 1] = 0;
            }
        }
        else if(query == 2)
        {
            int x;
            std::cin>>x;
            nowLocation = nowLocation + (x % areas.size());
        }
        else if(query == 3)
        {
            int count = 0;
            int flag = 0;
            for(size_t i = 0; count < areas.size();i++)
            {
                count++;
                if(areas[(nowLocation + i) % areas.size()] == 1)
                {
                    std::cout<<i<<'\n';
                    flag = 1;
                    break;
                }
            }

            if(flag == 0)
            {
                std::cout<<"-1"<<'\n';
            }

            flag = 0;
        }
    }



    return 0;
}