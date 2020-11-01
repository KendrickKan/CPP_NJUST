#include <iostream>
using namespace std;
struct people
{
    int beginbianhao;
    int live;
};
int main()
{
    int N;
    cin >> N;
    while (N--)
    {
        int x;
        cin >> x;
        people a[10000];
        for (int i = 0; i < x; i++)
        {
            a[i].beginbianhao = i + 1;
            a[i].live = 1;
        }
        int restpeople = x;
        int judge2or3 = 2;
        while (restpeople > 3)
        {
            if (judge2or3 == 2)
            {
                int flag = 1;
                for (int i = 0; i < x; i++)
                {
                    if (a[i].live == 1 && flag == 1)
                        flag = 2;
                    else if (a[i].live == 1 && flag == 2)
                    {
                        a[i].live = 0;
                        flag = 1;
                        restpeople--;
                    }
                }
                judge2or3 = 3;
            }
            else
            {
                int flag = 1;
                for (int i = 0; i < x; i++)
                {
                    if (a[i].live == 1 && flag == 1)
                        flag = 2;
                    else if (a[i].live == 1 && flag == 2)
                        flag = 3;
                    else if (a[i].live == 1 && flag == 3)
                    {
                        a[i].live = 0;
                        flag = 1;
                        restpeople--;
                    }
                }
                judge2or3 = 2;
            }
        }
        int l = 1;
        for (int i = 0; i < x; i++)
        {
            if (a[i].live == 1 && l != restpeople)
            {
                cout << a[i].beginbianhao << ' ';
                l++;
            }
            else if (a[i].live == 1)
                cout << a[i].beginbianhao << endl;
        }
    }
    return 0;
}