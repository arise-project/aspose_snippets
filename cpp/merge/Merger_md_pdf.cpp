#include "Aspose.PDF.Cpp\Document.h"
#include "Aspose.PDF.Cpp\MdLoadOptions.h"
#include "Aspose.PDF.Cpp\Page.h"
#include "Aspose.PDF.Cpp\SaveFormat.h"
using namespace System;
using namespace Aspose::Pdf;

void md_to_pdf()
{
    auto pathSource1 = u"../../TestData/test.md";
    auto pathSource2 = u"../../TestData/Second/test.md";

    // Markdown files can be parsed and loaded as Aspose Document
    auto firstDoc = MakeObject<Document>(pathSource1, MakeObject<MdLoadOptions>());
    auto secondDoc = MakeObject<Document>(pathSource2, MakeObject<MdLoadOptions>());

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

    // save result pdf to file
    outputDoc->Save("test.pdf", SaveFormat::Pdf);
}
