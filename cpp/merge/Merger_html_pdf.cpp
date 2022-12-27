#include "Aspose.PDF.Cpp/HtmlLoadOptions.h"
#include "Aspose.PDF.Cpp/Page.h"
#include "Aspose.PDF.Cpp/PageCollection.h"
#include "Aspose.PDF.Cpp/Document.h"
#include "Aspose.PDF.Cpp/SaveFormat.h"
using namespace System;
using namespace Aspose::Pdf;

void html_to_pdf()
{
    String pathSource1 = u"../../TestData/test.html";
    String pathSource2 = u"../../TestData/Second/test.html";

    auto opt1 = MakeObject<HtmlLoadOptions>();

    // set html encoding
    opt1->InputEncoding = u"UTF-8";
    // render all html to single large pdf page
    opt1->RenderToSinglePage = true;

    // html files can be parsed and loaded as Aspose Document
    auto firstDoc = MakeObject<Document>(pathSource1, opt1);

    auto opt2 = MakeObject<HtmlLoadOptions>();
    // set html encoding
    opt2->InputEncoding = u"UTF-8";
    // split html content to pdf pages
    opt2->RenderToSinglePage = false;

    auto secondDoc = MakeObject<Document>(pathSource2, opt2);

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

    // save result pdf to file
    outputDoc->Save(u"test.pdf", SaveFormat::Pdf);
}
