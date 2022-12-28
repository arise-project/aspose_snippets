#include "Aspose.PDF.Cpp/Document.h"
#include "Aspose.PDF.Cpp/Devices/Resolution.h"
#include "Aspose.PDF.Cpp/Devices/Device.h"
#include "Aspose.PDF.Cpp/Devices/JpegDevice.h"
#include "Aspose.PDF.Cpp/Page.h"
#include "Aspose.PDF.Cpp/Generator/PageInfo.h"
#include "Aspose.PDF.Cpp/PageCollection.h"
#include "Aspose.PDF.Cpp/Devices/ImageDevice.h"
#include "Aspose.PDF.Cpp/Devices/JpegDevice.h"
#include "system/io/file.h"
#include "drawing/bitmap.h"
#include "drawing/graphics.h"

#include <windows.h>
#include <gdiplus.h>
#include <stdio.h>
using namespace Gdiplus;

using namespace System;
using namespace Aspose::Pdf;

INT GetEncoderClsid(const WCHAR* format, CLSID* pClsid);  // helper function

void pdf_to_tiff()
{
        String pathSource1 = u"../../TestData/test.pdf";

        // read pdf file to Aspose Document
        System::SharedPtr<Document> doc = MakeObject<Document>(pathSource1);

		// make list of path to temporary images
		String* images = new String[doc->get_Pages()->get_Count()];

		int newWidth = 0;
		int newHeight = 0;

		// pages in pdf counted from 1 to n
		int pageCount = 1;
		for (auto const& page : doc->get_Pages())
		{
			// setup default resolution to pdf documents 72dpi
			auto resolution = MakeObject<Devices::Resolution>(72);

			// create image device to save document as image with page dimensions and resolution
			auto imageDevice = MakeObject<Devices::JpegDevice>(
				page->get_PageInfo()->get_Width(),
				page->get_PageInfo()->get_Height(),
				resolution);

			// process document page to image
			String outPath = String::Format(u"{0}_test.jpg", pageCount);
			auto stream = System::IO::File::Create(outPath);
			imageDevice->Process(page, stream);
			images[pageCount - 1] = outPath;
			pageCount++;
		}

		// Initialize GDI+.
		GdiplusStartupInput gdiplusStartupInput;
		ULONG_PTR gdiplusToken;
		GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

		EncoderParameters encoderParameters;
		ULONG             parameterValue;
		Status            stat;

		// An EncoderParameters object has an array of
		// EncoderParameter objects. In this case, there is only
		// one EncoderParameter object in the array.
		encoderParameters.Count = 1;

		// Initialize the one EncoderParameter object.
		encoderParameters.Parameter[0].Guid = EncoderSaveFlag;
		encoderParameters.Parameter[0].Type = EncoderParameterValueTypeLong;
		encoderParameters.Parameter[0].NumberOfValues = 1;
		encoderParameters.Parameter[0].Value = &parameterValue;

		// Get the CLSID of the TIFF encoder.
		CLSID encoderClsid;
		GetEncoderClsid(L"image/tiff", &encoderClsid);

		// Create four image objects.
		Image* multi = new Image(L"Shapes.bmp");
		Image* page2 = new Image(L"Cereal.gif");
		Image* page3 = new Image(L"Iron.jpg");
		Image* page4 = new Image(L"House.png");

		// Save the first page (frame).
		parameterValue = EncoderValueMultiFrame;
		stat = multi->Save(L"MultiFrame.tif", &encoderClsid, &encoderParameters);
		if (stat == Ok)
			printf("Page 1 saved successfully.\n");

		// Save the second page (frame).
		parameterValue = EncoderValueFrameDimensionPage;
		stat = multi->SaveAdd(page2, &encoderParameters);
		if (stat == Ok)
			printf("Page 2 saved successfully.\n");

		// Save the third page (frame).
		parameterValue = EncoderValueFrameDimensionPage;
		stat = multi->SaveAdd(page3, &encoderParameters);
		if (stat == Ok)
			printf("Page 3 saved successfully.\n");

		// Save the fourth page (frame).
		parameterValue = EncoderValueFrameDimensionPage;
		stat = multi->SaveAdd(page4, &encoderParameters);
		if (stat == Ok)
			printf("Page 4 saved successfully.\n");

		// Close the multiframe file.
		parameterValue = EncoderValueFlush;
		stat = multi->SaveAdd(&encoderParameters);
		if (stat == Ok)
			printf("File closed successfully.\n");

		delete multi;
		delete page2;
		delete page3;
		delete page4;
		GdiplusShutdown(gdiplusToken);
}
