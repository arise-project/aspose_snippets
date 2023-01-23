```cpp

//1. create empty pdf document
outputDoc = MakeObject<Document>();

//2. eps files can be parsed and loaded as Aspose Document
firstDoc = MakeObject<Document>(u"1.eps", MakeObject<PsLoadOptions>());
secondDoc = MakeObject<Document>(u"2.eps", MakeObject<PsLoadOptions>());

//3. add page from one document to another directly
for (auto const& page : firstDoc->get_Pages())
	outputDoc->get_Pages()->CopyPage(page);
for (auto const& page : secondDoc->get_Pages())
	outputDoc->get_Pages()->CopyPage(page);

//4. save result pdf to file
outputDoc->Save(u"Merger_eps_pdf.pdf", SaveFormat::Pdf);

```