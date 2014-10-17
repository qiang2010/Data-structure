/*
 *�����㷨
 * �㷨��ѡ��ֻ�Ԫ�ص�ʱ��ʹ�õ��������һ��Ԫ��
 *  QuickSortDividByMode.cpp ʹ����λ����Ϊ�ֻ�Ԫ��
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
       input[i] = (rand()%(EN - BE+1))+BE;  // ���� 1 �� 10000 ֮��������
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

     delete []input; //�ͷſռ�
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
  T base = target[b]; // ��׼Ԫ��
  int i = b+1;   // ����i ��j ʹ�� size_t ���� Ҫע���޷������ͣ���i-=0����-1��ͱ�ɺܴ������
  int j = e;
  T temp;
  while(i <= j  ){
    while( i<=e &&  i >= b && target[i] <= base)  i++;   // ���ϴ�����bug
    while( j>=b &&  j <= e && target[j] >= base)  j--;   // �˴����������������ֹ i��j Խ��
    if(i<j){
      swap_(target[i],target[j]);
    }
  }
  //cout<< i <<" i and j "<< j <<endl;
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
