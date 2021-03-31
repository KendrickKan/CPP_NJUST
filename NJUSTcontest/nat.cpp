#include <bits/stdc++.h>
using namespace std;
#define FastIO ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
typedef long long ll;
const int MAXN = 200005;
int a[MAXN];
int main()
{
    FastIO;
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            string str;
            cin >> str;
            if (str[0] == 'n')
                a[i] = 0;
            else
            {
                int x = 0;
                for (int j = 2; j <= str.length() - 2; j++)
                {
                    x *= 10;
                    x += str[j] - '0';
                }
                a[i] = x;
            }
            //cout<<a[i]<<endl;
        }
        stack<int> st;
        bool flag = false;
        for (int i = 0; i < n; i++)
        {
            if (st.empty())
            {
                st.push(a[i]);
            }
            else
            {
                if (a[i] == 0)
                {
                stt:
                    if (st.empty() || st.top() == 0)
                    {
                        st.push(0);
                    }
                    else
                    {
                        int temp = st.top();
                        st.pop();
                        temp--;
                        if (temp == 0)
                            goto stt;
                        else
                            st.push(temp);
                    }
                }
                else
                {
                    if (!st.empty() && st.top() == 0)
                    {
                        flag = true;
                        goto stop;
                    }
                    st.push(a[i]);
                }
            }
        }
    stop:
        if (flag || (st.size() != 1 || st.top() != 0))
            cout << "Invalid" << endl;
        else
            cout << "Valid" << endl;
    }
    return 0;
}
