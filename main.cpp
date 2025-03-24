#include <iostream>
using namespace std;
#include <iostream>
#include <ctime>

int main() {

    // Aggiungi un ritardo per simulare il passare del tempo
    clock_t before = clock();
    int k = 0;
    for(int i = 0; i < 100000; i++) {
        k += i;
    }
    clock_t duration = clock() - before;
    cout << "Duration: " << (float)duration / CLOCKS_PER_SEC << " seconds";
    cout << endl;
    cout << before << endl;


    while((float)duration/CLOCKS_PER_SEC <=40.0){    // >>
        duration = clock() - before;
        //cout << ".";
    }
    cout << endl;
    //(int)((float)(timer)/CLOCKS_PERSEC*100)
    cout << (float)duration/CLOCKS_PER_SEC << endl;
    /*        --> per stampare nella classifica quando è stato fatto il record
    time_t x;
    time(&x);
    cout << endl;
    cout << ctime(&x) << endl;
     */
    return 0;
}
