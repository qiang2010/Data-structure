/*
 * ����������   ���η�
 *  A[0..n-1],�� n/2���֣�����֮��������������ټ��Ϻϲ�ʱ���������
 * �ؼ��� �ϲ���ʱ����δ��������ķ����ǣ� �ȸ�����������Ȼ��鲢������������O(N)�ϲ���
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
// ��������������һ���Ǽ����������кϲ�������������һ�����Ǻϲ�����
template<class T> int mergeInversion(T input[], int b1, int e1,int b2,int e2){

}

