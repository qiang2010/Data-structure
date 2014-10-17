/*
 * 计算逆序数   分治法
 *  A[0..n-1],用 n/2划分，两个之问题的逆序数，再加上合并时候的逆序数
 * 关键是 合并的时候如何处理，给出的方法是： 先给子序列排序，然后归并，这样就能在O(N)合并完
*/
#include <iostream>

using namespace std;
template<class T> int countingInversion(T input[], int b, int e);
template<class T> int mergeInversion(T input[], int b1, int e1,int b2,int e2);

int main(){


}
template<class T> int countingInversion(T input[], int b, int e){
  if(b >= e ) return 0;
  if(b == e+1){
    if(input[b] > input[e]){
      T t = input[b];
      input[b] = input[e];
      input[e] = t;
      return 1;
    }
    return 0;
  }
  int mid = (b+e)/2;
  int left = countingInversion(input,b,mid);
  int right = countingInversion(input,mid+1,e);
  int m = mergeInversion(input,b.mid,mid+1,e);
  return left+right+m;
}
// 这里有两个任务，一个是计算两个子列合并的逆序数，另一个就是合并排序
template<class T> int mergeInversion(T input[], int b1, int e1,int b2,int e2){

}

