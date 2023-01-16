
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

//4. create text absorber for extract text
textAbsorber = MakeObject<Aspose::Pdf::Text::TextAbsorber>();
outputDoc->get_Pages()->Accept(textAbsorber);
extractedText = textAbsorber->get_Text();

//5. save result text to file 
fstream file;
file.open("Merger_pdf_text.txt", ios::out);
file << extractedText;
file.close();
