```cs

//1. create empty pdf document
outputDoc = new Aspose.Pdf.Document();

//2. cgm files can be parsed and loaded as Aspose Document
firstDoc = new Aspose.Pdf.Document("1.cgm", new Aspose.Pdf.CgmLoadOptions());
secondDoc = new Aspose.Pdf.Document("2.cgm", new Aspose.Pdf.CgmLoadOptions());

//3. add page from one document to another directly
foreach (var page in firstDoc.Pages)
    outputDoc.Pages.Add(page);
foreach (var page in secondDoc.Pages)
    outputDoc.Pages.Add(page);

//4. save result pdf to file
outputDoc.Save("Merger_cgm_pdf.pdf", Aspose.Pdf.SaveFormat.Pdf);

```