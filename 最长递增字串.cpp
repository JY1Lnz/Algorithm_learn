#include<bits/stdc++.h>
using namespace std;

int a[100],dp[100],m,Max;
int n;
void LICS()
{
    //����
/*
��̬�滮
������ִ�
Ƕ��ѭ��
������dp�����Ӧÿ��λ��֮ǰ����ִ�
��ѭ�� ��������ͷ����������β
λ��i��ʾ
��ѭ����������ͷ������λ��i
λ��j��ʾ
ÿ��λ��iֵ����λ��j��ֵʱ
�������dpλ��i��ֵС��j��ֵ+1
��dp[i]���в��� dp[i] = dp[j]+1
����λ��i�����ӵ�֮ǰ����ִ���
������
�õ�����dpΪ��λ�õ�������ִ�
*/
    for (int i = 0;i<n;i++)
    {
        dp[i] = 1;//��С�����ִ�����Ϊ1
        for (int j = 0;j<i;j++)//�ж�ÿһ��λ��֮ǰ����ִ�
        {
            if (a[i]>a[j] && dp[i]<1+dp[j])//��ǰiλ�õ���С��j��ͬʱiλ�õ���ִ�С��j������ִ�
                dp[i] = 1+dp[j];//��iλ�ü���jλ����ִ���ֵ+1
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
