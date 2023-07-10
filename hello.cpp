#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> flowerbed = {0,0,0,0,1,0,1};
    int n = 3;

    int k = 0;
    for (int i = 0; i < flowerbed.size(); i++){
        if (flowerbed[i] == 0){
            bool isLeftPlotEmpty = (i == 0) || (flowerbed[i-1] == 0);
            bool isRightPlotEmpty = (i == flowerbed.size()-1) || (flowerbed[i+1] == 0);

            if (isLeftPlotEmpty && isRightPlotEmpty){
                k++;
                i++;
            }
        }
    
    }

    if (n <= k){
        cout << "true" << endl;
    }
    else cout << "false" << endl;
    
    return 0;
}
