```cs

//create empty pdf document
outputDoc = new Aspose.Pdf.Document();

//read pdf file to Aspose Document
firstDoc = new Aspose.Pdf.Document("1.pdf");
secondDoc = new Aspose.Pdf.Document("2.pdf");

//add page from one document to another directly
foreach (var page in firstDoc.Pages)
    outputDoc.Pages.Add(page);
foreach (var page in secondDoc.Pages)
    outputDoc.Pages.Add(page);

//save pdf to Microsoft Word docx format
//use docx format
//make document editable flow and recognize of tables
opt1 = new Aspose.Pdf.DocSaveOptions
{
    Format = Aspose.Pdf.DocSaveOptions.DocFormat.DocX,
    Mode = Aspose.Pdf.DocSaveOptions.RecognitionMode.EnhancedFlow
};

outputDoc.Save("Merger_pdf_docx.docx", opt1);

```