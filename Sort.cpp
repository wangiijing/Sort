// Sort.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include "Sort.h"



// ���ǵ���������һ��ʾ��

// ���ǵ���������һ��ʾ����
//SORT_API int fnSort(void)
//{
//	cout << "hello world!" << endl;
//	return 0;
//}

// �����ѵ�����Ĺ��캯����
// �й��ඨ�����Ϣ������� Sort.h


void InsertSort(int* a, size_t size)//ֱ�Ӳ��뺯��  
{
	assert(a);//������ڼ��  
	//size_t size = right - left;
	int left = 0;
	int right = size - 1;
	for (int j = left; j < right; j++)//ѭ��������֤��ÿ�����������˲���  
	{
		int i = left;
		while (i<j && a[j]>a[i])//ѭ������i<j��֤�˰�a[j]ǰ����������ź���ģ����ҵ���a[j]Ӧ��Ҫ����ĵط���a[i]  
		{
			i++;
		}
		int tmp = a[j];
		for (int index = j; index>i; index--)//��a[i]����Ĵ�i��j��������߶�һλ  
		{
			a[index] = a[index - 1];
		}
		a[i] = tmp;//����a[j]�ŵ���Ӧ�ò����λ��  
	}
}
//********************************************************************ֱ�Ӳ���***********************************************************************
SORT_API int ShellSort(int *a, size_t size)
{
	assert(a);
	clock_t start = clock();
	int spilk = size;//��������  
	while (spilk >1)//����������1ʱ������ѭ����������СΪ1  
	{
		spilk = spilk / 3 + 1;//  
		for (int i = spilk; i < size; i++)//��֤ÿ���������бȽ���  
		{
			for (int j = 0; j + spilk < size; j += spilk)
			{
				if (a[j]>a[j + spilk])
				{
					swap(a[j], a[j + spilk]);
				}
				else
				{
					break;
				}
			}
		}
	}
	clock_t end = clock();
	return (end - start);
}
//********************************************************************ֱ�Ӳ���***********************************************************************


//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$


//********************************************************************����***************************************************************************
int Getkey(int *a, size_t left, size_t right)
{
	assert(a);
	int mid = left + (right - left) / 2;  //ȡͷ��β���м��������бȽϣ�ȡ�м��������  
	if (a[left] < a[mid])
	{
		if (a[mid] < a[right])  // ������a[left] < a[mid] && a[mid] < a[right]  
		{
			return mid;
		}
		else if (a[left] < a[right]) // ������a[left] < a[mid] && a[mid] > a[right] && a[left] < a[right]  
		{
			return right;
		}
		else   // ������a[left] < a[mid] && a[mid] > a[right] && a[left] > a[right]  
			return left;
	}
	else
	{
		if (a[left] < a[right])  //������a[left] > a[mid] && a[left] < a[right]  
		{
			return left;
		}
		else if (a[mid]>a[right])//������a[left] > a[mid] && a[left] > a[right] && a[mid] > a[right]  
		{
			return mid;
		}
		else   //������a[left] > a[mid] && a[left] > a[right] && a[mid] < a[right]  
			return right;
	}
}
void quicksort(int *a, int left, int right)
{
	if (left < right)  //������a��һ���ǲ�����������ݹ�  
	{
		int key = Getkey(a, left, right);//��ȡ�����keyֵ  
		swap(a[key], a[right]);
		int cur = left;
		int index = left;
		while (cur < right) //��cur��left��ʼ������,������key������ʹ�left��ʼ������ν���  
		{
			if (a[cur] < a[right])
			{
				swap(a[index++], a[cur]);
			}
			cur++;
		}
		swap(a[index], a[right]);
		quicksort(a, left, index - 1);//��ߵݹ�  
		quicksort(a, index + 1, right);//�ұߵݹ�  
	}
	else
	{
		return;
	}
}
SORT_API int QuickSort(int *a, size_t size)
{
	clock_t start = clock();
	quicksort(a, 0, size - 1);
	clock_t end = clock();
	return (end - start);
}
//********************************************************************����***********************************************************************


//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$


//********************************************************************�鲢***********************************************************************
void mergersort(int *a, size_t left, size_t right)
{
	size_t mid = left + (right - left) / 2;
	if (right - left>1)
	{
		mergersort(a, left, mid);
		mergersort(a, mid + 1, right);
	}
	if (right - left <= 1)
	{
		if (a[left] > a[right])
		{
			swap(a[left], a[right]);
		}
	}
	else
	{
		size_t cur = left;
		size_t cmp = mid + 1;
		int i = left;
		int *str = new int[right + 1];
		while (cur <= mid &&  cmp <= right)
		{
			if (a[cur] < a[cmp])
			{
				str[i++] = a[cur++];
			}
			else
			{
				str[i++] = a[cmp++];
			}
		}
		if (cur == mid + 1)
		{
			while (cmp <= right)
			{
				str[i++] = a[cmp++];
			}
		}
		else
		{
			while (cur <= mid)
			{
				str[i++] = a[cur++];
			}
		}
		for (size_t i = left; i <= right; i++)
		{
			a[i] = str[i];
		}
		delete[] str;
	}
}
SORT_API int MergerSort(int *a, size_t size)
{
	assert(a);
	clock_t start = clock();
	if (size > 1000000)
	{
		int left = 0;
		int right = size - 1;
		int key = Getkey(a, left, right);//��ȡ�����keyֵ
		swap(a[left], a[key]);
		int temp = a[left];
		int curleft = left;
		int curright = right;
		while (curleft < curright)
		{
			//��ӷ�
			while (curleft < curright && a[curleft] <= a[curright])//�Ӻ�����С��
			{
				curright--;
			}
			if (curleft < curright && a[curleft] > a[curright])
			{
				a[curleft++] = a[curright];
			}
			while (curleft < curright && a[curleft] <= a[curright])//��ǰ���Ҵ��
			{
				curleft++;
			}
			if (curleft < curright && a[curleft] > a[curright])
			{
				a[curright--] = a[curleft];
			}
		}
		a[curleft] = temp;
		mergersort(a, 0, curleft - 1);
		mergersort(a, curleft + 1, right);
	}
	else
	{
		mergersort(a, 0, size - 1);
	}
	
	clock_t end = clock();
	return (end - start);
}
//********************************************************************�鲢***********************************************************************


//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$


//********************************************************************��***********************************************************************
void AdjustDown(int *a, size_t k, int root)//�µ�����С������С������֤���ڵ��ֵΪ���ֵ           
{
	size_t parent = root;
	size_t child = parent * 2 + 1;
	while (child < k)
	{
		if (child + 1 < k && a[child] < a[child + 1])
		{
			child++;
		}
		if (a[child] > a[parent])
		{
			swap(a[child], a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
SORT_API int HeapSort(int *a, size_t size)
{
	assert(a);
	clock_t start = clock();
	for (int i = (size - 2) / 2; i >= 0; i--)
	{
		AdjustDown(a, size, i);//�������  
	}
	for (size_t i = 0; i < size; i++)
	{
		swap(a[0], a[size - 1 - i]);//�������δ������ǰ����  
		AdjustDown(a, size - 1 - i, 0);  //��a[0]�����µ�  
	}
	clock_t end = clock();
	return (end - start);
}
