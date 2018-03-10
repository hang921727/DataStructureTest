/********************************************************************************************************************
作者：琴卓
日期：2016-12-10-17:10
文件：test.cpp
功能：贪心算法的设计与实现
内容：
1、给定n种物品和一个背包，物品i的重量是w[i], 其价值是p[i], 背包的容量为C。设物品已按单位重量价值递减的次序排序。每种物品不可以装入背包多次，但可以装入部分的物品i。背包问题是选择装入背包中的物品，在不超过背包容量的前提下使背包的得总价值最大。用贪心法设计与实现一个算法，求解背包问题。
要求：掌握用贪心法设计算法的方法，并能选择适合的数据结构，在其上实现所设计的贪心算法，使算法复杂性尽可能低。
*********************************************************************************************************************/


#include<iostream>
using namespace std;
void Greed(int size, float C, float p[], float w[], float x[]) {			//贪心算法求背包问题
	int i;
	for ( i = 1; i < size; i++)												//将x[]归零
	{
		x[i] = 0;
	}
	float c = C;
	for ( i = 1; i < size; i++)												//对物体数组进行扫描
	{
		if (w[i] > c) {														//如果背包容量剩余
			break;
		}
		x[i] = 1;
		c -= w[i];															//则放入当前物体 否则放入当前部分物体
	}
	if (i < size) {
		x[i] = c / w[i];
	}
}


int main() {
	float C = 50;					//背包容量
	float w[] = { 0,10,20,30 };		//下标从1开始  物体重量
	float p[] = { 0,60,100,120 };	//物体价值
	float x[4] = {0};				//各个物体最终选择的百分比
	cout << "背包容量为：" << C << endl;
	cout << "待装物品的重量和价值分别为：" << endl;
	for (int i = 1; i < 4; i++)
	{
		cout << "[" << i << "]:(" << w[i] << "," << p[i] << ")" << endl;
	}
	Greed(4, C, p, w, x);													//调用贪心算法求背包问题
	cout << "选择装的物品重量与物体总重量比如下：" << endl;
	for (int i = 1; i < 4; i++)
	{
		cout << "[" << i << "]" << x[i] << endl;
	}
	return 0;
}