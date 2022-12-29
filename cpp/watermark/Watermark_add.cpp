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

void add()
{
    const string pathSource = "../../TestData/test.pdf";
            const string watermarkSource = "../../TestData/test.jpg";
            var doc = new Aspose.Pdf.Document(pathSource);

            var artifact = new Aspose.Pdf.WatermarkArtifact();
            artifact.SetImage(new FileStream(watermarkSource, FileMode.Open));

            artifact.ArtifactHorizontalAlignment = Aspose.Pdf.HorizontalAlignment.Center;
            artifact.ArtifactVerticalAlignment = Aspose.Pdf.VerticalAlignment.Center;
            artifact.Rotation = 15;
            artifact.Opacity = 1;
            artifact.IsBackground = true;
            doc.Pages[1].Artifacts.Add(artifact);

            //save result pdf to file
            doc.Save("test.pdf", Aspose.Pdf.SaveFormat.Pdf);
}
