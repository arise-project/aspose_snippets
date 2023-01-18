```cs

//1. create empty pdf document
outputDoc = new Aspose.Pdf.Document();

//2. eps files can be parsed and loaded as Aspose Document
firstDoc = new Aspose.Pdf.Document("1.eps", new Aspose.Pdf.PsLoadOptions());
secondDoc = new Aspose.Pdf.Document("2.eps",  new Aspose.Pdf.PsLoadOptions());

//3. add page from one document to another directly
foreach (var page in firstDoc.Pages)
    outputDoc.Pages.Add(page);
foreach (var page in secondDoc.Pages)
    outputDoc.Pages.Add(page);

//4. save result pdf to file
outputDoc.Save("Merger_eps_pdf.pdf", Aspose.Pdf.SaveFormat.Pdf);

```