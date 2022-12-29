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

void TXT()
{
    const string pathSource = "../../TestData/test.txt";
            var pdfEditor = new PdfFileEditor();

            using (var doc = new Document(pathSource, new TxtLoadOptions()))
            {
                //save input text to pdf to file
                doc.Save("test.pdf", SaveFormat.Pdf);
            }

            MemoryStream [] pages = pdfEditor.SplitToPages("test.pdf");
            int index = 1;
            foreach(var ms in pages)
            {
                using(var page = new Document(ms))
                {
                    var textAbsorber = new TextAbsorber();
                    page.Pages.Accept(textAbsorber);
                    string extractedText = textAbsorber.Text;
                    File.WriteAllText("text_"+index+".txt", extractedText);
                    index++;
                }
            }
}
