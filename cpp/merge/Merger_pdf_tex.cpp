#include "Aspose.PDF.Cpp/Document.h"
#include "Aspose.PDF.Cpp/Page.h"
#include "Aspose.PDF.Cpp/PageCollection.h"
#include "Aspose.PDF.Cpp/TeXSaveOptions.h"

using namespace System;
using namespace Aspose::Pdf;

void pdf_to_tex()
{
    String pathSource1 = u"../../TestData/test.pdf";
    String pathSource2 = u"../../TestData/Second/test.pdf";

    // read pdf file to Aspose Document
    auto firstDoc = MakeObject<Document>(pathSource1);
    auto secondDoc = MakeObject<Document>(pathSource2);

    // create empty pdf document
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

    auto opt1 = MakeObject<TeXSaveOptions>();
    // save parsed artifacts, for example images to a directory
    opt1->set_OutDirectoryPath(u"./test");

    outputDoc->Save(u"test.tex", opt1);
}
