#include "Aspose.PDF.Cpp/Document.h"
#include "Aspose.PDF.Cpp/Page.h"
#include "Aspose.PDF.Cpp/PageCollection.h"
#include "Aspose.PDF.Cpp/PptxSaveOptions.h"
#include "Aspose.PDF.Cpp/Generator\Image.h"
using namespace System;
using namespace Aspose::Pdf;

void pdf_to_pptx()
{
    String pathSource1 = u"../../TestData/test.pdf";
    String pathSource2 = u"../../TestData/Second/test.pdf";

    // read pdf file to Aspose Document
    auto firstDoc = MakeObject<Document>(pathSource1);
    auto secondDoc = MakeObject<Document>(pathSource2);

    auto outputDoc = MakeObject<Document>();
    // set less memory usage with unload instead of fast performance
    outputDoc->set_EnableObjectUnload(true);

    for (int i = 1; i < firstDoc->get_Pages()->get_Count(); i++)
    {
        auto page = firstDoc->get_Pages()->idx_get(i);
        // add page from one document to another directly
        outputDoc->get_Pages()->CopyPage(page);
    }

    for (int i = 1; i < secondDoc->get_Pages()->get_Count(); i++)
    {
        auto page = secondDoc->get_Pages()->idx_get(i);
        // add page from one document to another directly
        outputDoc->get_Pages()->CopyPage(page);
    }

    var opt1 = MakeObject<PptxSaveOptions>();
    // save all content on page as single image
    opt1->SlidesAsImages = true;
    outputDoc->Save(u"test.pptx", opt1);
}
