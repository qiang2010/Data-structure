#include <iostream>

using namespace std;
template<class T> void mergeSort(T target[],int b,int e);
template<class T> void merge_bin(T target[],int b1,int e1,int b2,int e2);
template<class T> void print_list(T a,size_t s);

int  main(){
 int a []={1,3,5,2,0,4,21,122,-223};
 int s = 9;
 mergeSort(a,0,s-1);
 print_list(a,s);
}
template<class T> void mergeSort(T target[],int b,int e){
  if ( b >= e ) return;
  // 划分
  int mid = (b+e)/2;
  //cout<<mid<<"  "<<b<<"  "<<e<<endl;
  mergeSort(target,b,mid);
  mergeSort(target,mid+1,e);
  // 合并
  merge_bin(target,b,mid,mid+1,e);
  // cout<<mid<<endl;
}
template<class T> void merge_bin(T target[],int b1,int e1,int b2,int e2){
  int num = e1-b1+2+e2-b2;
  T *temp = new T[num];
  size_t be = b1;
  size_t i =0;

  while( b1<=e1 && b2<= e2){
    if(target[b1]<=target[b2]){
      temp[i] = target[b1];
      b1++;
      i++;
    }else{
      temp[i] = target[b2];
      i++;
      b2++;
    }
  }
  while(b1<=e1){ temp[i++] = target[b1];b1++;}
  while(b2<=e2){ temp[i++] = target[b2];b2++;}
  for( size_t j =0;j<num; j++ ){
    target[be + j] = temp[j];
  }
  //cout<<e2<<"  ji"<<endl;
  delete [] temp;
}
template<class T> void print_list(T a,size_t s){
  size_t i =0;
  for( i = 0; i<s ;i++)
    cout<<a[i]<<" ";
  cout<<endl;
}
