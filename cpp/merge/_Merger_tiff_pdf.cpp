#include "Aspose.PDF.Cpp/Generator/Image.h"
#include "Aspose.PDF.Cpp/Document.h"
#include "Aspose.PDF.Cpp/Page.h"
#include "Aspose.PDF.Cpp/PageCollection.h"
#include "Aspose.PDF.Cpp/SaveFormat.h"
#include <guiddef.h>

#include <windows.h>
#include <gdiplus.h>
#include <stdio.h>

using namespace System;

INT GetEncoderClsid(const WCHAR* format, CLSID* pClsid);  // helper function

void tiff_to_pdf()
{
    GUID   pageGuid = FrameDimensionPage;
    CLSID  encoderClsid;
    Image  multi(L"../../TestData/test.tiff");

    // Get the CLSID of the PNG encoder.
    GetEncoderClsid(L"image/png", &encoderClsid);

    // Display and save the first page (index 0).
    multi.SelectActiveFrame(&pageGuid, 0);
    graphics.DrawImage(&multi, 10, 10);
    multi.Save(L"Page0.png", &encoderClsid, NULL);

    // Display and save the second page.
    multi.SelectActiveFrame(&pageGuid, 1);
    graphics.DrawImage(&multi, 200, 10);
    multi.Save(L"Page1.png", &encoderClsid, NULL);

    // Display and save the third page.
    multi.SelectActiveFrame(&pageGuid, 2);
    graphics.DrawImage(&multi, 10, 150);
    multi.Save(L"Page2.png", &encoderClsid, NULL);

    // Display and save the fourth page.
    multi.SelectActiveFrame(&pageGuid, 3);
    graphics.DrawImage(&multi, 200, 150);
    multi.Save(L"Page3.png", &encoderClsid, NULL);

    // create empty pdf document
    System::SharedPtr<Document> outputDoc = MakeObject<Document>();

    int index = 1;
    for (var multiImage : images)
    {
        // iterate through tiff frames
        for (var tiffFrame : multiImage.getFrames())
        {
            // set active frame to work with
            multiImage.setActiveFrame(tiffFrame);

            // load bitmap from a frame
            var pixels = multiImage.loadPixels(tiffFrame.getBounds());

            com.aspose.imaging.Source ms = new com.aspose.imaging.sources.FileCreateSource(
                index.toString() + "temp.tiff",
                false); // preserve image on the disk

            // create image savesource to a stream
            var createOptions = new com.aspose.imaging.imageoptions.JpegOptions();
            createOptions.setSource(ms);

            // create empty image with width and hight
            var tiffImage = (com.aspose.imaging.fileformats.jpeg.JpegImage)
                                com.aspose.imaging.Image.create(createOptions, tiffFrame.getWidth(), tiffFrame.getHeight());
            // set frame bounds to save to bitmap
            tiffImage.savePixels(tiffFrame.getBounds(), pixels);
            // save frame bitmap to stream
            tiffImage.save();

            // add new page to document
            com.aspose.pdf.Page page = outputDoc.getPages().add();

            page.getPageInfo().getMargin().setBottom(0);
            page.getPageInfo().getMargin().setTop(0);
            page.getPageInfo().getMargin().setLeft(0);
            page.getPageInfo().getMargin().setRight(0);
            page.getPageInfo().setWidth(tiffFrame.getWidth());
            page.getPageInfo().setHeight(tiffFrame.getHeight());

            // create new image into document
            var image = new com.aspose.pdf.Image();
            // set image source to memory stream
            image.setImageStream(new FileInputStream(index.toString() + "temp.tiff"));

            // add document image to specific page
            page.getParagraphs().add(image);
        }
    }

    // save result pdf to file
    outputDoc->Save(u"test.pdf", SaveFormat::Pdf);
}
