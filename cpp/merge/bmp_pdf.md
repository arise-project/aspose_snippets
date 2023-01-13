
//1. create empty pdf document
System::SharedPtr<Document> doc = MakeObject<Document>();

//2. make list of files with images to merge
String images[] = { u"1.bmp", u"2.bmp" };

//3. add new page to pdf
// read image dimensions to pdf page rectangle
// add image to new pdf page
for (String fs : images) {
	auto page = doc->get_Pages()->Add();
	page->AddImage(fs, new Aspose::Pdf::Rectangle(0, 0, 700, 1000));
}

//4. save result pdf to file
doc->Save(u"Merger_bmp_pdf.pdf", SaveFormat::Pdf);
