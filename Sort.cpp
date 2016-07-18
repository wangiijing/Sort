// Sort.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "Sort.h"



// 这是导出变量的一个示例

// 这是导出函数的一个示例。
//SORT_API int fnSort(void)
//{
//	cout << "hello world!" << endl;
//	return 0;
//}

// 这是已导出类的构造函数。
// 有关类定义的信息，请参阅 Sort.h


void InsertSort(int* a, size_t size)//直接插入函数  
{
	assert(a);//参数入口检测  
	//size_t size = right - left;
	int left = 0;
	int right = size - 1;
	for (int j = left; j < right; j++)//循环条件保证了每个数都进行了插入  
	{
		int i = left;
		while (i<j && a[j]>a[i])//循环条件i<j保证了啊a[j]前面的数都是排好序的，并找到啊a[j]应该要插入的地方即a[i]  
		{
			i++;
		}
		int tmp = a[j];
		for (int index = j; index>i; index--)//将a[i]后面的从i到j整体向后踢动一位  
		{
			a[index] = a[index - 1];
		}
		a[i] = tmp;//将啊a[j]放到它应该插入的位置  
	}
}
//********************************************************************直接插入***********************************************************************
SORT_API int ShellSort(int *a, size_t size)
{
	assert(a);
	clock_t start = clock();
	int spilk = size;//增量定义  
	while (spilk >1)//当增量大于1时，进入循环，增量最小为1  
	{
		spilk = spilk / 3 + 1;//  
		for (int i = spilk; i < size; i++)//保证每个数都进行比较了  
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
//********************************************************************直接插入***********************************************************************


//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$


//********************************************************************快排***************************************************************************
int Getkey(int *a, size_t left, size_t right)
{
	assert(a);
	int mid = left + (right - left) / 2;  //取头，尾，中间三个进行比较，取中间的数返回  
	if (a[left] < a[mid])
	{
		if (a[mid] < a[right])  // 条件：a[left] < a[mid] && a[mid] < a[right]  
		{
			return mid;
		}
		else if (a[left] < a[right]) // 条件：a[left] < a[mid] && a[mid] > a[right] && a[left] < a[right]  
		{
			return right;
		}
		else   // 条件：a[left] < a[mid] && a[mid] > a[right] && a[left] > a[right]  
			return left;
	}
	else
	{
		if (a[left] < a[right])  //条件：a[left] > a[mid] && a[left] < a[right]  
		{
			return left;
		}
		else if (a[mid]>a[right])//条件：a[left] > a[mid] && a[left] > a[right] && a[mid] > a[right]  
		{
			return mid;
		}
		else   //条件：a[left] > a[mid] && a[left] > a[right] && a[mid] < a[right]  
			return right;
	}
}
void quicksort(int *a, int left, int right)
{
	if (left < right)  //当数组a有一个是不进行排序与递归  
	{
		int key = Getkey(a, left, right);//或取合理的key值  
		swap(a[key], a[right]);
		int cur = left;
		int index = left;
		while (cur < right) //让cur从left开始往后走,遇到比key大的数就从left开始向后依次交换  
		{
			if (a[cur] < a[right])
			{
				swap(a[index++], a[cur]);
			}
			cur++;
		}
		swap(a[index], a[right]);
		quicksort(a, left, index - 1);//左边递归  
		quicksort(a, index + 1, right);//右边递归  
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
//********************************************************************快排***********************************************************************


//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$


//********************************************************************归并***********************************************************************
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
		int key = Getkey(a, left, right);//或取合理的key值
		swap(a[left], a[key]);
		int temp = a[left];
		int curleft = left;
		int curright = right;
		while (curleft < curright)
		{
			//填坑法
			while (curleft < curright && a[curleft] <= a[curright])//从后面找小的
			{
				curright--;
			}
			if (curleft < curright && a[curleft] > a[curright])
			{
				a[curleft++] = a[curright];
			}
			while (curleft < curright && a[curleft] <= a[curright])//从前面找大的
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
//********************************************************************归并***********************************************************************


//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
//$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$


//********************************************************************堆***********************************************************************
void AdjustDown(int *a, size_t k, int root)//下调，将小的数往小调，保证根节点的值为最大值           
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
		AdjustDown(a, size, i);//构建大堆  
	}
	for (size_t i = 0; i < size; i++)
	{
		swap(a[0], a[size - 1 - i]);//将根依次从最后往前交换  
		AdjustDown(a, size - 1 - i, 0);  //将a[0]进行下调  
	}
	clock_t end = clock();
	return (end - start);
}
