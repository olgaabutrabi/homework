#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> flowerbed = {0,0,1,0,0,0,1,0,0,0};
    int n = 4;

    int emptyCounter = 1;
    int placedCounter = 0;
    for (int i = 0; i < flowerbed.size(); i++){
        if (flowerbed[i] == 0){
            emptyCounter++;
        }
        else {
            placedCounter += (emptyCounter-1)/2;
            emptyCounter = 0;
        }
    
    }
    placedCounter += emptyCounter/2;

    if (placedCounter >= n){
        cout << "True" <<endl;
    }
    else cout << "False" << endl;
  
    
    return 0;
}
    