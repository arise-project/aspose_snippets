// split.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "split.h"
#include <system/exception.h>

using namespace std;
using namespace System;

int main()
{    
    try
    {
        PDF();
    }
    catch (const System::Exception &ex)
    {
        std::cerr << ex->get_Message() << std::endl;
        return false;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return false;
    }
    catch (...)
    {
        std::cerr << "Unknown error" << std::endl;
        return false;
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
