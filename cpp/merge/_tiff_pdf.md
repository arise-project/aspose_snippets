```cpp
#include "Aspose.PDF.Cpp/Document.h"
#include "Aspose.PDF.Cpp/Page.h"
#include "Aspose.PDF.Cpp/Generator/PageInfo.h"
#include "Aspose.PDF.Cpp/Generator/MarginInfo.h"
#include <Aspose.PDF.Cpp/Generator/Image.h>
#include <Aspose.PDF.Cpp/Generator/Paragraphs.h>
#include "Aspose.PDF.Cpp/PageCollection.h"
#include "Aspose.PDF.Cpp/SaveFormat.h"
#include <guiddef.h>

#include <windows.h>
#include <gdiplus.h>
#include <stdio.h>
#include <gdiplusimaging.h>
#include <system/io/file.h>

using namespace System;
using namespace Gdiplus;

INT GetEncoderClsid(const WCHAR* format, CLSID* pClsid);  // helper function

void tiff_to_pdf()
{
    GUID   pageGuid = FrameDimensionPage;
    CLSID  encoderClsid;
    Gdiplus::Image  multi(L"../../TestData/test.tiff");

    // Get the CLSID of the PNG encoder.
    GetEncoderClsid(L"image/png", &encoderClsid);

    // Display and save the first page (index 0).
    multi.SelectActiveFrame(&pageGuid, 0);
    multi.Save(L"Page0.png", &encoderClsid, NULL);

    // Display and save the second page.
    multi.SelectActiveFrame(&pageGuid, 1);
    multi.Save(L"Page1.png", &encoderClsid, NULL);

    // make list of path to temporary images
    auto images = { u"Page0.png", u"Page1.png" };

    // create empty pdf document
    auto outputDoc = MakeObject<Aspose::Pdf::Document>();

    for (auto path : images)
    {
        // add new page to document
        auto page = outputDoc->get_Pages()->Add();

        page->get_PageInfo()->get_Margin()->set_Bottom(0);
        page->get_PageInfo()->get_Margin()->set_Top(0);
        page->get_PageInfo()->get_Margin()->set_Left(0);
        page->get_PageInfo()->get_Margin()->set_Right(0);
        page->get_PageInfo()->set_Width(1000);
        page->get_PageInfo()->set_Height(1000);

        // create new image into document
        auto image = MakeObject<Aspose::Pdf::Image>();
        // set image source to memory stream
        auto stream = System::IO::File::Create(path);
        image->set_ImageStream(stream);

        // add document image to specific page
        page->get_Paragraphs()->Add(image);
    }

    // save result pdf to file
    outputDoc->Save(u"Merger_tiff_pdf.pdf", Aspose::Pdf::SaveFormat::Pdf);
}

```