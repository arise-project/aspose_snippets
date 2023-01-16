
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

//4. save result svg to file 
// scale the output document from typographic points to pixels
opt1 = MakeObject<SvgSaveOptions>();
opt1->ScaleToPixels = true;
outputDoc->Save(u"Merger_pdf_svg.svg", opt1);
