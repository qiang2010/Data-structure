
/*
 *�����㷨
 * �㷨��ѡ��ֻ�Ԫ�ص�ʱ��ʹ�õ��������һ��Ԫ��
 *  QuickSortDividByMode.cpp ʹ����λ����Ϊ�ֻ�Ԫ��
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
  T base = target[b]; // ��׼Ԫ��
  size_t i = b+1;
  size_t j = e;
  T temp;
  while(i <= j){
    while(target[i] <= base &&  i<=e ) i++;   // ���ϴ�����bug
    while(target[j] >= base &&  j>=b ) j--;   // �˴����������������ֹ i��j Խ��
    if(i<j){
      swap_(target[i],target[j]);
    }
  }
  cout<< i <<" i and j "<< j <<endl;
  // �ҵ���base��λ�ã�Ȼ��ֿ��ݹ�
  swap_(target[i-1],target[b]);
  // �ݹ�
  QuickSort(target,b,i-2);
  QuickSort(target,i,e);
}
template<class T> void swap_(T &a, T&b){
  T temp =a;
  a = b;
  b = temp;
}
