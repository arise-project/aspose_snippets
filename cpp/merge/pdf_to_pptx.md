```cpp

//1. create empty pdf document
auto outputDoc = MakeObject<Document>();

//2. read pdf file to Aspose Document
firstDoc = MakeObject<Document>(u"1.pdf");
auto secondDoc = MakeObject<Document>(u"2.pdf");

//3. add page from one document to another directly
for (auto const& page : firstDoc->get_Pages())
	outputDoc->get_Pages()->CopyPage(page);
for (auto const& page : secondDoc->get_Pages())
	outputDoc->get_Pages()->CopyPage(page);

//4. save result pptx to file 
// save all content on page as single image
auto opt1 = MakeObject<PptxSaveOptions>();
opt1->set_SlidesAsImages(true);
outputDoc->Save(u"Merger_pdf_pptx.pptx", opt1);

```