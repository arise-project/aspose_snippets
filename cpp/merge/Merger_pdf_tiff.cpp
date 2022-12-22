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

void pdf_to_tiff()
{
        auto pathSource1 = u"../../TestData/test.pdf";

        //read pdf file to Aspose Document
        var doc = new com.aspose.pdf.Document(pathSource1);

        //make list of Aspose images
        var images = new com.aspose.imaging.Image[doc.getPages().size()];

        //pdf document count pages from 1 to n
        for (int pageCount = 1; pageCount <= doc.getPages().size(); pageCount++) {
            //setup default resolution to pdf documents 72dpi
            var resolution = new com.aspose.pdf.devices.Resolution(72);

            //create image device to save document as image with page dimensions and resolution
            var imageDevice = new com.aspose.pdf.devices.JpegDevice(
                    (int) doc.getPages().get_Item(pageCount).getPageInfo().getWidth(),
                    (int) doc.getPages().get_Item(pageCount).getPageInfo().getHeight(), resolution);

            var outPath = "test_" + pageCount + ".jpg";

            //process document page to image
            imageDevice.process(doc.getPages().get_Item(pageCount), outPath);

            //load image from file, it supports a lot of formats
            images[pageCount - 1] = com.aspose.imaging.Image.load(outPath);
        }

        //use file system as source for save image
        com.aspose.imaging.Source fileSource = new com.aspose.imaging.sources.FileCreateSource(
                "./test.tiff",
                false); //preserve image on the disk

        var createOptions = new com.aspose.imaging.imageoptions.TiffOptions(
                //The default tiff format is no compression with B/W 1 bit per pixel only format.
                //You can also use this setting to get an empty options and initialize with your tags or other settings.
                com.aspose.imaging.fileformats.tiff.enums.TiffExpectedFormat.Default);

        //type of image compression Lzw
        createOptions.setCompression(com.aspose.imaging.fileformats.tiff.enums.TiffCompressions.Lzw);
        //Pits per pixel
        createOptions.setBitsPerSample(new int[]{8, 8, 8});
        //Photometric RGB interpolation
        createOptions.setPhotometric(com.aspose.imaging.fileformats.tiff.enums.TiffPhotometrics.Rgb);
        createOptions.setSource(fileSource);

        var tiffImage = com.aspose.imaging.Image.create(images, true);
        //save tiff file
        tiffImage.save("test.tiff", createOptions);
}
