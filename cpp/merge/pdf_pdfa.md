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

//4. save document as specific pdf standard PDFA 3Y
// delete objects that impossible to convert
outputDoc->Convert(u"Merger_pdf_pdfa.pdf", PdfFormat::PDF_A_3U, ConvertErrorAction::Delete);

```