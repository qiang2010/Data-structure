/*
 * �ҵ������е�KС��Ԫ��
 *
 * һ�ַ����ǣ����� ������ʱ�临�Ӷ������������� O(nlogn)
 *  ����һ�ַ������� ���ÿ����еķֻ�˼�룬һ�ηֻ���Ԫ��v�Ϳ��Ե����Լ���λ��j
 *  ���k<j ����ôҪ�ҵ�Ԫ�ؾ��������1��j֮�䣻
 *  ���k>j ����ôҪ�ҵ�Ԫ�ؾ�������� j+1�����֮�䣬������A[j+1,..,n]�ĵ�j-k��Ԫ��
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
    p = part(target,b,e);  // p���������е����꣬�������λ��
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

