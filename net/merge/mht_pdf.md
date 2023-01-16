
//1. create empty pdf document
var outputDoc = new Aspose.Pdf.Document();

//2. mht files can be parsed and loaded as Aspose Document
firstDoc = new Aspose.Pdf.Document("1.mht", new Aspose.Pdf.MhtLoadOptions());
secondDoc = new Aspose.Pdf.Document("2.mht",  new Aspose.Pdf.MhtLoadOptions());

//3. add page from one document to another directly
foreach (var page in firstDoc.Pages)
    outputDoc.Pages.Add(page);
foreach (var page in secondDoc.Pages)
    outputDoc.Pages.Add(page);

//4. save result pdf to file
outputDoc.Save("Merger_mht_pdf.pdf", Aspose.Pdf.SaveFormat.Pdf);
