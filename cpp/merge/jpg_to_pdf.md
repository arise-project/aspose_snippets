```cpp

//1. create empty pdf document
outputDoc = MakeObject<Document>();

//2. make list of files with images to merge
String images[] = { u"1.jpg", u"2.jpg" };

//3. add new page to pdf
// read image dimensions to pdf page rectangle
// add image to new pdf page
for (String fs : images) {
	page = outputDoc->get_Pages()->Add();
	page->AddImage(fs, new Aspose::Pdf::Rectangle(0, 0, 700, 1000));
}

//4. save result pdf to file
outputDoc->Save(u"Merger_jpg_pdf.pdf", SaveFormat::Pdf);

```