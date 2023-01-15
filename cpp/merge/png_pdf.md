
//1. create empty pdf document
System::SharedPtr<Document> outputDoc = MakeObject<Document>();

//2. add new page to pdf
// add image to new pdf page
// make list of files with images to merge
String images[] = { u"1.png", u"2.png" };
for (String fs : images)
{
	auto page = outputDoc->get_Pages()->Add();
	page->AddImage(fs, new Aspose::Pdf::Rectangle(0, 0, 700, 1000));
}

//3. save result pdf to file
outputDoc->Save(u"Merger_png_pdf.pdf", SaveFormat::Pdf);
