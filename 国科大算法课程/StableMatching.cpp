/*
 * 配对, * 采用增量法来结解决问题
 * 输入是 N
 * 然后是 Ｎ个男士对女生的排序
 *         N个女生对男生的排序
 *  输出是 稳定的对
*/
#include <iostream>
#include <queue>
#include <memory.h>

#define MAX 1000
using namespace std;

int men[MAX],women[MAX];

queue<int> unMatchMan;
int firstUnmatchWoman(int man,int n);
int getManPos(int woman,int man,int n);
int menW[4][4]={{2,1,3,0},{1,3,2,0}  ,{ 2,3,1,0}, {3,2,1,0}};
int womenW[4][4]={{3,0,2,1}  , {0,2,1,3},  {1,2,0,3},  {1,2,0,3}};
int n;
int main(){

   //cout<<"please input n:"<<endl;
   //cin>>n;
   // 初始数据
   n = 4; //
   memset(men,-1,sizeof(men));
   memset(women,-1,sizeof(women));

   while(!unMatchMan.empty()) unMatchMan.pop();
   // 初始所有男士都没有配对
   for(int i = 0;i<n;i++) unMatchMan.push(i);
   int tempMan,tempW;
   while( !unMatchMan.empty()){
     tempMan = unMatchMan.front();
     unMatchMan.pop();
     tempW = firstUnmatchWoman(tempMan,n);
     //cout<<tempMan<<"  wo man  "<<tempW<<endl;
     if( women[tempW] == -1){
        men[tempMan] = tempW;
        women[tempW] = tempMan;
     cout<<tempMan<<"  wo man  "<<tempW<<endl;
     }else{
        if(getManPos(tempW,tempMan,n) < getManPos(tempW,women[tempW],n)){
           // 新的 男生 比原来的男生好，更新信息
          //menW[tempMan][tempW] = -1;
          men[women[tempW]] = -1;
          unMatchMan.push(women[tempW]); // 相应的男生变成为配对的
          men[tempMan] = tempW;
          women[tempW] = tempMan;
        }else{
           unMatchMan.push(tempMan); // 比不过人家之前的对象，就只能接着单身了
        }

     }
   }
   cout<<"result:"<<endl;
   for(size_t i = 0;i< n ;i++){
     cout<<"Man:"<< i<<" Woman:"<<men[i]<<endl;
   }
}
// 输入一个男士，返回其列表中，第一个还没有被其求过婚的女生
int firstUnmatchWoman(int man,int n){
  int j =0;
  int p = menW[man][j];
  while( p == -1){
    j++;
    p = menW[man][j];
  }
  menW[man][j] = -1;  // 被求过婚的女生的地方置为 -1
  return p;
}
// 输入一个女生 和男生，返回该男生在女生心中的地位pos
int getManPos(int woman,int man,int n){
   for(int j =0; j<n;j++){
     if(womenW[woman][j] == man) return j;
   }
}

