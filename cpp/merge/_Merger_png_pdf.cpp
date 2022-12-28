#include "Aspose.PDF.Cpp/Document.h"
#include "Aspose.PDF.Cpp/Page.h"
#include "Aspose.PDF.Cpp/PageCollection.h"
#include "Aspose.PDF.Cpp/PageSize.h"
#include "Aspose.PDF.Cpp/Generator/Image.h"
#include "Aspose.PDF.Cpp/Rectangle.h"
#include "Aspose.PDF.Cpp/SaveFormat.h"

using namespace System;
using namespace Aspose::Pdf;

void png_to_pdf()
{
    String pathSource1 = u"../../TestData/test.png";
    String pathSource2 = u"../../TestData/Second/test.png";

    // create empty pdf document
    auto outputDoc = MakeObject<Document>();

    // set less memory usage with unload instead of fast performance
    doc->set_EnableObjectUnload(true);

    // make list of files with images to merge
    String images[] = {pathSource1, pathSource2};

    for (int i = 1; i < sizeof(images); i++)
    {
        auto fs = images[i];
        // add new page to pdf
        auto page = document->get_Pages()->CopyPage();

        // setup page size to be A4
        page->SetPageSize(PageSize::get_A4()->get_Width(), PageSize::get_A4()->get_Height());

        //todo: calc image size

        com.aspose.pdf.Rectangle rect;
        // load image from stream, it supports a lot of formats
        com.aspose.imaging.Image image = com.aspose.imaging.Image.load(fs);
        // read image dimensions to pdf page rectangle
        rect = new com.aspose.pdf.Rectangle(0, 0, image.getWidth() - 1, image.getHeight() - 1);

        // add image to new pdf page
        page->AddImage(fs, rect);
    }

    // save result pdf to file
    doc->Save(u"test.pdf", SaveFormat::Pdf);
}
