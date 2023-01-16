
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

//4. save pdf to epub
//keep the logical structure of transformed document 
opt1 = new Aspose.Pdf.EpubSaveOptions
{
    ContentRecognitionMode = Aspose.Pdf.EpubSaveOptions.RecognitionMode.PdfFlow
};
outputDoc.Save("Merger_pdf_epub.epub",opt1);