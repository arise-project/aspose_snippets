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

void pdf_to_pdfa()
{
        auto pathSource1 = u"../../TestData/test.pdf";
        auto pathSource2 = u"../../TestData/Second/test.pdf";

        //read pdf file to Aspose Document
        auto firstDoc = MakeObject<Document>(pathSource1);
        auto secondDoc = MakeObject<Document>(pathSource2);

        //create empty pdf document
        auto outputDoc = MakeObject<Document>();

        //set less memory usage with unload instead of fast performance
        outputDoc->EnableObjectUnload = true;

        for (var page : firstDoc.getPages()) {
            //add page from one document to another directly
            outputDoc->get_Pages()->Add(page);
        }

        for (var page : secondDoc.getPages()) {
            //add page from one document to another directly
            outputDoc->get_Pages()->Add(page);
        }

        //save document as specific pdf standard PDFA 3Y
        outputDoc.convert(
                "test.pdf",
                com.aspose.pdf.PdfFormat.PDF_A_3U,
                //delete objects that impossible to convert
                com.aspose.pdf.ConvertErrorAction.Delete);
    }
}
