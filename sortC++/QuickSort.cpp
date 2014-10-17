/*
 *快排算法
 * 算法在选择分化元素的时候使用的是数组第一个元素
 *  QuickSortDividByMode.cpp 使用中位数作为分化元素
*/
#include <iostream>
#include <time.h>
#include <stdlib.h>
#define BE 1
#define EN  10000

using namespace std;

template<class T> void QuickSort(T target[],int b,int e);
template<class T> void swap_(T &a, T&b);

int main(){
   int jk = 1;
   int * input;
   int s = 0;
   clock_t beginTime,endTime;
   for(jk = 1;jk <11;jk++){
     s = jk * 100;
     input = new int[s];
     for(size_t i = 0;i< s;i++){
       input[i] = (rand()%(EN - BE+1))+BE;  // 产生 1 到 10000 之间的随机数
     }
     beginTime = clock();
     QuickSort(input,0,s-1);

    //continue;
     //cout<<"Result:"<<endl;
     //for(size_t i=0;i<s;i++)
     //  cout<<input[i]<<" ";
     //cout<<endl;
      endTime  = clock();
     cout<<s<<": "<<(endTime-beginTime)*1000.0<<endl;

     delete []input; //释放空间
   }

  // int a[] = {8,4,6,21,56,78,12};
  //  int a[] = {3,9,3,56,7,5,4};
 //  size_t s = 7;
 //  QuickSort(a,0,6);
  // cout<<"Result:"<<endl;
  // for(size_t i=0;i<s;i++)
   // cout<<a[i]<<" ";
}

template<class T> void QuickSort(T target[], int b,int e){
  if(b<0||e<0) return;
  if (b>=e) return ;
  T base = target[b]; // 基准元素
  int i = b+1;   // 这里i 和j 使用 size_t 类型 要注意无符号类型，当i-=0，在-1后就变成很大的数了
  int j = e;
  T temp;
  while(i <= j  ){
    while( i<=e &&  i >= b && target[i] <= base)  i++;   // 书上代码有bug
    while( j>=b &&  j <= e && target[j] >= base)  j--;   // 此处必须添加条件，防止 i、j 越界
    if(i<j){
      swap_(target[i],target[j]);
    }
  }
  //cout<< i <<" i and j "<< j <<endl;
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
