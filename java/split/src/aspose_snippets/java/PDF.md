
//1. Read the source PDF file
var doc = new com.aspose.pdf.Document("1.pdf");
//2. Instantiate PdfFileEditor object
var pdfEditor = new com.aspose.pdf.facades.PdfFileEditor();

//3. Split the PDF file into two halves    
pdfEditor.extract(pathSource, 1, doc.getPages().size() / 2, "pdf_half.pdf");
