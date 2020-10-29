#include <iostream>
#include <vector>
using namespace std;

float get_val(int x1, float ro1, int ac1, int x2, float ro2, int ac2){
    int h = x2 - x1;
    float fx1 = ro1 * ac1;
    float fx2 = ro2 * ac2;

    float final_return = h * (fx1 + fx2) / 2;

    return final_return;
}

int main(){
    vector<int> x{0,2,3,4};
    vector<float> ro1{4.00, 3.95, 3.89, 3.80};
    vector<int> ac1{100, 103, 106, 110};

    int i = 0;
    int kaha_tk = 3;
    float sum = 0;

    for(i = 0;i<kaha_tk;i++){
        cout << "For xi : " << x[i] << " and " << x[i+1];
        float Ii = get_val(x[i], ro1[i], ac1[i], x[i+1], ro1[i+1], ac1[i+1]);
        cout << ", I = " << Ii << "\n";
        sum += Ii;
    }
    cout << "The answer is : " << sum << "\n";
}