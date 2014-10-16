
/*
 *快排算法
 * 算法在选择分化元素的时候使用的是数组第一个元素
 *  QuickSortDividByMode.cpp 使用中位数作为分化元素
*/
#include <iostream>

using namespace std;

template<class T> void QuickSort(T target[],int b,int e);
template<class T> void swap_(T &a, T&b);

int main(){
   //int a[] = {8,4,6,21,56,78,12};
   int a [] = {3,9,7,5,4};
   size_t s = 5;
   for( int i =0;i<10;i++)
    cout<<s--<<endl;
}

template<class T> void QuickSort(T target[], size_t b,size_t e){
  if(b<0||e<0) return;
  if (b>=e) return ;
  T base = target[b]; // 基准元素
  size_t i = b+1;
  size_t j = e;
  T temp;
  while(i <= j){
    while(target[i] <= base &&  i<=e ) i++;   // 书上代码有bug
    while(target[j] >= base &&  j>=b ) j--;   // 此处必须添加条件，防止 i、j 越界
    if(i<j){
      swap_(target[i],target[j]);
    }
  }
  cout<< i <<" i and j "<< j <<endl;
  // 找到了base的位置，然后分开递归
  swap_(target[i-1],target[b]);
  // 递归
  QuickSort(target,b,i-2);
  QuickSort(target,i,e);
}
template<class T> void swap_(T &a, T&b){
  T temp =a;
  a = b;
  b = temp;
}
