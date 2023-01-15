
//1. create empty pdf document
auto outputDoc = MakeObject<Document>();

//2. SVG files can be parsed and loaded as Aspose Document
// Adust pdf page size to svg size
auto opt1 = MakeObject<SvgLoadOptions>();
opt1->set_AdjustPageSize(true);
System::SharedPtr<Document> firstDoc = MakeObject<Document>(u"1.svg", opt1);
auto secondDoc = MakeObject<Document>(u"1.svg", opt1);

//3. add page from one document to another directly
for (auto const& page : firstDoc->get_Pages())
	outputDoc->get_Pages()->CopyPage(page);
for (auto const& page : secondDoc->get_Pages())
	outputDoc->get_Pages()->CopyPage(page);

//4. save result pdf to file
outputDoc->Save(u"Merger_svg_pdf.pdf", SaveFormat::Pdf);
