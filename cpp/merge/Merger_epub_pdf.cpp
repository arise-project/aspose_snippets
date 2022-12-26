#include "Aspose.PDF.Cpp\EpubLoadOptions.h"
#include "Aspose.PDF.Cpp\Facades\Algorithm.h"
#include "Aspose.PDF.Cpp\Devices\Margins.h"
#include "Aspose.PDF.Cpp\Document.h"
#include "Aspose.PDF.Cpp\Page.h"
#include "Aspose.PDF.Cpp\SaveFormat.h"
using namespace System;
using namespace Aspose::Pdf;

void epub_to_pdf()
{
    auto pathSource1 = u"../../TestData/test.epub";
    auto pathSource2 = u"../../TestData/Second/test.epub";

    auto opt1 = MakeObject<EpubLoadOptions>();
    // use algorithm to prevent content to be truncated
    opt1->PageSizeAdjustmentMode = PageSizeAdjustmentModes::EnlargeRequiredViewportWidthAndDoConversionAgain;
    // usage of margins area during conversion
    opt1->MarginsAreaUsageMode = MarginsAreaUsageModes::PutContentOnMarginAreaIfNecessary;

    // epub files can be parsed and loaded as Aspose Document
    auto firstDoc = MakeObject<Document>(pathSource1, opt1);

    auto opt2 = MakeObject<EpubLoadOptions>();
    // use algorithm to prevent content to be truncated
    opt2->PageSizeAdjustmentMode = PageSizeAdjustmentModes::EnlargeRequiredViewportWidthAndDoConversionAgain;
    // usage of margins area during conversion
    opt2->MarginsAreaUsageMode = MarginsAreaUsageModes::PutContentOnMarginAreaIfNecessary;

    auto secondDoc =MakeObject<Document>(pathSource2, opt2);

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
