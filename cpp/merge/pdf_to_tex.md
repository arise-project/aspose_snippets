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

//4. save result tex to file 
// save parsed artifacts, for example images to a directory
opt1 = MakeObject<TeXSaveOptions>();
opt1->set_OutDirectoryPath(u"./test");
outputDoc->Save(u"Merger_pdf_tex.tex", opt1);

```