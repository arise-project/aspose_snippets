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

//4. save Excel document
//set Microsoft document type
opt1 = new Aspose.Pdf.ExcelSaveOptions()
{
    Format = Aspose.Pdf.ExcelSaveOptions.ExcelFormat.XMLSpreadSheet2003
};
outputDoc.Save("Merger_pdf_xls.xls",opt1);

```