#include <fstream>
#define MAXPRICE 1001
using namespace std;

int main() {
    ifstream fin ("milk.in");
    ofstream fout ("milk.out");
    unsigned int i, needed, price, paid, farmers, amount, milk[MAXPRICE][1];
    paid = 0;
    fin>>needed>>farmers;
    for(i = 0;i<farmers;i++){
        fin>>price>>amount;
        milk[price][0] += amount;
    }
    for(i = 0; i<MAXPRICE && needed;i++){
        if(needed >= milk[i][0]) {
            needed -= milk[i][0];
            paid += milk[i][0] * i;
        } else if(milk[i][0] > 0) {
            paid += i*needed;
            needed = 0;
        }
    }
    fout << paid << endl;
    return 0;
}
