
//1. create empty pdf document
outputDoc = MakeObject<Document>();

//2. pcl files can be parsed and loaded as Aspose Document
// suspend not critical errors
opt1 = MakeObject<PclLoadOptions>();
opt1->SupressErrors = true;
firstDoc = MakeObject<Document>(u"1.pcl", opt1);
secondDoc = MakeObject<Document>(u"2.pcl", opt1);

//3. add page from one document to another directly
for (auto const& page : firstDoc->get_Pages())
	outputDoc->get_Pages()->CopyPage(page);
for (auto const& page : secondDoc->get_Pages())
	outputDoc->get_Pages()->CopyPage(page);

//4. save result pdf to file
outputDoc->Save(u"Merger_pcl_pdf.pdf", SaveFormat::Pdf);
