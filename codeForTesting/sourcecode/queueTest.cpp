#include <iostream>
#include <queue>
using namespace std;

int main(){
  queue<int> q;
  q.push(3);
  cout<<q.size();   // ++ size ���ض��еĴ�С
  cout<<q.front();  // ++ front �鿴��һ��Ԫ��
  q.pop();      // ++pop ������һ��Ԫ�أ�û�з���ֵ
  cout<<q.size();


  return 0;
}
