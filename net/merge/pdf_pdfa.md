```cs

//1. create empty pdf document
outputDoc = new Aspose.Pdf.Document();

//2. read pdf file to Aspose Document
firstDoc = new Aspose.Pdf.Document("1.pdf");
secondDoc = new Aspose.Pdf.Document("2.pdf");

//3. add page from one document to another directly
foreach (var page in firstDoc.Pages)
    outputDoc.Pages.Add(page);
foreach (var page in secondDoc.Pages)
    outputDoc.Pages.Add(page);

//4. save document as specific pdf standard PDFA 3Y
//delete objects that impossible to convert
outputDoc.Convert("Merger_pdf_pdfa.pdf", Aspose.Pdf.PdfFormat.PDF_A_3U, Aspose.Pdf.ConvertErrorAction.Delete);

```