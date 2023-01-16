
// Read pdf file to Aspose Document
doc = MakeObject<Document>(u"1.pdf");

//Create PdfFileEditor object
pdfEditor = MakeObject<Aspose::Pdf::Facades::PdfFileEditor>();

//Split pdf file by half
pdfEditor->Extract(pathSource, 1, doc->get_Pages()->get_Count() / 2, u"pdf_half.pdf");
