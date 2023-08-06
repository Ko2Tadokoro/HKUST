#include <iostream>
using namespace std;


int main()
{

    cout << "Hello, world!" << endl;

    string hw1("Hello, Martino!");

    cout << hw1 << endl;

    string hw2;

    cout << "Who would you like to greet?" << endl;

    cout << "Name: ";

    cin >> hw2;         //cin: as user presses the enter key it will open a new line automatically

    cout << "Hello, " << hw2 << "!" << endl;

    return 0;

}