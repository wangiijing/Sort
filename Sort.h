// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� SORT_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// SORT_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef SORT_EXPORTS
#define SORT_API __declspec(dllexport)
#else
#define SORT_API __declspec(dllimport)
#endif
#include<iostream>
#include<assert.h>
#include<time.h>
using namespace std;

#define random(x) (rand()%x)



// �����Ǵ� Sort.dll ������
//class SORT_API CSort {
//public:
//	CSort(void);
//	// TODO:  �ڴ�������ķ�����
//};



SORT_API int ShellSort(int *a, size_t size);
SORT_API int QuickSort(int *a, size_t size);
SORT_API int MergerSort(int *a, size_t size);
SORT_API int HeapSort(int *a, size_t size);
