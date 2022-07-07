#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//递归方式构建大堆跟
//参数（数组  开始的父系下标  数组元素个数  bool判断升序降序）
void Hp(vector<int>&arr, int start, int len, bool flag)
{
	int f = start;//父系节点下标
	int l = f * 2 + 1;//左子系节点下标
	int r = f * 2 + 2;//右子系节点下标
	if (flag)//升序
	{
		if (l<len && arr[l]>arr[f])
		{
			f = l;
		}
		if (r<len && arr[r]>arr[f])
		{
			f = r;
		}
		if (f != start)
		{
			//将父系节点的元素和子系节点的元素互换
			swap(arr[f], arr[start]);
			//重新构建互换元素后子系节点和它的子系之间的关系
			Hp(arr, f, len,flag);
		}
	}
	else//降序
	{
		if (l<len && arr[l]<arr[f])
		{
			f = l;
		}
		if (r<len && arr[r]<arr[f])
		{
			f = r;
		}
		if (f != start)
		{
			swap(arr[f], arr[start]);
			Hp(arr, f, len, flag);
		}
	}
	
}
//堆排序
//参数（数组  最小或最大的元素数量  bool判断升序降序）
void Heapsort(vector<int>&arr,int num,bool flag)
{
	//构建大堆跟 （从最后一个父系节点开始逐步向上构建大堆跟）
	for (int i = arr.size() / 2 - 1; i >= 0; i--)
	{
		Hp(arr, i, arr.size(), flag);
	}
	for (int i = arr.size() - 1; i > arr.size() - num - 1; i--)
	{
		//将构建完成的大堆跟堆顶元素和i位置的元素互换
		swap(arr[i], arr[0]);
		//重新构建大堆跟父系节点和子系节点的关系
		Hp(arr, 0, i,flag);
	}
}
int main()
{
	bool greater = true;//升序
	bool less = false;//降序
	vector<int> arr = { 0,5,2,9,8};
	int num = 2;//数组中最小或最大的元素数量（num = arr.size()时，对整个数组升序或者降序操作）
	Heapsort(arr, num,less);
	for (int i = arr.size() - num; i < arr.size(); i++)//遍历数组打印num个元素的升序或者降序的数组
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}
