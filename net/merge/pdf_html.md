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


//4. save pdf to html page
//embed css into a page
//embed images into a page
//enhance conversion of documents with backgrounds
//use fixed layout render
var opt1 = new Aspose.Pdf.HtmlSaveOptions
{
    PartsEmbeddingMode = Aspose.Pdf.HtmlSaveOptions.PartsEmbeddingModes.EmbedAllIntoHtml,
    RasterImagesSavingMode = Aspose.Pdf.HtmlSaveOptions.RasterImagesSavingModes.AsEmbeddedPartsOfPngPageBackground,
    AntialiasingProcessing = Aspose.Pdf.HtmlSaveOptions.AntialiasingProcessingType.TryCorrectResultHtml,
    FixedLayout = true
};
outputDoc.Save("Merger_pdf_html.html",opt1);

```