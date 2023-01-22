
//1. read pdf file to Aspose Document
doc = MakeObject<Aspose::Pdf::Document>(u"1.pdf");

//2. setup default resolution to pdf documents 72dpi
// create image device to save document as image with page dimensions and resolution
// process document page to image
for (auto const& page : doc->get_Pages()) {
	imageDevice = MakeObject<Aspose::Pdf::Devices::JpegDevice>(
				page->get_PageInfo()->get_Width(),
				page->get_PageInfo()->get_Height(),
				MakeObject<Aspose::Pdf::Devices::Resolution>(72));

	imageDevice->Process(page, System::IO::File::Create(String::Format(u"{0}_test.jpg", pageCount)));
}

//3. Create two image pages.
multi = new Gdiplus::Image(L"1_test.jpg");
page2 = new Gdiplus::Image(L"2_test.jpg");

//4. Save page (frame).
parameterValue = EncoderValueMultiFrame;
stat = multi->Save(L"Merger_pdf_tiff.tiff", &encoderClsid, &encoderParameters);
stat = multi->SaveAdd(page2, &encoderParameters);
parameterValue = EncoderValueFlush;		
stat = multi->SaveAdd(&encoderParameters);
GdiplusShutdown(gdiplusToken);