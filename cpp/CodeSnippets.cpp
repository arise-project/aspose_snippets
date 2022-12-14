// CodeSnippets.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// NOT SUPPORTED:
// pdf-epub, pdf-emf
// epub-pdf, html-pdf, pcl-html, mht-pdf

//TODO: make PDF from: jpeg, xps, tex, svg, ps, eps, md, bmp, png, tiff, cgm


#include <iostream>

#include "Aspose.PDF.Cpp/Document.h"
#include "Aspose.PDF.Cpp/PdfLicense.h"
#include "Aspose.PDF.Cpp/IO/ConvertStrategies/PdfFormat.h"
#include "Aspose.PDF.Cpp/PdfFormatConversionOptions.h"
#include "Aspose.PDF.Cpp/Page.h"
#include "Aspose.PDF.Cpp/PageCollection.h"
#include "Aspose.PDF.Cpp/Devices/BmpDevice.h"
#include "Aspose.PDF.Cpp/Devices/EmfDevice.h"
#include "Aspose.PDF.Cpp/Devices/JpegDevice.h"
#include "Aspose.PDF.Cpp/Devices/PngDevice.h"
#include "Aspose.PDF.Cpp/Devices/TextDevice.h"
#include "Aspose.PDF.Cpp/Facades/PdfConverter.h"
#include "Aspose.PDF.Cpp/Generator/Paragraphs.h"
#include "Aspose.PDF.Cpp/Text/TextAbsorber.h"
#include "Aspose.PDF.Cpp/Text/TextFragment.h"
#include "Aspose.PDF.Cpp/SaveFormat.h"

#include "system/string.h"
#include "system/io/file.h"
#include "drawing/imaging/image_format.h"

using namespace System;
using namespace Aspose::Pdf;

bool create_pdf(String filename)
{
    try
    {
        auto lic = MakeObject<License>();
        lic->SetLicense(u"c:/aspose.pdf/license/Aspose.PDF.C++.lic");

        auto document = MakeObject<Document>();

        auto page = document->get_Pages()->Add();
        auto paragraps = page->get_Paragraphs();
        paragraps->Add(MakeObject<Aspose::Pdf::Text::TextFragment>(u"Hello World!"));
        paragraps->Add(MakeObject<Aspose::Pdf::Text::TextFragment>(u"This example is created by Aspose.Pdf for C++."));

        page = document->get_Pages()->Add();
        paragraps = page->get_Paragraphs();
        paragraps->Add(MakeObject<Aspose::Pdf::Text::TextFragment>(u"Second page."));
        paragraps->Add(MakeObject<Aspose::Pdf::Text::TextFragment>(u"This example is created by Aspose.Pdf for C++."));
        document->Save(filename);
    }
    catch (const Exception &ex)
    {
        std::cout << ex->get_Message() << std::endl;
        return false;
    }
    return true;
}

void pdf2doc(String inputFilename, String outputFilename)
{
    auto document = MakeObject<Document>(inputFilename);
    document->Save(outputFilename, SaveFormat::Doc);
}

void pdf2docx(String inputFilename, String outputFilename)
{
    auto document = MakeObject<Document>(inputFilename);
    document->Save(outputFilename, SaveFormat::DocX);
}

void pdf2html(String inputFilename, String outputFilename)
{
    auto document = MakeObject<Document>(inputFilename);
    document->Save(outputFilename, SaveFormat::Html);
}

void pdf2xps(String inputFilename, String outputFilename)
{
    auto document = MakeObject<Document>(inputFilename);
    document->Save(outputFilename, SaveFormat::Xps);
}

void pdf2tex(String inputFilename, String outputFilename)
{
    auto document = MakeObject<Document>(inputFilename);
    document->Save(outputFilename, SaveFormat::TeX);
}

void pdf2svg(String inputFilename, String outputFilename)
{
    auto document = MakeObject<Document>(inputFilename);
    document->Save(outputFilename, SaveFormat::Svg);
}

void pdf2excel(String inputFilename, String outputFilename)
{
    auto document = MakeObject<Document>(inputFilename);
    document->Save(outputFilename, SaveFormat::Excel);
}

void pdf2pptx(String inputFilename, String outputFilename)
{
    auto document = MakeObject<Document>(inputFilename);
    document->Save(outputFilename, SaveFormat::Pptx);
}

void pdf2tiff(String inputFilename, String outputFilename)
{
    auto document = MakeObject<Document>(inputFilename);
    auto converter = MakeObject<Facades::PdfConverter>(document);
    converter->SaveAsTIFF(outputFilename);
}

void pdf2bmp(String inputFilename)
{
    auto document = MakeObject<Document>(inputFilename);
    auto converter = MakeObject<Facades::PdfConverter>(document);

    int counter = 0;
    while (converter->HasNextImage())
        converter->GetNextImage(String::Format(u"{0}.page_{1}.bmp", inputFilename, ++counter), System::Drawing::Imaging::ImageFormat::get_Bmp());
}

void pdf2bmp_method2(String inputFilename)
{
    auto document = MakeObject<Document>(inputFilename);
    auto device = MakeObject<Devices::BmpDevice>();

    int counter = 0;
    for (auto page : document->get_Pages())
    {
        auto stream = System::IO::File::Create(String::Format(u"{0}.method2.page_{1}.bmp", inputFilename, ++counter));
        device->Process(page, stream);
    }
}

void pdf2png(String inputFilename)
{
    auto document = MakeObject<Document>(inputFilename);
    auto converter = MakeObject<Facades::PdfConverter>(document);

    int counter = 0;
    while (converter->HasNextImage())
        converter->GetNextImage(String::Format(u"{0}.page_{1}.png", inputFilename, ++counter), System::Drawing::Imaging::ImageFormat::get_Png());
}

void pdf2jpeg(String inputFilename)
{
    auto document = MakeObject<Document>(inputFilename);
    auto device = MakeObject<Devices::JpegDevice>();

    int counter = 0;
    for (auto page : document->get_Pages())
    {
        auto stream = System::IO::File::Create(String::Format(u"{0}.page_{1}.jpeg", inputFilename, ++counter));
        device->Process(page, stream);
    }
}

void pdf2pdfa(String inputFilename, String outputFilename)
{
    auto document = MakeObject<Document>(inputFilename);
    auto options = MakeObject<PdfFormatConversionOptions>(PdfFormat::PDF_A_1B);
    document->Convert(options);
    document->Save(outputFilename);
}

void pdf2text(String inputFilename, String outputFilename)
{
    auto document = MakeObject<Document>(inputFilename);
    auto textAbsorber = MakeObject<Aspose::Pdf::Text::TextAbsorber>();
    document->get_Pages()->Accept(textAbsorber);
    System::IO::File::WriteAllText(outputFilename, textAbsorber->get_Text());
}

int main()
{
    create_pdf(u"example.pdf");
    pdf2doc(u"example.pdf", u"example.doc");
    pdf2docx(u"example.pdf", u"example.docx");
    pdf2html(u"example.pdf", u"example.html");
    pdf2xps(u"example.pdf", u"example.xps");
    pdf2tex(u"example.pdf", u"example.tex");
    pdf2svg(u"example.pdf", u"example.svg");
    pdf2excel(u"example.pdf", u"example.xlsx");
    pdf2pptx(u"example.pdf", u"example.pptx");
    pdf2tiff(u"example.pdf", u"example.tiff");
    pdf2bmp(u"example.pdf");
    pdf2bmp_method2(u"example.pdf");
    pdf2png(u"example.pdf");
    pdf2jpeg(u"example.pdf");
    pdf2pdfa(u"example.pdf", u"example_pdfa.pdf");
    pdf2text(u"example.pdf", u"example.txt");
}
