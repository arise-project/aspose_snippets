
//1. create empty pdf document
auto outputDoc = MakeObject<Document>();

//2. read pdf file to Aspose Document
System::SharedPtr<Document> firstDoc = MakeObject<Document>(u"1.pdf");
auto secondDoc = MakeObject<Document>(u"2.pdf");

// add page from one document to another directly
for (auto const& page : firstDoc->get_Pages())
	outputDoc->get_Pages()->CopyPage(page);
for (auto const& page : secondDoc->get_Pages())
	outputDoc->get_Pages()->CopyPage(page);

//4. save xps document
// do not save transparent text to output file
auto opt1 = MakeObject<XpsSaveOptions>();
opt1->set_SaveTransparentTexts(false);
outputDoc->Save(u"Merger_pdf_xps.xps", opt1);
