//1. Create empty GDI+ image
multi = new Gdiplus::Image();

//2. read pdf file to Aspose Document
doc = MakeObject<Aspose::Pdf::Document>(u"1.pdf");

//3. setup default resolution to pdf documents 72dpi
// create image device to save document as image with page dimensions and resolution
// process document page to image
// add image from file to GDI+ image
for (auto const& page : doc->get_Pages()) {
	imageDevice = MakeObject<Aspose::Pdf::Devices::JpegDevice>(
				page->get_PageInfo()->get_Width(),
				page->get_PageInfo()->get_Height(),
				MakeObject<Aspose::Pdf::Devices::Resolution>(72));

	
	imageDevice->Process(page, System::IO::File::Create(u"page.jpg"));
	page = new Gdiplus::Image(L"page.jpg");
	multi->SaveAdd(page, &encoderParameters);
}

//4. save GDI+ image to tiff file
stat = multi->Save(L"Merger_pdf_tiff.tiff", &encoderClsid, &encoderParameters);
