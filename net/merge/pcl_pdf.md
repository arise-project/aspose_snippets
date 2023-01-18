```cs


//1. create empty pdf document
outputDoc = new Aspose.Pdf.Document();

//2. pcl files can be parsed and loaded as Aspose Document
//suspend not critical errors
firstDoc = new Aspose.Pdf.Document("1.pcl", new Aspose.Pdf.PclLoadOptions() { SupressErrors = true });
secondDoc = new Aspose.Pdf.Document("2.pcl", new Aspose.Pdf.PclLoadOptions()  { SupressErrors = true });

//3. add page from one document to another directly
foreach (var page in firstDoc.Pages)
    outputDoc.Pages.Add(page);
foreach (var page in secondDoc.Pages)
    outputDoc.Pages.Add(page);

//4. save result pdf to file
outputDoc.Save("Merger_pcl_pdf.pdf", Aspose.Pdf.SaveFormat.Pdf);

```