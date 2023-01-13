
	// read pdf file to Aspose Document
	System::SharedPtr<Document> doc = MakeObject<Document>(u"1.pdf");

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
	newImage->Save(u"Merger_pdf_jpeg.jpg", System::Drawing::Imaging::ImageFormat::get_Jpeg());
