// 下列 ifdef 块是创建使从 DLL 导出更简单的
// 宏的标准方法。此 DLL 中的所有文件都是用命令行上定义的 SORT_EXPORTS
// 符号编译的。在使用此 DLL 的
// 任何其他项目上不应定义此符号。这样，源文件中包含此文件的任何其他项目都会将
// SORT_API 函数视为是从 DLL 导入的，而此 DLL 则将用此宏定义的
// 符号视为是被导出的。
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



// 此类是从 Sort.dll 导出的
//class SORT_API CSort {
//public:
//	CSort(void);
//	// TODO:  在此添加您的方法。
//};



SORT_API int ShellSort(int *a, size_t size);
SORT_API int QuickSort(int *a, size_t size);
SORT_API int MergerSort(int *a, size_t size);
SORT_API int HeapSort(int *a, size_t size);
