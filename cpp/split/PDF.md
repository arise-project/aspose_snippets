
// Read pdf file to Aspose Document
auto doc = MakeObject<Document>(u"1.pdf");

//Create PdfFileEditor object
auto pdfEditor = MakeObject<Aspose::Pdf::Facades::PdfFileEditor>();

//Calculate half of pages
int beg = 1, end = 1;
end = doc->get_Pages()->get_Count();
if(end > 1) end /= 2;

//Split pdf file by half
pdfEditor->Extract(pathSource, beg, end, u"pdf_half.pdf");
