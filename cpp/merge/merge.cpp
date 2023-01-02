// merge.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "merger.h"
#include <system/exception.h>

using namespace std;
using namespace System;

int main()
{
    try
    {
        //pdf_to_tiff();    
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
	
	try
    {
        //tiff_to_pdf();    
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
	
	try
    {
        bmp_to_pdf();    
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
	
	try
    {
        //jpg_to_docx();    
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
	
	try
    {
        jpg_to_pdf();    
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
	
	try
    {
        png_to_pdf();    
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
	
	try
    {
        //cgm_to_pdf();    
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
	
	try
    {
        //eps_to_pdf();   
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
	
	try
    {
        //epub_to_pdf();    
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
	
	try
    {
        //html_to_pdf();    
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
	
	try
    {
        //md_to_pdf();    
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
	
	try
    {
        //mht_to_pdf();    
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
	
	try
    {
        //pcl_to_pdf();    
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
	
	try
    {
        //pdf_to_doc();    
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
	
	try
    {
        //todo: docx
        //pdf_to_docx();    
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
	
	try
    {
        //todo: error
        //pdf_to_epub();    
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
	
	try
    {
        //todo: error
        //pdf_to_html();    
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
    
    try
    {
        //todo: error
        //pdf_to_pdfa();    
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
	
	try
    {
        //todo: error
        //pdf_to_pptx();    
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
    
	try
    {
        //pdf_to_svg();    
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
    
	try
    {
        //pdf_to_tex();    
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
    
	try
    {
        pdf_to_text();    
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
    
	try
    {
        //todo: error
        //pdf_to_xls();    
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
    
	try
    {
        //error
        //pdf_to_xps();    
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
    
	try
    {
        //ps_to_pdf();    
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
    
	
	try
    {
        //error
        //svg_to_pdf();    
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
    
	try
    {
        //error
        //tex_to_pdf();    
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
	
	try
    {
        //xps_to_pdf();    
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
