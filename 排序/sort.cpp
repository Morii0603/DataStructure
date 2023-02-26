#include<iostream>
using namespace std;
//2021412011韩磊 作业
//主要使用C语言，使用了部分C++特性
void print_arr(int arr[],int len);
void bubble_sort(int arr[], int len)//冒泡排序
{
    int i, j;
    for (i = 0; i < len - 1; i++) {
        for (j = 0; j < len - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
void insert_sort(int arr[], int len) //插入排序，不带哨兵
{
    int i, j,temp=0;
    for (i = 1; i < len; i++) {
        if (arr[i] < arr[i - 1]) {
            temp = arr[i];
            for (j = i - 1; j >= 0; j--) {
                if (temp < arr[j]) {
                    arr[j + 1] = arr[j];
                }
                else break;
            }
            arr[j + 1] = temp;
        }
    }
}
void shell_sort(int arr[], int len)//希尔排序
{
    int temp,d,i,j; //d是增量,temp为暂存变量
    for(d=len/2;d>=1;d=d/2){
        for(i=d;i<len;i++){
            if(arr[i]<arr[i-d]){
                temp = arr[i];
                for(j=i-d;j>=0;j=j-d){
                    if(temp<arr[j]) arr[j+d] = arr[j]; 
                    else break;
                }
                arr[j+d] = temp;
                // print_arr(arr,len);//供调试
            }
        }
    }
}
int partition(int arr[],int low,int high)//快速排序-划分
{
    int pivot = arr[low]; //用第一个元素作为枢轴
    while(low < high){
        while(low < high && arr[high] >= pivot) high--;
        arr[low] = arr[high];
        while(low < high && arr[low] <= pivot) low++;
        arr[high] = arr[low];
    }
    arr[low] = pivot;
    return low;
}
void quick_sort(int arr[],int low,int high)//快速排序
{
    
    if(low < high){
        int pivotpos = partition(arr,low,high);
        quick_sort(arr,low,pivotpos-1);
        quick_sort(arr,pivotpos+1,high);

    }
}
void merge_sort(int arr[],int len)//归并排序
{
    
}
void print_arr(int arr[],int len)
{
    for(int i=0;i<len;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    int arr[] = { 2,32,10,8,26,13 };
    int len = sizeof(arr) / sizeof(arr[0]);
    return 0;
}
