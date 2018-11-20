#include<bits/stdc++.h>
using namespace std;

int a[100],dp[100],m,Max;
int n;
void LICS()
{
    //初代
/*
动态规划
最长递增字串
嵌套循环
用数组dp储存对应每个位置之前的最长字串
外循环 ：从数组头遍历到数组尾
位置i表示
内循环：从数组头便利到位置i
位置j表示
每当位置i值大于位置j数值时
如果数组dp位置i的值小于j的值+1
对dp[i]进行操作 dp[i] = dp[j]+1
即将位置i的数加到之前的最长字串中
遍历完
得到数组dp为各位置的最长递增字串
*/
    for (int i = 0;i<n;i++)
    {
        dp[i] = 1;//最小递增字串长度为1
        for (int j = 0;j<i;j++)//判断每一个位置之前的最长字串
        {
            if (a[i]>a[j] && dp[i]<1+dp[j])//当前i位置的数小于j处同时i位置的最长字串小于j处的最长字串
                dp[i] = 1+dp[j];//对i位置加上j位置最长字串的值+1
        }
        Max = 0;
        for (int i = 0;i<n;i++)
            if (Max<dp[i])
                Max = dp[i];
    }
}

int main()
{
    cin>>n;
    for (int i = 0;i<n;i++)
        cin>>a[i];
    LICS();
    cout<<Max<<endl;

    return 0;
}
