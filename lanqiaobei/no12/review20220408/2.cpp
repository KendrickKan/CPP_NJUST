#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main()
{
    vector<pair<int, int>> vec;
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 21; j++)
        {
            vec.push_back(pair<int, int>(i, j));
        }
    }
    int num = vec.size();
    set<pair<double, double>> line;
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num; j++)
        {
            if (vec[i].first != vec[j].first && vec[i].second != vec[j].second)
            {
                double k = (vec[i].second - vec[j].second) * 1.0 / (vec[i].first - vec[j].first);
                double b = (vec[j].second * (vec[j].first - vec[i].first) - (vec[j].second - vec[i].second) * vec[j].first) * 1.0 / (vec[j].first - vec[i].first);
                //double b = vec[j].second - k * vec[j].first;
                line.insert(pair<double, double>(k, b));
            }
        }
    }
    cout << line.size() + 20 + 21;
    return 0;
}