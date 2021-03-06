// PermutationCombine.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

//打印
template<typename T>
void print(const T& t) {
	for_each(t.begin(), t.end(), [](const int& v) {cout << v << "    "; });
	cout << endl;
}

//排列
void permutation() {

	vector<int> A{ 3,1,2 };

	//在进行排列组合之前  一定要对数组排序
	//注：求全排列时，会对待排列的数组进行修改

	//1  从小到大排序
	//使用next_permulation  遍历每一个 
	cout << "next_permulation" << endl;
	sort(A.begin(), A.end(), less<int>());
	print(A);
	while (next_permutation(A.begin(),A.end())) {
		print(A);
	}
	
	//2 从大到小排序的时，
	//需要使用prev_permutation 遍历每一个
	cout << "prev_permulation" << endl;
	sort(A.begin(), A.end(), greater<int>());
	print(A);
	while (prev_permutation(A.begin(), A.end())) {
		print(A);
	}

}



//组合的递归实现
template <typename T>
void combine_inner(T &data, int start, int n, int m, int depth, T temp, vector<T> &result)
{
	if (depth == m - 1)
	{
		//最内层循环 将temp加入result
		for (int i = start; i < n - (m - depth - 1); ++i)
		{
			temp[depth] = data[i];
			result.push_back(temp);
		}
	}
	else
		for (int i = start; i < n - (m - depth - 1); ++i)
		{
			temp[depth] = data[i];//每层输出一个元素
			combine_inner(data, i + 1, n, m, depth + 1, temp, result);
		}
}

//T可以调入vector<int>, string等，需要支持下标[]操作及size()函数
template <typename T>
vector<T> combine(T &data, int m)
{
	if (m <= 0)
		return{};
	int depth = 0;
	vector<T> result;
	T temp(m, 0);
	combine_inner(data, 0, data.size(), m, depth, temp, result);
	return result;
}







int main()
{
	permutation();

	string s{ "ABC" };

	cout << "组合" << endl;
	auto ret=combine(s,2);
	for (auto v : ret) {
		for_each(v.begin(), v.end(), [](const char& c) {cout << c; });
		cout << endl;
	}



	system("pause");
    return 0;
}

