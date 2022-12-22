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

void pcl_to_pdf()
{
        auto pathSource1 = u"../../../../TestData/test.pcl";
        auto pathSource2 = u"../../../../TestData/Second/test.pcl";

        com.aspose.pdf.PclLoadOptions opt1 = new com.aspose.pdf.PclLoadOptions();
        //suspend not critical errors
        opt1.setSupressErrors(true);
        //pcl files can be parsed and loaded as Aspose Document
        com.aspose.pdf.Document firstDoc = new com.aspose.pdf.Document(pathSource1, opt1);

        com.aspose.pdf.PclLoadOptions opt2 = new com.aspose.pdf.PclLoadOptions();
        //suspend not critical errors
        opt2.setSupressErrors(true);
        com.aspose.pdf.Document secondDoc = new com.aspose.pdf.Document(pathSource2, opt2);

        //create empty pdf document
        auto outputDoc = MakeObject<Document>();

        //set less memory usage with unload instead of fast performance
        outputDoc->EnableObjectUnload = true;

        for (com.aspose.pdf.Page page : firstDoc.getPages()) {
            //add page from one document to another directly
            outputDoc->get_Pages()->Add(page);
        }

        for (com.aspose.pdf.Page page : secondDoc.getPages()) {
            //add page from one document to another directly
            outputDoc->get_Pages()->Add(page);
        }

        //save result pdf to file
        outputDoc->Save("test.pdf", SaveFormat::Pdf);
}
