/********************************************************************************************************************
作者：琴卓
日期：2016-12-14-17:10
文件：test.cpp
功能：动态规划算法的设计与实现
内容：
1、采用动态规划策略设计并实现算法，求解最大子段和及最大子段和的起始下标和终止下标，要求算法的时间复杂性不超过O(n)。
最大子段和问题：给定由n个整数（可能为负整数）组成的序列a1, a2,…, an, 求该序列形如的子段和的最大值。当所有整数均为负整数时定义其最大子段和为0。依次定义，所求的最优值为：
例如, 当（a1，a2， a3， a4，a5，a6）= （-2，11，-4，13，-5，-2）时，最大子段和为= 20，起始下标为2，终止下标为4。
要求：掌握用动态规划法设计算法的方法，并能选择适合的数据结构，在其上实现所设计的动态规划算法，使算法复杂性尽可能低。
*********************************************************************************************************************/

#include<iostream>
using namespace std;
int MaxSum(int size, int *num, int &left, int &right) {						//求最大字段和函数 同时更改left指针和right指针的值
	int maxSum = 0;															//最大和
	int tempSum = 0;														//计算和中间值
	int l = 0, r = 0;
	for (int i = 0; i < size; i++)											//对数组进行扫描求和
	{
		if (tempSum > 0) {													//如果当前和为正数则子段加入下一个元素
			tempSum += num[i]; r++;
		}
		else
		{
			tempSum = num[i];												//如果为负数
			l = i;
			r = l;
		}
		if (tempSum > maxSum) {
			maxSum = tempSum;												//如果当前最大值大于字段和 则更改指针
			left = l;
			right = r;
		}
		
	}
	return maxSum;
}
int main() {
	int a[10];
	cout << "请输入10个正负不同数值：" << endl;
	for (int i = 0; i < 10; i++)
	{
		cin >> a[i];
	}
	int left = -1, right = -1;
	int max = MaxSum(10, a, left, right);									//调用最大子段和并输出
	cout << "最大子段和为：" << MaxSum << " 起点为：" << left << " 终点为：" << right<<endl;
	return 0;
}
















