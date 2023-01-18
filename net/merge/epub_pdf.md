```cs

//1. epub files can be parsed and loaded as Aspose Document
//use algorithm to prevent content to be truncated
//usage of margins area during conversion 
opt1 = new Aspose.Pdf.EpubLoadOptions
                {
                    
                    PageSizeAdjustmentMode = Aspose.Pdf.LoadOptions.PageSizeAdjustmentModes.EnlargeRequiredViewportWidthAndDoConversionAgain,
                    MarginsAreaUsageMode = Aspose.Pdf.LoadOptions.MarginsAreaUsageModes.PutContentOnMarginAreaIfNecessary
                };
firstDoc = new Aspose.Pdf.Document("1.epub", opt1);
secondDoc = new Aspose.Pdf.Document("2.epub", opt1);

//2. create empty pdf document
outputDoc = new Aspose.Pdf.Document();

//3. add page from one document to another directly
foreach (var page in firstDoc.Pages)
    outputDoc.Pages.Add(page);
foreach (var page in secondDoc.Pages)
    outputDoc.Pages.Add(page);

//4. save result pdf to file
outputDoc.Save("Merger_epub_pdf.pdf", Aspose.Pdf.SaveFormat.Pdf);

```