/*
 * 最近点对问题
 * 给出平面上的N个点的坐标，找到一个点对，使得它们之间的距离是所有点对中最小的
 * 给出两种方法：
 * 1. 首先是时间复杂度是 O(N^2)的暴力求解算法，作为答案的对比
 * 2. 使用分治法求解，使得在O(NlogN)的时间求解
 **   分治法的主要思想：将N个点按照X方向分成两个部分，设划分为X0，分别求解这两个部分的最短距离，记为d1和d2
 *    那么整个集合的最短距离必然小于d =  min(d1,d2),然后合并。
 *   合并采取的是，减少合并时候比较的点对，x0
*/

// 这里为了简化计算，我们统一使用int类型,并限制点的数量不能多于 MAX
#include <iostream>
#include <cmath>
#include <stdlib.h>
#define MAX 1000

#define MAX_DIS 100000
// 假设两点间距离最大不超过 MAX_DIS
using namespace std;
struct point{
  int x ;
  int y ;
  point(){
   x = y = 0;
  }
};
point points[MAX];
point points2[MAX];
inline double distance_points(point a,point b){
  return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
 int comX(const void *a,const void * b){
  return (*((point*)a)).x < (*((point*)b)).x;
}
double closestPair(point inputs[],int b,int e);  // 暴力求解
double closestPair_main(point inputs[],int b,int e);
double closestPair_Divide (point inputs[],int b,int e); // 分治法求解
double closestPair_Conquer(point inputs[],int b1,int e1,int b2,int e2,double min_current); // 分治法求解


int main(){
  int n;
  cin>>n;
  size_t i = 0;
  for( i = 0; i<n;i++){
    cin>>points[i].x;
    cin>>points[i].y;
    points2[i].x = points[i].x;
    points2[i].y = points[i].y;
  }
  cout<<"divide and conquer:"<<closestPair_main(points,0,n-1)<<endl;
  cout<<" contrast"<<closestPair(points,0,n-1)<<endl;

}
double closestPair_main(point inputs[],int b,int e){
  // 按照 x 排序
  qsort(inputs,b,e,comX);
  // 计算
  return  closestPair_Divide(inputs,b,e);
}


double closestPair_Divide(point inputs[],int b,int e){
  if( b == e) return MAX_DIS; // 集合中只有一个点的时候
  if( b+1 == e) return distance_points(inputs[b],inputs[e]); // 集合中只有两个点的时候
  int mid =(b+e)/2;
  double min1 = closestPair_Divide(inputs,b,mid);
  double min2 = closestPair_Divide(inputs,mid+1,e);
  if(min1 > min2) min1 = min2;
  return closestPair_Conquer(inputs,b,mid,mid+1,e,min1);
}
double closestPair_Conquer(point inputs[],int b1,int mid,int mid1,int e2,double min_current){
  double left = inputs[mid].x-min_current;
  double right = inputs[mid].x+min_current;
  double top   = -1;
  double bottom = -1;
  double tempDis = MAX_DIS;
  size_t i = mid, j = mid1;
  for(i = mid;i >= b1;i--){
    if( inputs[i].x < left) break;     // 超出 左侧条带，不需在进行比较啦
    top = inputs[i].y + min_current;  //当前点的 上下边界
    bottom = inputs[i].y - min_current;
    for( j = mid1; j <= e2; j++){
      if(inputs[j].x > right) break;
      if(inputs[j].y > top) continue;
      if(inputs[j].y < bottom) continue;
      // 经过上面的判断，走到这一步，表明当前用于和 i 测试的点，是在i的范围里面的，这里面最多有 6 个点
      // 计算距离，更新 min_current
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

// 暴力求解
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

