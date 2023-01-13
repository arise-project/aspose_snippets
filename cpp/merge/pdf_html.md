
//1. create empty pdf document
auto outputDoc = MakeObject<Document>();

//2. read pdf file to Aspose Document
System::SharedPtr<Document> firstDoc = MakeObject<Document>(u"1.pdf");
auto secondDoc = MakeObject<Document>(u"2.pdf");

//3. add page from one document to another directly
for (auto const& page : firstDoc->get_Pages())
	outputDoc->get_Pages()->CopyPage(page);
for (auto const& page : secondDoc->get_Pages())
	outputDoc->get_Pages()->CopyPage(page);

//4. save result html to file
// embed css into a page
// embed images into a page
// enhance conversion of documents with backgrounds
// use fixed layout render
auto opt1 = MakeObject<HtmlSaveOptions>();
opt1->PartsEmbeddingMode = Aspose::Pdf::HtmlSaveOptions::PartsEmbeddingModes::EmbedAllIntoHtml;
opt1->RasterImagesSavingMode = Aspose::Pdf::HtmlSaveOptions::RasterImagesSavingModes::AsEmbeddedPartsOfPngPageBackground;
opt1->AntialiasingProcessing = Aspose::Pdf::HtmlSaveOptions::AntialiasingProcessingType::TryCorrectResultHtml;
opt1->set_FixedLayout(true);
outputDoc->Save(u"Merger_pdf_html.html", opt1);
