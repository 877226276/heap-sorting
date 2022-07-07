#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//�ݹ鷽ʽ������Ѹ�
//����������  ��ʼ�ĸ�ϵ�±�  ����Ԫ�ظ���  bool�ж�������
void Hp(vector<int>&arr, int start, int len, bool flag)
{
	int f = start;//��ϵ�ڵ��±�
	int l = f * 2 + 1;//����ϵ�ڵ��±�
	int r = f * 2 + 2;//����ϵ�ڵ��±�
	if (flag)//����
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
			//����ϵ�ڵ��Ԫ�غ���ϵ�ڵ��Ԫ�ػ���
			swap(arr[f], arr[start]);
			//���¹�������Ԫ�غ���ϵ�ڵ��������ϵ֮��Ĺ�ϵ
			Hp(arr, f, len,flag);
		}
	}
	else//����
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
//������
//����������  ��С������Ԫ������  bool�ж�������
void Heapsort(vector<int>&arr,int num,bool flag)
{
	//������Ѹ� �������һ����ϵ�ڵ㿪ʼ�����Ϲ�����Ѹ���
	for (int i = arr.size() / 2 - 1; i >= 0; i--)
	{
		Hp(arr, i, arr.size(), flag);
	}
	for (int i = arr.size() - 1; i > arr.size() - num - 1; i--)
	{
		//��������ɵĴ�Ѹ��Ѷ�Ԫ�غ�iλ�õ�Ԫ�ػ���
		swap(arr[i], arr[0]);
		//���¹�����Ѹ���ϵ�ڵ����ϵ�ڵ�Ĺ�ϵ
		Hp(arr, 0, i,flag);
	}
}
int main()
{
	bool greater = true;//����
	bool less = false;//����
	vector<int> arr = { 0,5,2,9,8};
	int num = 2;//��������С������Ԫ��������num = arr.size()ʱ������������������߽��������
	Heapsort(arr, num,less);
	for (int i = arr.size() - num; i < arr.size(); i++)//���������ӡnum��Ԫ�ص�������߽��������
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}
