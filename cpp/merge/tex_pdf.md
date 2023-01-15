
//1. create empty pdf document
auto outputDoc = MakeObject<Document>();

//2. TeX files can be parsed and loaded as Aspose Document
// Cancels ligatures in all fonts
// Rasterize scientific formulas to images
// Print parsing steps details to console output
auto opt1 = MakeObject<TeXLoadOptions>();
opt1->set_NoLigatures(false);
opt1->set_RasterizeFormulas(true);
opt1->set_ShowTerminalOutput(true);
System::SharedPtr<Document> firstDoc = MakeObject<Document>(u"1.tex", opt1);
auto secondDoc = MakeObject<Document>(u"2.tex", opt1);

//3. add page from one document to another directly
for (auto const& page : firstDoc->get_Pages())
	outputDoc->get_Pages()->CopyPage(page);
for (auto const& page : secondDoc->get_Pages())
	outputDoc->get_Pages()->CopyPage(page);

//4. save result pdf to file
outputDoc->Save(u"Merger_tex_pdf.pdf", SaveFormat::Pdf);
