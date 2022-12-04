#include <iostream>
#include <string>
using namespace std;
int main() {
    char a = 'a';
    for (int i = 0; i < 8; ++i) {
        a = a + i;
        std::cout << a << std::endl;
        a = 'a';
    }
    
}