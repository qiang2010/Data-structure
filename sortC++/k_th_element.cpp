/*
 * 找到数组中第K小的元素
 *
 * 一种方法是，排序 这样的时间复杂度最坏情况下至少是 O(nlogn)
 *  还有一种方法就是 利用快排中的分划思想，一次分划，元素v就可以到达自己的位置j
 *  如果k<j ，那么要找的元素就在数组的1到j之间；
 *  如果k>j ，那么要找的元素就在数组的 j+1到最后之间，并且是A[j+1,..,n]的第j-k个元素
 *
*/
#include <iostream>

using namespace std;

template<class T> int part(T target[],int b,int e);
template<class T> void swap_(T &a, T&b);
template<class T> int k_th(T target[],int b,int e,int k);
template<class T> void print_list(T a,size_t s);

int main(){
  int a [] = {3,9,7,5,2,33,4,1};
 //int a []= {3,9,4,2,5};
  cout<<k_th(a,0,7,2);

}
template<class T> int k_th(T target[],int b,int e,int k){
  k;
  if(k>e|| k<b) return -1;
  int p ;
  while( b <= e){
    print_list(target,8);
    p = part(target,b,e);  // p是在数组中的坐标，不是相对位置
    int dis = p - b+1;
    print_list(target,8);
    if(k == dis ) return p;
    if(k<dis){
      e = p-1;
    }else{
       b = p+1; k = k-p;
   }
  }
}

template<class T> int part(T target[],int b,int e){
  if(b>e) return -1;
  T base = target[b];
  int i = b+1;
  int j = e;
  while(i<=j){
    while(target[i] <= base && i <= e&& i >= b) i++;
    while(target[j] >= base && j >= b&& j <= e) j--;
    if(i<j){
      swap_(target[i],target[j]);
    }
  }
  swap_(target[i-1],target[b]);
  return i-1;
}
template<class T> void swap_(T &a, T&b){
  T temp =a;
  a = b;
  b = temp;
}
template<class T> void print_list(T a,size_t s){
  size_t i =0;
  for( i = 0; i<s ;i++)
    cout<<a[i]<<" ";
  cout<<endl;
}

