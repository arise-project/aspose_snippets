```cs

//1. read pdf file to Aspose Document
firstDoc = new Aspose.Pdf.Document("1.pdf");
secondDoc = new Aspose.Pdf.Document("2.pdf");

//2. create empty pdf document
outputDoc = new Aspose.Pdf.Document();

//3. add page from one document to another directly
foreach (var page in firstDoc.Pages)
    outputDoc.Pages.Add(page);
foreach (var page in secondDoc.Pages)
    outputDoc.Pages.Add(page);

//4. save xps document
//do not save transparent text to output file
opt1 = new Aspose.Pdf.XpsSaveOptions
{
    SaveTransparentTexts = false
};
outputDoc.Save("Merger_pdf_xps.xps",op1);
```