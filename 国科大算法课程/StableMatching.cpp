/*
 * ���, * ��������������������
 * ������ N
 * Ȼ���� �θ���ʿ��Ů��������
 *         N��Ů��������������
 *  ����� �ȶ��Ķ�
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
   // ��ʼ����
   n = 4; //
   memset(men,-1,sizeof(men));
   memset(women,-1,sizeof(women));

   while(!unMatchMan.empty()) unMatchMan.pop();
   // ��ʼ������ʿ��û�����
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
           // �µ� ���� ��ԭ���������ã�������Ϣ
          //menW[tempMan][tempW] = -1;
          men[women[tempW]] = -1;
          unMatchMan.push(women[tempW]); // ��Ӧ���������Ϊ��Ե�
          men[tempMan] = tempW;
          women[tempW] = tempMan;
        }else{
           unMatchMan.push(tempMan); // �Ȳ����˼�֮ǰ�Ķ��󣬾�ֻ�ܽ��ŵ�����
        }

     }
   }
   cout<<"result:"<<endl;
   for(size_t i = 0;i< n ;i++){
     cout<<"Man:"<< i<<" Woman:"<<men[i]<<endl;
   }
}
// ����һ����ʿ���������б��У���һ����û�б���������Ů��
int firstUnmatchWoman(int man,int n){
  int j =0;
  int p = menW[man][j];
  while( p == -1){
    j++;
    p = menW[man][j];
  }
  menW[man][j] = -1;  // ��������Ů���ĵط���Ϊ -1
  return p;
}
// ����һ��Ů�� �����������ظ�������Ů�����еĵ�λpos
int getManPos(int woman,int man,int n){
   for(int j =0; j<n;j++){
     if(womenW[woman][j] == man) return j;
   }
}

