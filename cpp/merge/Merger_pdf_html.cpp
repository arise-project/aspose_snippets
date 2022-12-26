#include "Aspose.PDF.Cpp\Document.h"
#include "Aspose.PDF.Cpp\Page.h"
#include "Aspose.PDF.Cpp\HtmlSaveOptions.h"
using namespace System;
using namespace Aspose::Pdf;

void pdf_to_html()
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

    var opt1 = MakeObject<HtmlSaveOptions>();
    // embedd css into a page
    opt1->PartsEmbeddingMode = PartsEmbeddingModes::EmbedAllIntoHtml;
    // embedd images into a page
    opt1->RasterImagesSavingMode = RasterImagesSavingModes::AsEmbeddedPartsOfPngPageBackground;
    // enhance conversion of documents with backgrounds
    opt1->AntialiasingProcessing = AntialiasingProcessingType::TryCorrectResultHtml;
    // use fixed layout render
    opt1->FixedLayout = true;
    outputDoc->Save("test.html", opt1);
}
