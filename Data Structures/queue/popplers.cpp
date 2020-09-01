// Obadiah Boda section a
#include "randomengine.h"
#include "queuelist.hpp"


#include <iostream>
#include <string>

using namespace std;



//----------------------------------------
int main () {

int a;
cin >> a;
int b;
string c;
Qlist<int> A;

for (int k =0; k < a; k++)
{
    cin >> c >> b;
    A.enqueue(b);
    A.set_name(c);
}



A.run();

A.enqueue(1);
A.enqueue(2);
cout << "is empty? " << A.isEmpty() <<endl;
cout << "front " << A.front() << endl;
cout << "back " << A.back() << endl;
A.clear();
A.front();
A.back();


}
