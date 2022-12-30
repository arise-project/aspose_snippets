// merge.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "Merger_cgm_pdf.cpp"
#include "Merger_eps_pdf.cpp"
#include "Merger_epub_pdf.cpp"
#include "Merger_html_pdf.cpp"
#include "Merger_md_pdf.cpp"
#include "Merger_mht_pdf.cpp"
#include "Merger_pcl_pdf.cpp"
#include "Merger_pdf_doc.cpp"
#include "Merger_pdf_epub.cpp"
#include "Merger_pdf_docx.cpp"
#include "Merger_pdf_html.cpp"
#include "Merger_pdf_pptx.cpp"
#include "Merger_pdf_pdfa.cpp"
#include "Merger_pdf_svg.cpp"
#include "Merger_pdf_tex.cpp"
#include "Merger_pdf_text.cpp"
#include "Merger_pdf_xls.cpp"
#include "Merger_pdf_xps.cpp"
#include "Merger_ps_pdf.cpp"
#include "Merger_svg_pdf.cpp"
#include "Merger_tex_pdf.cpp"
#include "Merger_xps_pdf.cpp"
#include "Merger_pdf_tiff.cpp"
#include "Merger_tiff_pdf.cpp"
#include "Merger_bmp_pdf.cpp"
#include "Merger_jpg_docx.cpp"
#include "Merger_jpg_pdf.cpp"
#include "Merger_png_pdf.cpp"

using namesapace std;
using namesapce System;

int main()
{
    try
    {
        pdf_to_tiff();    
    }
    catch (const Exception &ex)
    {
        std::cout << ex->get_Message() << std::endl;
        return false;
    }
	
	try
    {
        tiff_to_pdf();    
    }
    catch (const Exception &ex)
    {
        std::cout << ex->get_Message() << std::endl;
        return false;
    }
	
	try
    {
        bmp_to_pdf();    
    }
    catch (const Exception &ex)
    {
        std::cout << ex->get_Message() << std::endl;
        return false;
    }
	
	try
    {
        jpg_to_docx();    
    }
    catch (const Exception &ex)
    {
        std::cout << ex->get_Message() << std::endl;
        return false;
    }
	
	try
    {
        jpg_to_pdf();    
    }
    catch (const Exception &ex)
    {
        std::cout << ex->get_Message() << std::endl;
        return false;
    }
	
	try
    {
        png_to_pdf();    
    }
    catch (const Exception &ex)
    {
        std::cout << ex->get_Message() << std::endl;
        return false;
    }
	
	try
    {
        cgm_to_pdf();    
    }
    catch (const Exception &ex)
    {
        std::cout << ex->get_Message() << std::endl;
        return false;
    }
	
	try
    {
        eps_to_pdf();   
    }
    catch (const Exception &ex)
    {
        std::cout << ex->get_Message() << std::endl;
        return false;
    }
	
	try
    {
        epub_to_pdf();    
    }
    catch (const Exception &ex)
    {
        std::cout << ex->get_Message() << std::endl;
        return false;
    }
	
	try
    {
        html_to_pdf();    
    }
    catch (const Exception &ex)
    {
        std::cout << ex->get_Message() << std::endl;
        return false;
    }
	
	try
    {
        md_to_pdf();    
    }
    catch (const Exception &ex)
    {
        std::cout << ex->get_Message() << std::endl;
        return false;
    }
	
	try
    {
        mht_to_pdf();    
    }
    catch (const Exception &ex)
    {
        std::cout << ex->get_Message() << std::endl;
        return false;
    }
	
	try
    {
        pcl_to_pdf();    
    }
    catch (const Exception &ex)
    {
        std::cout << ex->get_Message() << std::endl;
        return false;
    }
	
	try
    {
        pdf_to_doc();    
    }
    catch (const Exception &ex)
    {
        std::cout << ex->get_Message() << std::endl;
        return false;
    }
	
	try
    {
        pdf_to_docx();    
    }
    catch (const Exception &ex)
    {
        std::cout << ex->get_Message() << std::endl;
        return false;
    }
	
	try
    {
        pdf_to_epub();    
    }
    catch (const Exception &ex)
    {
        std::cout << ex->get_Message() << std::endl;
        return false;
    }
	
	try
    {
        pdf_to_html();    
    }
    catch (const Exception &ex)
    {
        std::cout << ex->get_Message() << std::endl;
        return false;
    }
    
    try
    {
        pdf_to_pdfa();    
    }
    catch (const Exception &ex)
    {
        std::cout << ex->get_Message() << std::endl;
        return false;
    }	
	
	try
    {
        pdf_to_pptx();    
    }
    catch (const Exception &ex)
    {
        std::cout << ex->get_Message() << std::endl;
        return false;
    }
    
	try
    {
        pdf_to_svg();    
    }
    catch (const Exception &ex)
    {
        std::cout << ex->get_Message() << std::endl;
        return false;
    }
    
	try
    {
        pdf_to_tex();    
    }
    catch (const Exception &ex)
    {
        std::cout << ex->get_Message() << std::endl;
        return false;
    }
    
	try
    {
        pdf_to_text();    
    }
    catch (const Exception &ex)
    {
        std::cout << ex->get_Message() << std::endl;
        return false;
    }
    
	try
    {
        pdf_to_xls();    
    }
    catch (const Exception &ex)
    {
        std::cout << ex->get_Message() << std::endl;
        return false;
    }
    
	try
    {
        pdf_to_xps();    
    }
    catch (const Exception &ex)
    {
        std::cout << ex->get_Message() << std::endl;
        return false;
    }
    
	try
    {
        ps_to_pdf();    
    }
    catch (const Exception &ex)
    {
        std::cout << ex->get_Message() << std::endl;
        return false;
    }
    
	
	try
    {
        svg_to_pdf();    
    }
    catch (const Exception &ex)
    {
        std::cout << ex->get_Message() << std::endl;
        return false;
    }
    
	try
    {
        tex_to_pdf();    
    }
    catch (const Exception &ex)
    {
        std::cout << ex->get_Message() << std::endl;
        return false;
    }
	
	try
    {
        xps_to_pdf();    
    }
    catch (const Exception &ex)
    {
        std::cout << ex->get_Message() << std::endl;
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
