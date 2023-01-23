```cpp

//1. Create blank image with calculated width and height
newImage = new System::Drawing::Bitmap(newWidth, newHeight);
canvas = System::Drawing::Graphics::FromImage(newImage);
canvas->set_InterpolationMode(System::Drawing::Drawing2D::InterpolationMode::HighQualityBicubic);
int stitchedWidth = 0;

//2. read pdf file to Aspose Document
doc = MakeObject<Document>(u"1.pdf");

//3. setup default resolution to pdf documents 72dpi
// create image device to save document as image with page dimensions and resolution
// process document page to image
for (auto const& page : doc->get_Pages()) {
	imageDevice = MakeObject<Devices::JpegDevice>(page->get_PageInfo()->get_Width(), page->get_PageInfo()->get_Height(), MakeObject<Devices::Resolution>(72));
	String outPath = String::Format(u"{0}_test.jpg", pageCount++);
	stream = System::IO::File::Create(outPath);
	imageDevice->Process(page, stream);	

	image = System::Drawing::Image::FromFile(outPath);
	canvas->DrawImage(image, stitchedWidth, 0);
	stitchedWidth += image->get_Width();
}
	
//4. save created image to disk
canvas->Save();
newImage->Save(u"Merger_pdf_jpeg.jpg", System::Drawing::Imaging::ImageFormat::get_Jpeg());
```