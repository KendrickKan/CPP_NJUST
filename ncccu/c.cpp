#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
struct kpeople
{
    string name;
    string id;
    double gpa;
    double jiascore;
    string school;
};
bool cmpgpa(kpeople a, kpeople b)
{
    return a.gpa > b.gpa;
}
bool cmpjiascore(kpeople a, kpeople b)
{
    return a.jiascore > b.jiascore;
}
bool cmphe(kpeople a, kpeople b)
{
    return (a.gpa + a.jiascore) > (b.gpa + b.jiascore);
}
kpeople temp[1005];
int main()
{
    int n, m;
    cin >> n >> m;
    int i = 0;
    for (i = 0; i < n; i++)
    {
        kpeople t;
        cin >> t.name;
        cin >> t.id;
        cin >> t.gpa;
        cin >> t.jiascore;
        cin >> t.school;
        temp[i] = t;
    }
    sort(temp, temp + n, cmpgpa);
    for (i = 0; i < m - 1; i++)
    {
        cout << temp[i].school << " ";
    }
    cout << temp[m - 1].school << endl;
    sort(temp, temp + n, cmpjiascore);
    for (i = 0; i < m - 1; i++)
    {
        cout << temp[i].id << " ";
    }
    cout << temp[m - 1].id << endl;
    sort(temp, temp + n, cmphe);
    for (i = 0; i < m - 1; i++)
    {
        cout << temp[i].name << " ";
    }
    cout << temp[m - 1].name << endl;
    return 0;
}