#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
char a[25][25];
int findup(int i, int j, int kind)
{
    int upnum = 0;
    if (kind == 1)
    {
        while (i > 0)
        {
            i--;
            if (a[i][j] == 'x')
                upnum++;
            else
                break;
        }
    }
    else if (kind == 0)
    {
        while (i > 0)
        {
            i--;
            if (a[i][j] == 'o')
                upnum++;
            else
                break;
        }
    }
    return upnum;
}

int finddown(int i, int j, int kind)
{
    int upnum = 0;
    if (kind == 1)
    {
        while (i < 25)
        {
            i++;
            if (a[i][j] == 'x')
                upnum++;
            else
                break;
        }
    }
    else if (kind == 0)
    {
        while (i < 25)
        {
            i++;
            if (a[i][j] == 'o')
                upnum++;
            else
                break;
        }
    }
    return upnum;
}
int findleft(int i, int j, int kind)
{
    int upnum = 0;
    if (kind == 1)
    {
        while (j > 0)
        {
            j--;
            if (a[i][j] == 'x')
                upnum++;
            else
                break;
        }
    }
    else if (kind == 0)
    {
        while (j > 0)
        {
            j--;
            if (a[i][j] == 'o')
                upnum++;
            else
                break;
        }
    }
    return upnum;
}
int findright(int i, int j, int kind)
{
    int upnum = 0;
    if (kind == 1)
    {
        while (j < 25)
        {
            j++;
            if (a[i][j] == 'x')
                upnum++;
            else
                break;
        }
    }
    else if (kind == 0)
    {
        while (j < 25)
        {
            j++;
            if (a[i][j] == 'o')
                upnum++;
            else
                break;
        }
    }
    return upnum;
}
int findleftup(int i, int j, int kind)
{
    int upnum = 0;
    if (kind == 1)
    {
        while (i > 0 && j > 0)
        {
            i--;
            j--;
            if (a[i][j] == 'x')
                upnum++;
            else
                break;
        }
    }
    else if (kind == 0)
    {
        while (i > 0 && j > 0)
        {
            i--;
            j--;
            if (a[i][j] == 'o')
                upnum++;
            else
                break;
        }
    }
    return upnum;
}
int findrightup(int i, int j, int kind)
{
    int upnum = 0;
    if (kind == 1)
    {
        while (i > 0 && j < 25)
        {
            i--;
            j++;
            if (a[i][j] == 'x')
                upnum++;
            else
                break;
        }
    }
    else if (kind == 0)
    {
        while (i > 0 && j < 25)
        {
            i--;
            j++;
            if (a[i][j] == 'o')
                upnum++;
            else
                break;
        }
    }
    return upnum;
}
int findleftdown(int i, int j, int kind)
{
    int upnum = 0;
    if (kind == 1)
    {
        while (j > 0 && i < 25)
        {
            i++;
            j--;
            if (a[i][j] == 'x')
                upnum++;
            else
                break;
        }
    }
    else if (kind == 0)
    {
        while (j > 0 && i < 25)
        {
            i++;
            j--;
            if (a[i][j] == 'o')
                upnum++;
            else
                break;
        }
    }
    return upnum;
}
int findrightdown(int i, int j, int kind)
{
    int upnum = 0;
    if (kind == 1)
    {
        while (j < 25 && i < 25)
        {
            i++;
            j++;
            if (a[i][j] == 'x')
                upnum++;
            else
                break;
        }
    }
    else if (kind == 0)
    {
        while (i < 25 && j < 25)
        {
            i++;
            j++;
            if (a[i][j] == 'o')
                upnum++;
            else
                break;
        }
    }
    return upnum;
}
bool cmpv(pair<int, int> a, pair<int, int> b)
{
    if (a.first != b.first)
        return a.first < b.first;
    else
        return a.second < b.second;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int hei = 0, bai = 0;
    for (int i = 0; i < 25; i++)
        for (int j = 0; j < 25; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 'x')
                hei++;
            else if (a[i][j] == 'o')
                bai++;
        }
    int kind = 1;
    if (hei == bai)
        kind = 1;
    else
        kind = 0;
    pair<int, int> vec[626];
    int x = 0;
    for (int i = 0; i < 25; i++)
        for (int j = 0; j < 25; j++)
        {
            if (a[i][j] != 'x' && a[i][j] != 'o' && ((findup(i, j, kind) + finddown(i, j, kind) >= 4) || (findleft(i, j, kind) + findright(i, j, kind) >= 4) || (findleftup(i, j, kind) + findrightdown(i, j, kind) >= 4) || (findrightup(i, j, kind) + findleftdown(i, j, kind) >= 4)))
            {
                vec[x].first = i;
                vec[x].second = j;
                x++;
            }
        }
    if (x == 0)
        cout << "tie";
    else
    {
        sort(vec, vec + x, cmpv);
        for (int i = 0; i < x - 1; i++)
            cout << vec[i].first << ' ' << vec[i].second << endl;
        cout << vec[x - 1].first << ' ' << vec[x - 1].second;
    }
    return 0;
}