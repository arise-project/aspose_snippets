#include <iostream>

#include "Aspose.PDF.Cpp/Document.h"
#include "Aspose.PDF.Cpp/PdfLicense.h"
#include "Aspose.PDF.Cpp/IO/ConvertStrategies/PdfFormat.h"
#include "Aspose.PDF.Cpp/PdfFormatConversionOptions.h"
#include "Aspose.PDF.Cpp/Page.h"
#include "Aspose.PDF.Cpp/PageSize.h"
#include "Aspose.PDF.Cpp/PageCollection.h"
#include "Aspose.PDF.Cpp/Devices/BmpDevice.h"
#include "Aspose.PDF.Cpp/Devices/EmfDevice.h"
#include "Aspose.PDF.Cpp/Devices/JpegDevice.h"
#include "Aspose.PDF.Cpp/Devices/PngDevice.h"
#include "Aspose.PDF.Cpp/Devices/TextDevice.h"
#include "Aspose.PDF.Cpp/Facades/PdfConverter.h"
#include "Aspose.PDF.Cpp/Generator/Paragraphs.h"
#include "Aspose.PDF.Cpp/Text/TextAbsorber.h"
#include "Aspose.PDF.Cpp/Text/TextFragment.h"
#include "Aspose.PDF.Cpp/SaveFormat.h"

#include "system/string.h"
#include "system/io/file.h"
#include "drawing/imaging/image_format.h"

using namespace System;
using namespace Aspose::Pdf;

void bmp_to_pdf()
{
    auto pathSource1 = u"../../TestData/test.bmp";
    auto pathSource2 = u"../../TestData/Second/test.bmp";

    // create empty pdf document
    auto doc = MakeObject<Document>();

    // make list of files with images to merge
    auto images[] = {pathSource1, pathSource2};

    for (int i = 0; i < sizeof(images); i++)
    {
        auto fs = images[i];
        // add new page to pdf
        auto page = document->get_Pages()->Add();

        // setup page size to be A4
        page->SetPageSize(PageSize::get_A4()->get_Width(), PageSize::get_A4()->get_Height());

        // TODO: read image size
        com.aspose.pdf.Rectangle rect;

        // load image from stream, it supports a lot of formats
        com.aspose.imaging.Image image = com.aspose.imaging.Image.load(fs);
        // read image dimensions to pdf page rectangle
        rect = new com.aspose.pdf.Rectangle(0, 0, image.getWidth() - 1, image.getHeight() - 1);

        // add image to new pdf page
        page->AddImage(fs, rect);
    }

    // save result pdf to file
    doc->Save("test.pdf", SaveFormat::Pdf);
}
