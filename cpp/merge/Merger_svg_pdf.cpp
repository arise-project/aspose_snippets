#include "Aspose.PDF.Cpp/Page.h"
#include "Aspose.PDF.Cpp/PageCollection.h"
#include "Aspose.PDF.Cpp/SvgLoadOptions.h"
#include "Aspose.PDF.Cpp/Document.h"
#include "Aspose.PDF.Cpp/SaveFormat.h"
using namespace System;
using namespace Aspose::Pdf;

void svg_to_pdf()
{
    String pathSource1 = u"../../TestData/test.svg";
    String pathSource2 = u"../../TestData/Second/test.svg";

    // Adust pdf page size to svg size
    var opt1 = MakeObject<SvgLoadOptions>();
    opt1->AdjustPageSize = true;
    // SVG files can be parsed and loaded as Aspose Document
    var firstDoc = MakeObject<Document>(pathSource1, opt1);

    // Use default pdf page size
    var opt2 = MakeObject<SvgLoadOptions>();
    opt1->AdjustPageSize = false;
    var secondDoc = MakeObject<Document>(pathSource2, opt2);

    // create empty pdf document
    auto outputDoc = MakeObject<Document>();

    // set less memory usage with unload instead of fast performance
    outputDoc->EnableObjectUnload = true;

    for (int i = 1; i < firstDoc->get_Pages()->get_Count(); i++)
    {
        auto page = firstDoc->get_Pages()->idx_get(i);
        // add page from one document to another directly
        outputDoc->get_Pages()->Add(page);
    }

    for (int i = 1; i < secondDoc->get_Pages()->get_Count(); i++)
    {
        auto page = secondDoc->get_Pages()->idx_get(i);
        // add page from one document to another directly
        outputDoc->get_Pages()->Add(page);
    }

    // save result pdf to file
    outputDoc->Save(u"test.pdf", SaveFormat::Pdf);
}
