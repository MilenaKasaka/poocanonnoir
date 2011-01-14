#include <iostream>
#include "Interface.h"

using namespace std;
int main (int argc, char * const argv[]) {
    // insert code here...
    Interface i;
	cout << i.initNbJoueurs(4) << endl;
	cout << i.lanceDe() << endl;
	cout << i.lanceDe() << endl;
	
    return 0;
}
