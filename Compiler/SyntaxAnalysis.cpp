#include <bits/stdc++.h>
using namespace std;
struct State //状态集
{
    char state;
    vector<char> firsts; // first集
};
vector<State> states;
vector<char> inputs;
struct Grammar
{
    string str;            //文法
    vector<char> searchCh; //向前搜索符
    int index;             //·的下标
    int num;               //第几个文法
    bool ifUse;            //·移动时，是否已经被使用了
};
vector<Grammar> grammars; //文法集合
struct Item               //项目
{
    vector<Grammar> grammars; //项目里面包含的文法
};
vector<Item> items;       //项目集
bool isInStates(char ch); //判断是否在状态里
bool isInInputs(char ch); //判断是否在输入字符里
void getGrammar();        //读取文法
void showGrammars();      //展示文法
void getFirsts();         //得到每个状态的first集

int main()
{
    getGrammar();
    showGrammars();
}
bool isInStates(char ch)
{
    for (int i = 0; i < states.size(); i++)
    {
        if (ch == states[i].state)
        {
            return true;
        }
    }
    return false;
}
bool isInInputs(char ch)
{
    for (int i = 0; i < inputs.size(); i++)
    {
        if (ch == inputs[i])
        {
            return true;
        }
    }
    return false;
}
void getGrammar()
{
    ifstream fs("LexicalAnalysisOLD.txt");
    if (fs.is_open())
    {
        string line;
        int num = 0;
        while (getline(fs, line))
        {
            if (num == 0) //增加拓广文法
            {
                Grammar gtemp;
                string strtemp = "$->";
                strtemp += line[0]; //$代表拓广的初始状态
                gtemp.ifUse = false;
                gtemp.index = 3;
                gtemp.num = num;
                gtemp.searchCh.push_back('#');
                gtemp.str = strtemp;
                grammars.push_back(gtemp);
                State stemp;           //将该状态存在状态集里
                stemp.state = line[0]; //其实这里也就是没有拓广的初态
                states.push_back(stemp);
            }
            num++;
            Grammar gm;
            gm.str = line;
            gm.num = num;
            gm.index = 3; //在下标为3的前面 eg:S->afsba 此时应该在a的前面
            gm.ifUse = false;
            gm.searchCh.push_back('#');
            grammars.push_back(gm);
            for (int i = 0; i < line.size(); i++)
            {
                if (line[i] >= 'A' && line[i] <= 'Z')
                {
                    State stemp;
                    stemp.state = line[i];
                    states.push_back(stemp); //如果这个状态是'A'~'Z'之间，那么就认为是一个状态不是输入
                }
                else
                {
                    inputs.push_back(line[i]); //不是上面所述那么就是一个输入符
                }
            }
        }
        fs.close();
    }
    return;
}
void showGrammars()
{
    for (int i = 0; i < grammars.size(); i++)
    {
        cout << left << setw(10) << grammars[i].str;
        cout << grammars[i].num << " " << grammars[i].index << " " << grammars[i].ifUse << endl;
        for (int j = 0; j < grammars[i].searchCh.size(); j++)
            cout << grammars[i].searchCh[j] << " ";
        cout << endl;
    }
}
void getFirsts()
{
    for (int i = 0; i < states.size(); i++)
    {
        
    }
}