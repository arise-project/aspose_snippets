#include "Aspose.PDF.Cpp/Document.h"
#include "Aspose.PDF.Cpp/Page.h"
#include "Aspose.PDF.Cpp/PageCollection.h"
#include "Aspose.PDF.Cpp/HtmlSaveOptions.h"

using namespace System;
using namespace Aspose::Pdf;

void pdf_to_html()
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

    auto opt1 = MakeObject<HtmlSaveOptions>();
    // embed css into a page
    opt1->PartsEmbeddingMode = Aspose::Pdf::HtmlSaveOptions::PartsEmbeddingModes::EmbedAllIntoHtml;
    // embed images into a page
    opt1->RasterImagesSavingMode = Aspose::Pdf::HtmlSaveOptions::RasterImagesSavingModes::AsEmbeddedPartsOfPngPageBackground;
    // enhance conversion of documents with backgrounds
    opt1->AntialiasingProcessing = Aspose::Pdf::HtmlSaveOptions::AntialiasingProcessingType::TryCorrectResultHtml;
    // use fixed layout render
    opt1->set_FixedLayout(true);
    outputDoc->Save(u"test.html", opt1);
}
