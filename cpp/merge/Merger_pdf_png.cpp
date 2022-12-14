#include "Aspose.PDF.Cpp/Document.h"
#include "Aspose.PDF.Cpp/Generator/Drawing/Path.h"
#include "Aspose.PDF.Cpp/Devices/Resolution.h"
#include "Aspose.PDF.Cpp/Generator/Image.h"
#include "Aspose.PDF.Cpp/Devices/Device.h"
#include "Aspose.PDF.Cpp/Page.h"
#include "Aspose.PDF.Cpp/Generator/PageInfo.h"
#include "Aspose.PDF.Cpp/PageCollection.h"
#include "Aspose.PDF.Cpp/Devices/ImageDevice.h"
#include "Aspose.PDF.Cpp/Devices/PngDevice.h"
#include "Aspose.PDF.Cpp/Rectangle.h"
#include "system/io/file.h"
#include "drawing/image.h"
#include "drawing/bitmap.h"
#include "drawing/graphics.h"

using namespace System;
using namespace Aspose::Pdf;

void pdf_to_png()
{
	String pathSource = u"../../TestData/test.pdf";

	// read pdf file to Aspose Document
	System::SharedPtr<Document> doc = MakeObject<Document>(pathSource);

	// make list of path to temporary images
	int imageCount = doc->get_Pages()->get_Count();
	String* images = new String[imageCount];

	int newWidth = 0;
	int newHeight = 0;

	// pages in pdf counted from 1 to n
	int pageCount = 1;
	for (auto const& page : doc->get_Pages())
	{
		// setup default resolution to pdf documents 72dpi
		auto resolution = MakeObject<Devices::Resolution>(72);

		// create image device to save document as image with page dimensions and resolution
		auto imageDevice = MakeObject<Devices::PngDevice>(
			page->get_PageInfo()->get_Width(),
			page->get_PageInfo()->get_Height(),
			resolution);

		// process document page to image
		String outPath = String::Format(u"{0}_test.png", pageCount);
		auto stream = System::IO::File::Create(outPath);
		imageDevice->Process(page, stream);
		images[pageCount - 1] = outPath;
		pageCount++;
	}

	for (int i = 0; i < imageCount; i++)
	{
		String path = images[i];
		// load image from file, it supports a lot of formats
		auto image = System::Drawing::Image::FromFile(path);
		// read image dimensions to pdf page rectangle
		auto rect = new Aspose::Pdf::Rectangle(0, 0, image->get_Width() - 1, image->get_Height() - 1);

		newWidth += image->get_Width();
		newHeight = newHeight < image->get_Height() ? image->get_Height() : newHeight;
	}

	auto newImage = new System::Drawing::Bitmap(newWidth, newHeight);
	auto canvas = System::Drawing::Graphics::FromImage(newImage);
	canvas->set_InterpolationMode(System::Drawing::Drawing2D::InterpolationMode::HighQualityBicubic);
	int stitchedWidth = 0;
	for (int i = 0; i < imageCount; i++)
	{
		String fs = images[i];
		// load image from file, it supports a lot of formats
		auto image = System::Drawing::Image::FromFile(fs);
		canvas->DrawImage(image, stitchedWidth, 0);
		stitchedWidth += image->get_Width();
	}

	canvas->Save();

	// save created image to disk
	newImage->Save(u"Merger_pdf_png.png", System::Drawing::Imaging::ImageFormat::get_Png());
}
