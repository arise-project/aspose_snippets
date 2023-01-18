```cs

//1. create empty pdf document
outputDoc = new Aspose.Pdf.Document();

//2. xps files can be parsed and loaded as Aspose Document
firstDoc = new Aspose.Pdf.Document("1.xps", new Aspose.Pdf.XpsLoadOptions());
secondDoc = new Aspose.Pdf.Document("2.xps", new Aspose.Pdf.XpsLoadOptions());

//3. add page from one document to another directly
foreach (var page in firstDoc.Pages)
    outputDoc.Pages.Add(page);

foreach (var page in secondDoc.Pages)
    outputDoc.Pages.Add(page);

//4. save result pdf to file
outputDoc.Save("Merger_xps_pdf.pdf", Aspose.Pdf.SaveFormat.Pdf);
```