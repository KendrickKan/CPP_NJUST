#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100;
struct node
{
    char c;
    int f;
    string strf;
    int loc;
    node *leftc;
    node *rightc;
};
vector<node *> vec;
vector<node *> ans;
bool cmp(node *a, node *b)
{
    return a->f > b->f;
}
bool cmp2(node *a, node *b)
{
    return a->loc < b->loc;
}
void setHuffman(node *a)
{
    if (a->leftc != NULL)
    {
        a->leftc->strf = a->strf + '0';
        setHuffman(a->leftc);
    }
    if (a->rightc != NULL)
    {
        a->rightc->strf = a->strf + '1';
        setHuffman(a->rightc);
    }
    if (a->rightc == NULL && a->leftc == NULL)
        ans.push_back(a);
}
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        node *temp = new node;
        cin >> temp->c >> temp->f;
        temp->strf = "";
        temp->leftc = NULL;
        temp->rightc = NULL;
        temp->loc = i;
        vec.push_back(temp);
    }
    while (vec.size() > 1)
    {
        sort(vec.begin(), vec.end(), cmp);
        node *temp = new node;
        temp->c = '0';
        temp->f = vec[vec.size() - 1]->f + vec[vec.size() - 2]->f;
        temp->strf = "";
        temp->loc = -1;
        temp->leftc = vec[vec.size() - 2];
        temp->rightc = vec[vec.size() - 1];
        vec.pop_back();
        vec.pop_back();
        vec.push_back(temp);
    }
    setHuffman(vec[0]);
    sort(ans.begin(), ans.end(), cmp2);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i]->c << " " << ans[i]->strf << endl;
    }
}