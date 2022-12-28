#include "Aspose.PDF.Cpp/Document.h"
#include "Aspose.PDF.Cpp/Page.h"
#include "Aspose.PDF.Cpp/PageCollection.h"
#include "Aspose.PDF.Cpp/XpsSaveOptions.h"

using namespace System;
using namespace Aspose::Pdf;

void pdf_to_xps()
{
    String pathSource1 = u"../../TestData/test.pdf";
    String pathSource2 = u"../../TestData/Second/test.pdf";

    // read pdf file to Aspose Document
    System::SharedPtr<Document> firstDoc = MakeObject<Document>(pathSource1);
    System::SharedPtr<Document> secondDoc = MakeObject<Document>(pathSource2);

    // create empty pdf document
    System::SharedPtr<Document> outputDoc = MakeObject<Document>();

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

    auto opt1 = MakeObject<XpsSaveOptions>();
    // do not save transparent text to output file
    opt1->set_SaveTransparentTexts(false);
    // save xps document
    outputDoc->Save(u"test.xps", opt1);
}
