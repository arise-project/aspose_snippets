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

void pdf_to_bmp()
{
        auto pathSource = u"../../TestData/test.pdf";

        //read pdf file to Aspose Document
        auto doc = MakeObject<Document>(inputFilename);

        //make list of path to temporary images
        ArrayList<String> images = new ArrayList<>();

        //pages in pdf counted from 1 to n
        for (int pageCount = 1; pageCount <= doc.getPages().size(); pageCount++) {
            //setup default resolution to pdf documents 72dpi
            com.aspose.pdf.devices.Resolution resolution = new com.aspose.pdf.devices.Resolution(72);

            //create image device to save document as image with page dimensions and resolution
            com.aspose.pdf.devices.BmpDevice imageDevice = new com.aspose.pdf.devices.BmpDevice(
                    (int) doc.getPages().get_Item(pageCount).getPageInfo().getWidth(),
                    (int) doc.getPages().get_Item(pageCount).getPageInfo().getHeight(),
                    resolution);

            String outPath = "test_" + pageCount + ".bmp";

            //process document page to image
            imageDevice.process(doc.getPages().get_Item(pageCount), outPath);
            images.add(outPath);
        }

        //make list pf parsed image sizes
        ArrayList<com.aspose.imaging.Size> imageSizes = new ArrayList<>();
        for (String path : images) {
            //load image from file, it supports a lot of formats
            com.aspose.imaging.RasterImage image =
                    (com.aspose.imaging.RasterImage) com.aspose.imaging.Image.load(path);
            imageSizes.add(image.getSize());
        }

        int newWidth = 0;
        int newHeight = 0;
        for (com.aspose.imaging.Size s : imageSizes) {
            newWidth += s.getWidth();
            newHeight = newHeight < s.getHeight() ? s.getHeight() : newHeight;
        }

        //use file system as source for save image
        com.aspose.imaging.Source fileSource = new com.aspose.imaging.sources.FileCreateSource(
                "./test.bmp",
                false); //preserve image on the disk

        com.aspose.imaging.imageoptions.BmpOptions options = new com.aspose.imaging.imageoptions.BmpOptions();
        options.setSource(fileSource);

        //create empty image with calculated witdh and hight
        com.aspose.imaging.fileformats.bmp.BmpImage newImage = (com.aspose.imaging.fileformats.bmp.BmpImage) com.aspose.imaging.Image.create(options, newWidth, newHeight);
        int stitchedWidth = 0;
        for (String imagePath : images) {
            //load image from file, it supports a lot of formats
            com.aspose.imaging.RasterImage image = (com.aspose.imaging.RasterImage) com.aspose.imaging.Image.load(imagePath);
            //create bounds to insert small image into large
            com.aspose.imaging.Rectangle bounds = new com.aspose.imaging.Rectangle(
                    stitchedWidth,
                    0,
                    image.getWidth(),
                    image.getHeight());

            //combining images into new one
            newImage.saveArgb32Pixels(
                    //where to insert image
                    bounds,
                    //convert image chunk to 32bit Argb
                    image.loadArgb32Pixels(image.getBounds()));
            stitchedWidth += image.getWidth();
        }

        //save created image to disk
        newImage.save();
}
