#include <bits/stdc++.h>
using namespace std;
const int N = 6e4 + 5;
struct node
{
    char s[1005];
    int can, id, time;
    bool operator<(const node &a) const 
    {
        if (id == a.id)
            return time > a.time;
        return id > a.id;
    }
} num;
int main()
{
    priority_queue<node> q;
    char t[5];
    int cas = 1;
    while (~scanf("%s", t))
    {
        if (t[0] == 'G')
        {
            if (q.empty())
                printf("EMPTY QUEUE!\n");
            else
            {
                node tmp = q.top();
                q.pop();
                printf("%s %d\n", tmp.s, tmp.can);
            }
        }
        else if (t[0] == 'P')
        {
            scanf("%s", num.s);
            scanf("%d%d", &num.can, &num.id);
            num.time = cas++;
            q.push(num);
        }
    }
    return 0;
}