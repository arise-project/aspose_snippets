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

void tiff_to_pdf()
{
    var pathSource1 = "../../TestData/test.tiff";
        var pathSource2 = "../../TestData/Second/test.tiff";

        //Load tiff to Aspose image
        var multiImage1 = (com.aspose.imaging.fileformats.tiff.TiffImage) com.aspose.imaging.Image.load(pathSource1);
        var multiImage2 = (com.aspose.imaging.fileformats.tiff.TiffImage) com.aspose.imaging.Image.load(pathSource2);

        //make list of tiff images to merge
        var images = new com.aspose.imaging.fileformats.tiff.TiffImage[]{multiImage1, multiImage2};

        //create empty pdf document
        var outputDoc = new com.aspose.pdf.Document();

		int index = 1;
        for (var multiImage : images) {
            //iterate througn tiff frames
            for (var tiffFrame : multiImage.getFrames()) {
                //set active frame to work with
                multiImage.setActiveFrame(tiffFrame);

                //load bitmap from a frame
                var pixels = multiImage.loadPixels(tiffFrame.getBounds());

                com.aspose.imaging.Source ms = new com.aspose.imaging.sources.FileCreateSource(
                        index.toString() + "temp.tiff",
                        false); //preserve image on the disk

                //create image savesource to a stream
                var createOptions = new com.aspose.imaging.imageoptions.JpegOptions();
                createOptions.setSource(ms);

                //create empty image with width and hight
                var tiffImage = (com.aspose.imaging.fileformats.jpeg.JpegImage)
                        com.aspose.imaging.Image.create(createOptions, tiffFrame.getWidth(), tiffFrame.getHeight());
                //set frame bounds to save to bitmap
                tiffImage.savePixels(tiffFrame.getBounds(), pixels);
                //save frame bitmap to stream
                tiffImage.save();

                //add new page to document
                com.aspose.pdf.Page page = outputDoc.getPages().add();

                page.getPageInfo().getMargin().setBottom(0);
                page.getPageInfo().getMargin().setTop(0);
                page.getPageInfo().getMargin().setLeft(0);
                page.getPageInfo().getMargin().setRight(0);
                page.getPageInfo().setWidth(tiffFrame.getWidth());
                page.getPageInfo().setHeight(tiffFrame.getHeight());

                //create new image into document
                var image = new com.aspose.pdf.Image();
                //set image source to memeory stream
                image.setImageStream(new FileInputStream(index.toString() + "temp.tiff"));

                //add document image to specific page
                page.getParagraphs().add(image);
            }
        }

        //save result pdf to file
        outputDoc.save("test.pdf", com.aspose.pdf.SaveFormat.Pdf);
}
