
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

// 预先定义一个连接数组，也可以动态分配
int link[MAX];
int  main(){
 //int a []={1,3,5,2,0,4,11,2334,21,122,-223};
 // 使用之前先清空link数组
   memset(link,0,sizeof(link));
    int jk = 1;
   int * input;
   int s = 0;
   clock_t beginTime,endTime;
   for(jk = 1;jk <11;jk++){
        memset(link,0,sizeof(link));
     s = jk * 1000;
     input = new int[s];
     for(size_t i = 0;i< s;i++){
       input[i] = (rand()%(EN - BE+1))+BE;  // 产生 1 到 10000 之间的随机数
     }
     beginTime = clock();
    int root= mergeSort(input,0,s-1);
      endTime  = clock();
     cout<<s<<": "<<(endTime-beginTime)*1000.0<<endl;

// while(root != 0){
 //  cout<< input[root]<<" ";
  // root = link[root];
 //}
 delete []input; //释放空间
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
