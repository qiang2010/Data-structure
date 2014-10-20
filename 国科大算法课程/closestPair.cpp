/*
 * ����������
 * ����ƽ���ϵ�N��������꣬�ҵ�һ����ԣ�ʹ������֮��ľ��������е������С��
 * �������ַ�����
 * 1. ������ʱ�临�Ӷ��� O(N^2)�ı�������㷨����Ϊ�𰸵ĶԱ�
 * 2. ʹ�÷��η���⣬ʹ����O(NlogN)��ʱ�����
 **   ���η�����Ҫ˼�룺��N���㰴��X����ֳ��������֣��軮��ΪX0���ֱ�������������ֵ���̾��룬��Ϊd1��d2
 *    ��ô�������ϵ���̾����ȻС��d =  min(d1,d2),Ȼ��ϲ���
 *   �ϲ���ȡ���ǣ����ٺϲ�ʱ��Ƚϵĵ�ԣ�x0
*/

#include <iostream>
#include <stdio.h>
#include <cmath>
#include <stdlib.h>
#define MAX 100010

#define MAX_DIS 100000
// ��������������󲻳��� MAX_DIS
using namespace std;
struct point{
  double x ;
  double y ;
  point(){
   x = y = 0;
  }
};
point points[MAX];
//point points2[MAX];
inline double distance_points(point a,point b){
  return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
 int comX(const void *a,const void * b){
  return (*((point*)a)).x < (*((point*)b)).x;
}
double closestPair(point inputs[],int b,int e);  // �������
double closestPair_main(point inputs[],int b,int e);
double closestPair_Divide (point inputs[],int b,int e); // ���η����
double closestPair_Conquer(point inputs[],int b1,int e1,int b2,int e2,double min_current); // ���η����


int main(){

  int n;
  while(true){
    scanf("%d",&n);
    if(n == 0) return 0;
    size_t i = 0;
    for( i = 0; i<n;i++){
      scanf("%lf%lf",&(points[i].x),&(points[i].y));
      //cout<<points[i].x<<"jjjj"<<endl;
      //cin>>points[i].x;
      //cin>>points[i].y;
      //cin>>;
      //points2[i].x = points[i].x;
      //points2[i].y = points[i].y;
   }
   printf("%.2f\n",closestPair_main(points,0,n-1)/2);
  //cout<<"divide and conquer:"<<closestPair_main(points,0,n-1)<<endl;
 // cout<<" contrast"<<closestPair(points,0,n-1) <<endl;
  }
}
double closestPair_main(point inputs[],int b,int e){
  // ���� x ����
  qsort(inputs,b,e,comX);
  // ����
  return  closestPair_Divide(inputs,b,e);
}


double closestPair_Divide(point inputs[],int b,int e){
  if( b == e) return MAX_DIS; // ������ֻ��һ�����ʱ��
  if( b+1 == e) return distance_points(inputs[b],inputs[e]); // ������ֻ���������ʱ��
  int mid =(b+e)/2;
  double min1 = closestPair_Divide(inputs,b,mid);
  double min2 = closestPair_Divide(inputs,mid+1,e);
  if(min1 > min2) min1 = min2;
  return closestPair_Conquer(inputs,b,mid,mid+1,e,min1);
}
//  ����Ĺ鲢��ʱ��ʱ�临�ӶȽϸߣ���Ҫ�Ľ�,���ڵĸ��Ӷ�Ϊ O(N^2)
//   ����Ľ�Ϊ�� ����һ�����飬���ڴ�������еĵ㣬Ȼ����Щ�㰴�� y ��������
//               Ȼ����ɨ��һ���ok��ʱ�临�Ӷ�Ϊ O(NlogN), ����ķ���ʱ�临�Ӷ�Ϊ O(N^2)
double closestPair_Conquer(point inputs[],int b1,int mid,int mid1,int e2,double min_current){
  double left = inputs[mid].x-min_current;
  double right = inputs[mid].x+min_current;
  double top   = -1;
  double bottom = -1;
  double tempDis = MAX_DIS;
  size_t i = mid, j = mid1;
  for(i = mid;i >= b1;i--){
    if( inputs[i].x < left) break;     // ���� ��������������ڽ��бȽ���
    top = inputs[i].y + min_current;  //��ǰ��� ���±߽�
    bottom = inputs[i].y - min_current;
    for( j = mid1; j <= e2; j++){
      if(inputs[j].x > right) break;
      if(inputs[j].y > top) continue;
      if(inputs[j].y < bottom) continue;
      // ����������жϣ��ߵ���һ����������ǰ���ں� i ���Եĵ㣬����i�ķ�Χ����ģ������������ 6 ����
      // ������룬���� min_current
      tempDis = distance_points(inputs[i],inputs[j]);
      if(tempDis < min_current ){
        min_current = tempDis;
        left = inputs[mid].x  - min_current;
        right = inputs[mid].x + min_current;
      }
    }
  }
    return min_current;
}

// �������
double closestPair(point inputs[],int b,int e){
  if ( b == e) return 0;
  double min_dis = distance_points(inputs[b],inputs[b+1]);
  double temp = 0;
  size_t i,j;
  //int s = e-b+1;
  for( i =b; i < e ; i++){
    for( j = i+1;j<=e;j++){
      temp = distance_points(inputs[i],inputs[j]);
      if(temp < min_dis) min_dis = temp;
    }
  }
  return min_dis;
}

