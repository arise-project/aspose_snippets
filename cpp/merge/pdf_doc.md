
//1. create empty pdf document
auto outputDoc = MakeObject<Document>();

//2. read pdf file to Aspose Document
System::SharedPtr<Document> firstDoc = MakeObject<Document>(u"1.pdf");
auto secondDoc = MakeObject<Document>(u"2.pdf");
	
//3. add page from one document to another directly
for (auto const& page : firstDoc->get_Pages())
	outputDoc->get_Pages()->CopyPage(page);
for (auto const& page : secondDoc->get_Pages())
	outputDoc->get_Pages()->CopyPage(page);

//4. save result doc to file
// use doc format
// This mode is fast and good for maximally preserving original look
auto opt1 = MakeObject<DocSaveOptions>();
opt1->set_Format(Aspose::Pdf::DocSaveOptions::DocFormat::Doc);
opt1->set_Mode(Aspose::Pdf::DocSaveOptions::RecognitionMode::Textbox);
outputDoc->Save(u"Merger_pdf_doc.doc", opt1);
