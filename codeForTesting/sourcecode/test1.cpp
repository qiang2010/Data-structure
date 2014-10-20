

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

// Ԥ�ȶ���һ���������飬Ҳ���Զ�̬����
int link[MAX];
int  main(){
 //int a []={1,3,5,2,0,4,11,2334,21,122,-223};
 // ʹ��֮ǰ�����link����
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
       input1[i]= input2[i] = (rand()%(EN - BE+1))+BE;  // ���� 1 �� 10000 ֮��������
     }
     beginTime = clock();
     mergeSort(input1,0,s-1);
     endTime  = clock();
     cout<<"MergeTime and qucik: "<<s<<": "<<(endTime-beginTime)*1000.0<<"    \t";
     beginTime = clock();
     QuickSort(input2,0,s-1);
     endTime  = clock();
     cout<<(endTime-beginTime)*1000.0<<endl;
     delete []input1; //�ͷſռ�
     delete []input2; //�ͷſռ�
  }
}
template<class T> int mergeSort(T target[],int b,int e){
  if ( b >= e ) return e;
  int mid = (b+e)/2;

  int q = mergeSort(target,b,mid);
  int p = mergeSort(target,mid+1,e);
  return  merge_bin(target,q,p);
}
// ���� p��q��ԭ���������е�����λ�ã�link[p]��link[q] �ֱ�ſ�ʼ��link�д��ԭ��������±�
// �ֱ������������root
// ����� p��q�ϲ��Ժ�Ľ��
template<class T> int merge_bin(T target[],int p,int q){
  size_t be = p;
  size_t i =0;
  int k = 0; // �ϲ����±��ʼ��Ϊ�� 0 ��

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

