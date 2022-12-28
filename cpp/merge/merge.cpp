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

int main()
{
	std::cout << "Hello World!\n";

	pdf_to_tiff();
	tiff_to_pdf();
	bmp_to_pdf();
	jpg_to_docx();
	jpg_to_pdf();
	png_to_pdf();
	cgm_to_pdf();
	eps_to_pdf();
	epub_to_pdf();
	html_to_pdf();
	md_to_pdf();
	mht_to_pdf();
	pcl_to_pdf();
	pdf_to_doc();
	pdf_to_docx();
	pdf_to_epub();
	pdf_to_html();
	pdf_to_pdfa();
	pdf_to_pptx();
	pdf_to_svg();
	pdf_to_tex();
	pdf_to_text();
	pdf_to_xls();
	pdf_to_xps();
	ps_to_pdf();
	svg_to_pdf();
	tex_to_pdf();
	xps_to_pdf();
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
