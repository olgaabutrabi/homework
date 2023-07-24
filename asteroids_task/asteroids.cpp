#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

 void printVec(vector<int> vec){
  for(int i = 0; i < vec.size(); i++){
    cout << vec[i] << " ";
  }
}


int main() {
  vector<int> asteroids = {-1,3,2,-3};
  stack<int> aster; // работаем со стеком, чтобы при поступлении новых элементов сравнивать их с концом и при необходимости не добавлять элементы или ужалять конец стека 
  int top; // для фиксации последнего элемента 
  
  for(int i = 0; i < asteroids.size(); i++ ){
    if (aster.empty() || asteroids[i] > 0){
      aster.push(asteroids[i]);
    }
    else {
      while(true){ // условие while(true) тк, например в случае [2, 3, 4] -5 <- последний астероид будет уничтожать конец стека до конца!
        top = aster.top();
        if(top<0){
          aster.push(asteroids[i]);
          break;
        }
        else if(top == - asteroids[i]){ //если в конце стека существует астероид противоположный по знаку поступающего астероида, то последний астероид в стеке просто убираем, а новый не добавляем 
          aster.pop();
          break;
        }
        else if (top > (- asteroids[i])){ // если постпуающий астероид меньше 
          break;
        }
        else {
          aster.pop(); 
          if (aster.empty()){ // при удаление последнего элемента из стека, мы должны проверить, не пустой ли он 
            aster.push(asteroids[i]);
            break;
          }
        }
      }
      vector<int> output;
      for (int i = aster.size()-1; i>= 0; i++){
        output[i] = aster.top();
        aster.pop();
      }
      printVec(output);
    }
  }
  
  
  return 0;
  
}