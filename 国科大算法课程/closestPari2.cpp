/*
 * 最近点对问题
 * 给出平面上的N个点的坐标，找到一个点对，使得它们之间的距离是所有点对中最小的
 *  在 closestPair.cpp 中已经有代码来解决问题，但是在提交到 杭电OJ 1007 题目的时候出现超时错误，
 *   这个是因为在y 坐标的处理上，没有加快操作，我们这里为了进一步减少比较的点
*  首先对 根据y方向排序，
*/

#include <iostream>
#include <stdio.h>
#include <cmath>
#include <stdlib.h>
#define MAX 100010

#define MAX_DIS 100000
// 假设两点间距离最大不超过 MAX_DIS
using namespace std;
struct point{
  double x ;
  double y ;
  int leftright ;
  point(){
   x = y = leftright= 0;
  }
};
point points[MAX];
point tempInBound[MAX];   // 为了加快计算，在合并的时候先将条带中的点全部选择出来，然后按照y 排序 时间复杂度降解到 O(NlogN)
inline double distance_points(point a,point b){
  return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
 int comX(const void *a,const void * b){
  if ((*((point*)a)).x == (*((point*)b)).x)
    return (*((point*)a)).y < (*((point*)b)).y ;
  return (*((point*)a)).x < (*((point*)b)).x;
}
int  comY(const void *a,const void *b){
    if((*((point*)a)).y ==(*((point*)b)).y)
        return (*((point*)a)).x < (*((point*)b)).x;
    return (*((point*)a)).y < (*((point*)b)).y;
}
double closestPair(point inputs[],int b,int e);  // 暴力求解
double closestPair_main(point inputs[],int b,int e);
double closestPair_Divide (point inputs[],int b,int e); // 分治法求解
double closestPair_Conquer(point inputs[],int b1,int e1,int b2,int e2,double min_current); // 分治法求解


int main(){

  int n;
  while(true){
    scanf("%d",&n);
    if(n == 0) return 0;
    size_t i = 0;
    for( i = 0; i<n;i++){
      scanf("%lf%lf",&(points[i].x),&(points[i].y));
   }
   printf("%.2lf\n",closestPair_main(points,0,n-1)/2);
  }
}
double closestPair_main(point inputs[],int b,int e){
  // 按照 x 排序
  qsort(inputs,e-b+1,sizeof(point),comX);
  // 计算
  return  closestPair_Divide(inputs,b,e);
}


double closestPair_Divide(point inputs[],int b,int e){
  if( b == e) return MAX_DIS; // 集合中只有一个点的时候
  if( b+1 == e) return distance_points(inputs[b],inputs[e]); // 集合中只有两个点的时候
  if(b+2 == e) {
    double d1 = distance_points(inputs[b],inputs[b+1]);
    double d2 = distance_points(inputs[b+1],inputs[b+2]);
    double d3 = distance_points(inputs[b],inputs[b+2]);
    double min2 = d1;
    if(d2<min2) min2 = d2;
    if(d3<min2) min2 = d3;
    return min2;

  } // 三个点的时候
  int mid =(b+e)/2;
  double min1 = closestPair_Divide(inputs,b,mid);
  double min2 = closestPair_Divide(inputs,mid+1,e);
  if(min1 > min2) min1 = min2;
  return closestPair_Conquer(inputs,b,mid,mid+1,e,min1);
}

double closestPair_Conquer(point inputs[],int b1,int mid,int mid1,int e2,double min_current){
  double left = inputs[mid].x-min_current;
  double right = inputs[mid].x+min_current;
  double tempDis = MAX_DIS;
  int i = mid, j = mid1;
  int coun = 0;
  for(i = mid;i >= b1;i--){
    if( inputs[i].x >= left) {     // 超出 左侧条带，不需在进行比较啦
      tempInBound[coun].x = inputs[i].x;
      tempInBound[coun].y = inputs[i].y;
      tempInBound[coun].leftright =  -1; // 左侧
      coun++;
    }
  }
  for(i = mid1;i <= e2;i++){
   if( inputs[i].x <= right) {   // 超出 左侧条带，不需在进行比较啦
      tempInBound[coun].x = inputs[i].x;
      tempInBound[coun].y = inputs[i].y;
      tempInBound[coun].leftright =  1; // 右侧
      coun++;
   }
  }
  // 按照 y 排序
  qsort(tempInBound,coun,sizeof(point),comY);
  //for(  i =0;i< coun;i++){
  //  cout<<tempInBound[i].y<<endl;
  //}
  for( i =0;i<coun;i++){
    for(j =1; (j<=7)&&(i+j<coun);j++){
      if(tempInBound[i].leftright != tempInBound[j+i].leftright){
        tempDis = distance_points(tempInBound[i],tempInBound[i+j]);
        if(tempDis < min_current) min_current = tempDis;
      }
    }
  }
    return min_current;
}

