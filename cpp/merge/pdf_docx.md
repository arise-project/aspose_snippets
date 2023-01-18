```cpp

//1. create empty pdf document
outputDoc = MakeObject<Document>();

//2. read pdf file to Aspose Document
System::SharedPtr<Document> firstDoc = MakeObject<Document>(u"1.pdf");
secondDoc = MakeObject<Document>(u"2.pdf");

//3. add page from one document to another directly
for (auto const& page : firstDoc->get_Pages())
	outputDoc->get_Pages()->CopyPage(page);

for (auto const& page : secondDoc->get_Pages())
	outputDoc->get_Pages()->CopyPage(page);

//4. save result docx to file
// use docx format
// make document editable flow and recognize of tables
opt1 = MakeObject<DocSaveOptions>();
opt1->set_Format(Aspose::Pdf::DocSaveOptions::DocFormat::DocX);
opt1->set_Mode(Aspose::Pdf::DocSaveOptions::RecognitionMode::EnhancedFlow);
outputDoc->Save(u"Merger_pdf_docx.docx", opt1);

```