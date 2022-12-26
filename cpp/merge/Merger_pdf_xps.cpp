#include "Aspose.PDF.Cpp\Document.h"
#include "Aspose.PDF.Cpp\Page.h"
#include "Aspose.PDF.Cpp\XpsSaveOptions.h"
using namespace System;
using namespace Aspose::Pdf;

void pdf_to_xps()
{
    auto pathSource1 = u"../../TestData/test.pdf";
    auto pathSource2 = u"../../TestData/Second/test.pdf";

    // read pdf file to Aspose Document
    auto firstDoc = MakeObject<Document>(pathSource1);
    auto secondDoc = MakeObject<Document>(pathSource2);

    // create empty pdf document
    auto outputDoc = MakeObject<Document>();

    // set less memory usage with unload instead of fast performance
    outputDoc->EnableObjectUnload = true;

    for (int i = 0; i < firstDoc->get_Pages()->get_Count(); i++)
    {
        auto page = firstDoc->get_Pages()->get_Item(i);
        // add page from one document to another directly
        outputDoc->get_Pages()->Add(page);
    }

    for (int i = 0; i < secondDoc->get_Pages()->get_Count(); i++)
    {
        auto page = secondDoc->get_Pages()->get_Item(i);
        // add page from one document to another directly
        outputDoc->get_Pages()->Add(page);
    }

    var opt1 = MakeObject<XpsSaveOptions>();
    // do not save transparent text to output file
    opt1->SaveTransparentTexts = false;
    // save xps document
    outputDoc->Save("test.xps", opt1);
}
