#include <iostream>

#include "Aspose.PDF.Cpp/Document.h"
#include "Aspose.PDF.Cpp/PdfLicense.h"
#include "Aspose.PDF.Cpp/IO/ConvertStrategies/PdfFormat.h"
#include "Aspose.PDF.Cpp/PdfFormatConversionOptions.h"
#include "Aspose.PDF.Cpp/Page.h"
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

void epub_to_pdf()
{
    auto pathSource1 = u"../../../../TestData/test.epub";
    auto pathSource2 = u"../../../../TestData/Second/test.epub";

    com.aspose.pdf.EpubLoadOptions opt1 = new com.aspose.pdf.EpubLoadOptions();
    // use algorithm to prevent content to be truncated
    opt1.setPageSizeAdjustmentMode(com.aspose.pdf.LoadOptions.PageSizeAdjustmentModes.EnlargeRequiredViewportWidthAndDoConversionAgain);
    // usage of margins area during conversion
    opt1.setMarginsAreaUsageMode(com.aspose.pdf.LoadOptions.MarginsAreaUsageModes.PutContentOnMarginAreaIfNecessary);

    // epub files can be parsed and loaded as Aspose Document
    com.aspose.pdf.Document firstDoc = new com.aspose.pdf.Document(pathSource1, opt1);

    com.aspose.pdf.EpubLoadOptions opt2 = new com.aspose.pdf.EpubLoadOptions();
    // use algorithm to prevent content to be truncated
    opt2.setPageSizeAdjustmentMode(com.aspose.pdf.LoadOptions.PageSizeAdjustmentModes.EnlargeRequiredViewportWidthAndDoConversionAgain);
    // usage of margins area during conversion
    opt2.setMarginsAreaUsageMode(com.aspose.pdf.LoadOptions.MarginsAreaUsageModes.PutContentOnMarginAreaIfNecessary);

    com.aspose.pdf.Document secondDoc = new com.aspose.pdf.Document(pathSource2, opt2);

    // create empty pdf document
    auto outputDoc = MakeObject<Document>();

    // set less memory usage with unload instead of fast performance
    outputDoc.setEnableObjectUnload(true);

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
