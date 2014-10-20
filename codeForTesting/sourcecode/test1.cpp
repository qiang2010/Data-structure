

#include <iostream>
#include <memory.h>
#include <time.h>
#include <stdlib.h>
#define BE 1
#define EN  100000
#define MAX 100100

using namespace std;

template<class T> int mergeSort(T target[],int b,int e);
template<class T> int merge_bin(T target[],int p,int q);
template<class T> void print_list(T a,size_t s);

template<class T> void QuickSort(T target[],int b,int e);
template<class T> void swap_(T &a, T&b);

// 预先定义一个连接数组，也可以动态分配
int link[MAX];
int  main(){
 //int a []={1,3,5,2,0,4,11,2334,21,122,-223};
 // 使用之前先清空link数组
   int jk = 1;
   int * input1,*input2;
   int s = 0;
   clock_t beginTime,endTime;
   for(jk = 1;jk <11;jk++){
     memset(link,0,sizeof(link));
     s = jk * 1000;
     input1 = new int[s];
     input2 = new int[s];

     for(size_t i = 0;i< s;i++){
       input1[i]= input2[i] = (rand()%(EN - BE+1))+BE;  // 产生 1 到 10000 之间的随机数
     }
     beginTime = clock();
     mergeSort(input1,0,s-1);
     endTime  = clock();
     cout<<"MergeTime and qucik: "<<s<<": "<<(endTime-beginTime)*1000.0<<"    \t";
     beginTime = clock();
     QuickSort(input2,0,s-1);
     endTime  = clock();
     cout<<(endTime-beginTime)*1000.0<<endl;
     delete []input1; //释放空间
     delete []input2; //释放空间
  }
}
template<class T> int mergeSort(T target[],int b,int e){
  if ( b >= e ) return e;
  int mid = (b+e)/2;

  int q = mergeSort(target,b,mid);
  int p = mergeSort(target,mid+1,e);
  return  merge_bin(target,q,p);
}
// 输入 p和q是原来的数组中的两个位置，link[p]和link[q] 分别才开始在link中存放原来数组的下标
// 分别是两个数组的root
// 输出是 p和q合并以后的结果
template<class T> int merge_bin(T target[],int p,int q){
  size_t be = p;
  size_t i =0;
  int k = 0; // 合并的新表初始化为在 0 处

  while( p != 0 && q !=0 ){
    if(target[p]<=target[q]){
      link[k] = p;
      k = p;
      p = link[p];
    }else{
      link[k] = q;
      k = q;
      q = link[q];
    }
  }
  while(q != 0){ link[k] = q; k =q;q=link[q];}
  while(p != 0){ link[k] = p; k =p;p=link[p];}
  return link[0];
}
template<class T> void print_list(T a,size_t s){
  size_t i =0;
  for( i = 0; i<s ;i++)
    cout<<a[i]<<" ";
  cout<<endl;
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

