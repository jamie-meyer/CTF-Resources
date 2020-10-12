#include <cstdlib> 
#include <ctime>
#include <iostream>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <vector>

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::vector;

int main() {
    char key[] = "flag{m0re_m0rse_pleas3}";
    char key1[23];
    char key2[23];
    for (int i = 0; i < 23; i++)
    {
        int random = rand()%255;
        key1[i] = random;
        key2[i] = key[i] ^ random;
    }
    for (int i = 0; i < 23; i++) {
        cout << (int) (key1[i]) << ",";
    }
    cout << endl;
    for (int i = 0; i < 23; i++) {
        cout << (int) (key2[i]) << ",";
    }
}