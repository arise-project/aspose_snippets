```cpp

//1. create empty pdf document
outputDoc = MakeObject<Document>();

//2. read pdf file to Aspose Document
firstDoc = MakeObject<Document>(u"1.pdf");
secondDoc = MakeObject<Document>(u"2.pdf");

//3. add page from one document to another directly
for (auto const& page : firstDoc->get_Pages())
		outputDoc->get_Pages()->CopyPage(page);
for (auto const& page : secondDoc->get_Pages())
	outputDoc->get_Pages()->CopyPage(page);

//4. save Excel document
// set Microsoft document type
opt1 = MakeObject<ExcelSaveOptions>();
opt1->set_Format(Aspose::Pdf::ExcelSaveOptions::ExcelFormat::XMLSpreadSheet2003);
outputDoc->Save(u"Merger_pdf_xls.xls", opt1);
```