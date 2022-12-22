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

void tex_to_pdf()
{
        auto pathSource1 = u"../../TestData/test.tex";
        auto pathSource2 = u"../../TestData/Second/test.tex";

        var opt1 = new com.aspose.pdf.TeXLoadOptions();

        //Cancels ligatures in all fonts
        opt1.setNoLigatures(false);
        //Rasterize scientific formulas to images
        opt1.setRasterizeFormulas(true);
        //Print parsing steps details to console output
        opt1.setShowTerminalOutput(true);

        //TeX files can be parsed and loaded as Aspose Document
        var firstDoc = new com.aspose.pdf.Document(pathSource1, opt1);

        var opt2 = new com.aspose.pdf.TeXLoadOptions();

        //Set ligatures in all fonts
        opt2.setNoLigatures(false);
        //Rasterize scientific formulas to images
        opt2.setRasterizeFormulas(true);
        //Print parsing steps details to console output
        opt2.setShowTerminalOutput(true);
        var secondDoc = new com.aspose.pdf.Document(pathSource2, opt2);

        auto outputDoc = MakeObject<Document>();

        //set less memory usage with unload instead of fast performance
        outputDoc.setEnableObjectUnload(true);

        for (var page : firstDoc.getPages()) {
            //add page from one document to another directly
            outputDoc.getPages().add(page);
        }

        for (var page : secondDoc.getPages()) {
            //add page from one document to another directly
            outputDoc.getPages().add(page);
        }

        //save result pdf to file
        outputDoc->Save("test.pdf", SaveFormat::Pdf);
}
