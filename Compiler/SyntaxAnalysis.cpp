#include <bits/stdc++.h>
using namespace std;
struct State //状态集
{
    char state;
    vector<char> firsts; // first集
    int ifInferEmpty;    //是否能推导出空 0代表不能 1代表能 -1代表还没确定
    vector<int> statesIndex;
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
    int ifInferEmpty;      //该文法能否推导出空 0代表不能 1代表能 -1代表还没确定
};
vector<Grammar> grammars; //文法集合
struct Item               //项目
{
    vector<Grammar> grammars; //项目里面包含的文法
};
vector<Item> items;            //项目集
int isInStates(char ch);       //判断是否在状态里 存在则返回标号
bool isInInputs(char ch);      //判断是否在输入字符里
void getGrammar();             //读取文法
void showGrammars();           //展示文法
void showStats();              //展示状态
bool ifAllInferEmptyConfirm(); //是否所有的能否推导空都已经确定了
void ifInferEmpty();           //是否能推导出空 运行这个函数 直接让所有的状态是否能推导出空填入状态属性里
void getFirsts();              //得到每个状态的first集

int main()
{
    getGrammar();
    showGrammars();
    cout << "--------------------------------\n";
    showStats();
    cout << "--------------------------------\n";
    ifInferEmpty();
    cout << "--------------------------------\n";
    showStats();
}
int isInStates(char ch)
{
    for (int i = 0; i < states.size(); i++)
    {
        if (ch == states[i].state)
        {
            return i;
        }
    }
    return -1;
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
                gtemp.ifInferEmpty = -1;
                grammars.push_back(gtemp);
                State stemp;             //将该状态存在状态集里
                stemp.state = '$';       //其实这里也就是没有拓广的初态
                stemp.ifInferEmpty = -1; //状态能否推导出空 置-1
                stemp.statesIndex.push_back(num);
                states.push_back(stemp);
            }
            num++;
            Grammar gm;
            gm.str = line;
            gm.num = num;
            gm.index = 3; //在下标为3的前面 eg:S->afsba 此时应该在a的前面
            gm.ifUse = false;
            gm.searchCh.push_back('#');
            gm.ifInferEmpty = -1;
            grammars.push_back(gm);
            int tempLoc = isInStates(line[0]); //判断是否存在在现有状态中
            if (tempLoc == -1)                 //不存在现有状态中
            {
                State stemp;
                stemp.state = line[0];
                stemp.ifInferEmpty = -1; //状态能否推导出空 置-1
                stemp.statesIndex.push_back(num);
                states.push_back(stemp); //如果这个状态是'A'~'Z'之间，那么就认为是一个状态不是输入}
            }
            else //存在现有状态
            {
                states[tempLoc].statesIndex.push_back(num);
            }
            for (int i = 3; i < line.size(); i++)
            {

                if (!isInInputs(line[i]) && (line[i] < 'A' || line[i] > 'Z'))
                    inputs.push_back(line[i]); //存输入
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
void showStats()
{
    for (int i = 0; i < states.size(); i++)
    {
        cout << states[i].state << " ";
        cout << states[i].ifInferEmpty << " " << endl;
        for (int j = 0; j < states[i].statesIndex.size(); j++)
        {
            cout << states[i].statesIndex[j] << " ";
        }
        cout << endl;
    }
}
bool ifAllInferEmptyConfirm()
{
    for (int i = 0; i < states.size(); i++)
    {
        if (states[i].ifInferEmpty == -1)
            return false;
    }
    return true;
}
void ifInferEmpty()
{
    while (!ifAllInferEmptyConfirm())
    {
        for (int i = 0; i < states.size(); i++)
        {
            // bool notHaveInput = false;
            bool inferEmpty = false;
            // bool ifConfirmEveryNotInferEmpty = true;               //是否能确定每个都推不出空
            bool ifConfirm = false;                                //能否确定这个state 是 能推出 还是 不能推出,就是是否存在未知文法
            for (int j = 0; j < states[i].statesIndex.size(); j++) //遍历每个状态存在文法左边的文法下标
            {
                if (states[i].ifInferEmpty != -1) //这个状态能否推出空已经被确定了
                {
                    continue;
                }
                if (grammars[states[i].statesIndex[j]].ifInferEmpty == 1) //能直接通过文法判断  能推出空
                {
                    inferEmpty = true;
                }
                else if (grammars[states[i].statesIndex[j]].ifInferEmpty == 0) ////能直接通过文法判断  不能推出空 //感觉可以不用
                {
                }
                else if (grammars[states[i].statesIndex[j]].ifInferEmpty == -1) //不能通过文法判断能不能推出空
                {
                    ifConfirm = true;
                    bool ifTheGrammarInferEmpty = false;
                    bool ifTheGrammarNotConfirm = false;
                    for (int k = 3; k < grammars[states[i].statesIndex[j]].str.length(); k++)
                    {
                        char tt = grammars[states[i].statesIndex[j]].str[k];
                        if (isInInputs(grammars[states[i].statesIndex[j]].str[k]) && grammars[states[i].statesIndex[j]].str[k] != '@')
                        {
                            grammars[states[i].statesIndex[j]].ifInferEmpty = 0; //这个文法不能推出空
                            break;
                        }
                        else if (isInStates(grammars[states[i].statesIndex[j]].str[k]) != -1)
                        {
                            if (states[isInStates(grammars[states[i].statesIndex[j]].str[k])].ifInferEmpty == -1)
                            {
                                ifTheGrammarNotConfirm = true;
                            }
                            else if (states[isInStates(grammars[states[i].statesIndex[j]].str[k])].ifInferEmpty == 0)
                            {
                                grammars[states[i].statesIndex[j]].ifInferEmpty = 0; //这个文法不能推出空
                                // ifTheGrammarInferEmpty = false;
                                break;
                            }
                            else
                            {
                                ifTheGrammarInferEmpty = true;
                            }
                        }
                        else if (grammars[states[i].statesIndex[j]].str[k] == '@')
                        {
                            inferEmpty = 1; //文法能推出空 那么状态就能推出空
                        }
                    }
                    if (ifTheGrammarInferEmpty == true && ifTheGrammarNotConfirm == false && grammars[states[i].statesIndex[j]].ifInferEmpty == -1) //有推出空的且没有不能推出空的和没有不确定的
                    {
                        grammars[states[i].statesIndex[j]].ifInferEmpty = 1;
                    }
                    // if (grammars[states[i].statesIndex[j]].str.length() <= 4)
                    // {
                    //     int tempStateIndex = isInStates(grammars[states[i].statesIndex[j]].str[3]);
                    //     if (grammars[states[i].statesIndex[j]].str[3] == '@') //如果该文法能推导出空，则这个状态能推导出空
                    //     {
                    //         grammars[states[i].statesIndex[j]].ifInferEmpty = 1; //该文法能推导出空
                    //         inferEmpty = true;
                    //     }
                    //     else if (tempStateIndex == -1) // input 该文法不能推导出空
                    //     {
                    //         grammars[states[i].statesIndex[j]].ifInferEmpty = 0;
                    //     }
                    //     else
                    //     {
                    //         if (states[tempStateIndex].ifInferEmpty != 1)
                    //             ifConfirmEveryNotInferEmpty = false;
                    //         else
                    //         {
                    //             inferEmpty = true;
                    //         }
                    //     }
                    // }
                    // else
                    // {
                    //     for (int k = 3; k < grammars[states[i].statesIndex[j]].str.length(); k++)
                    //     {
                    //         int tempStateIndex = isInStates(grammars[states[i].statesIndex[j]].str[k]);   //判断这个字符是否是状态还是input 是状态就返回状态下标
                    //         if (tempStateIndex == -1 && grammars[states[i].statesIndex[j]].str[k] != '@') // input
                    //         {
                    //             grammars[states[i].statesIndex[j]].ifInferEmpty = 0; //该文法不能推导出空
                    //         }
                    //         else
                    //         {
                    //             if (states[tempStateIndex].ifInferEmpty != 1) //-1 0不知道 或者不能
                    //                 ifConfirmEveryNotInferEmpty = false;
                    //             // else
                    //             // {
                    //             //     inferEmpty = true;
                    //             // }
                    //         }
                    //     }
                    // }
                }
            }
            if (inferEmpty == true && states[i].ifInferEmpty == -1)
            {
                states[i].ifInferEmpty = 1;
                continue;
            }
            if (!ifConfirm && states[i].ifInferEmpty == -1)
            {
                states[i].ifInferEmpty = 0;
                continue;
            }
            // if (ifConfirmEveryNotInferEmpty == true && states[i].ifInferEmpty == -1)
            // {
            //     states[i].ifInferEmpty = 0;
            // }
        }
    }
}
void getFirsts()
{
    for (int i = 0; i < states.size(); i++)
    {
    }
}