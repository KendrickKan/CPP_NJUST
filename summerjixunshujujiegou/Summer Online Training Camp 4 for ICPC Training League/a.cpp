#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#include <stack>
#include <cctype>
using namespace std;
struct node
{
    char data;
    int l, r;
};
string s;
node arr[20001];
char ans[20001];
int cnt = 0;
void bfs(int root)
{
    queue<int> q;
    q.push(root);
    ans[cnt++] = arr[root].data;
    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        if (arr[t].l != -1)
        {
            ans[cnt++] = arr[arr[t].l].data;
            q.push(arr[t].l);
        }
        if (arr[t].r != -1)
        {
            ans[cnt++] = arr[arr[t].r].data;
            q.push(arr[t].r);
        }
    }
}
void solve()
{
    stack<int> st;
    int len = s.size();
    for (int i = 0; i < len; i++)
    {
        if (islower(s[i]))
        { 
            st.push(i);
            arr[i].data = s[i];
            arr[i].l = arr[i].r = -1;
        }
        else
        { 
            int R = st.top();
            st.pop();
            int L = st.top();
            st.pop();
            arr[i].data = s[i];
            arr[i].l = L;
            arr[i].r = R;
            st.push(i);
        }
    }
    cnt = 0;
    bfs(st.top());
    for (int i = cnt - 1; i >= 0; i--)
        cout << ans[i];
    cout << endl;
}
int main()
{
    int t;
    cin.sync_with_stdio(false);
    cin >> t;
    while (t--)
    {
        cin >> s;
        solve();
    }
    return 0;
}