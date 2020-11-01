#include <bits/stdc++.h>
using namespace std;
string str[105];
void judge(string needjudge, int n)
{
    cout << needjudge << endl;
    int totalnum=0;
    int yes = 0;
    for (int i = 0; i < n; i++)
    {
        if (needjudge == str[i])
        {
            yes = 1;
            break;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (yes == 1)
        {
            totalnum++;
            cout << "CORRECT" << endl;
            break;
        }
        if (needjudge.length() == str[i].length())
        {
            int sum=0;
            char ch11,ch12,ch21,ch22;
            for (int j = 0; j < needjudge.length(); j++)
            {
                if(needjudge[j]!=str[i][j])
                {
                    sum++;
                    if(sum==1)
                    {
                        ch11=needjudge[j];
                        ch12=str[i][j];
                    }
                    if(sum==2)
                    {
                        ch21=needjudge[j];
                        ch22=str[i][j];
                    }
                }
            }
            if(sum==1)
            {
                totalnum++;
                cout<<"ONE LETTER DIFFERENT FROM "<<str[i]<<endl;
            }
            if(sum==2)
            {
                if(ch11==ch22&&ch12==ch21)
                {
                    totalnum++;
                    cout<<"TWO LETTERS TRANSPOSED IN "<<str[i]<<endl;
                }
            }
        }
        if(needjudge.length()==(str[i].length()-1))
        {
            int p=0;
            for(int q=0;q<str[i].length();q++)
            {
                if(str[i][q]==needjudge[p])
                    p++;
            }
            if(p==(str[i].length()-1))
            {
                totalnum++;
                cout<<"ONE LETTER OMITTED FROM "<<str[i]<<endl;
            }
        }
        if(needjudge.length()==(str[i].length()+1))
        {
            int p=0;
            for(int q=0;q<needjudge.length();q++)
            {
                if(needjudge[q]==str[i][p])
                    p++;
            }
            if(p==(needjudge.length()-1))
            {
                totalnum++;
                cout<<"ONE LETTER ADDED TO "<<str[i]<<endl;
            }
        }
    }
    if(totalnum==0)
        cout<<"UNKNOWN"<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> str[i];
    }
    int x;
    cin >> x;
    string needjudge;
    while (x--)
    {
        cin >> needjudge;
        judge(needjudge, n);
        cout << endl;
    }
    return 0;
}
