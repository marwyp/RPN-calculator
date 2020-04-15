#include <iostream>
#include <conio.h>
#include <string>
#include <windows.h>
#include "stringconvert.h"

using namespace std;

string operation;
vector<string> RPN;


int main()
{
    do
    {
        system("cls");
        cout << "RPN calculator" << endl;
        cout << "Enter a mathematical operation: ";
        getline(cin, operation);
        RPN = ONP_expr(alg_expr(operation));
        cout << "RPN expression: ";
        for (auto i: RPN) {
            cout << i << " ";
        }
        cout << endl << "result: " << kalk_ONP(RPN) << endl;


        cout << "ESC - exit";
    } while (_getch() != 27);
}

