#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    stack<int> num;
    stack<char> ch;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        num.push(x);
    }
    for (int i = 0; i < n - 1; i++)
    {
        char t;
        cin >> t;
        ch.push(t);
    }
    bool flag = false;
    while (num.size() != 1)
    {
        int b = num.top();
        num.pop();
        int a = num.top();
        num.pop();
        char c = ch.top();
        ch.pop();
        if (c == '+')
            num.push(a + b);
        else if (c == '-')
            num.push(a - b);
        else if (c == '*')
            num.push(a * b);
        else
        {
            if (b == 0)
            {
                cout << "ERROR: " << a << "/" << b << endl;
                flag = true;
                break;
            }
            else
                num.push(a / b);
        }
    }
    if (!flag)
        cout << num.top() << endl;
    return 0;
}