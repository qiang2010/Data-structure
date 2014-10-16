#include <iostream>
#include <memory.h>
#define MAX 10000
using namespace std;
template<class T> int mergeSort(T target[],int b,int e);
template<class T> int merge_bin(T target[],int p,int q);
template<class T> void print_list(T a,size_t s);

int link[MAX];
int  main(){
 int a []={1,3,5,2,0,4,11,2334,21,122,-223};
 int s = 11;
 // 使用之前先清空link数组
 memset(link,0,sizeof(link));
 int root = mergeSort(a,0,s-1);
 while(root != 0){
   cout<< a[root]<<" ";
   root = link[root];
 }
}
template<class T> int mergeSort(T target[],int b,int e){
  if ( b >= e ) return e;
  int mid = (b+e)/2;

  int q = mergeSort(target,b,mid);
  int p = mergeSort(target,mid+1,e);
  return  merge_bin(target,q,p);
}
// 输入 p和q是link中的两个位置，分别是两个数组的root
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
