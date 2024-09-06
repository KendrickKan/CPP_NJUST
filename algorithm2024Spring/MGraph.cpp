#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
bool f[105][105];//存两个点是否连通
int color[105];//存每个点的颜色
int num=0;
int n,k,m;
bool check(int sum){
    for(int i=1;i<=sum;i++){
        if(f[i][sum]==true&&color[i]==color[sum]){
            return false;
        }
    }
    return true;
}//这里是判断冲突的核心，当两个图连通时且颜色一样就冲突
void dfs(int s){
    if(s>n){
        num++;//搜到n+1个点，也就是走完了
        return;
    }
    for(int i=1;i<=m;i++){
        color[s]=i;//把颜色存下来
        if(check(s)==true){
            dfs(s+1);
        }else{
            color[s]=0;//如果冲突则重新打回0
        }
    }
}        
int main(){
    cin>>n>>k>>m;
    for(int i=1;i<=k;i++){
        int x,y;
        cin>>x>>y;
        f[x][y]=true;
        f[y][x]=true;
    }
    memset(color,0,sizeof(color));
    dfs(1);
    cout<<num<<endl;
    return 0;
}