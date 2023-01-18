```java

//1. create empty pdf document
outputDoc = new com.aspose.pdf.Document();

//2. epub files can be parsed and loaded as Aspose Document
//use algorithm to prevent content to be truncated
//usage of margins area during conversion
opt1 = new com.aspose.pdf.EpubLoadOptions();
opt1.setPageSizeAdjustmentMode(com.aspose.pdf.LoadOptions.PageSizeAdjustmentModes.EnlargeRequiredViewportWidthAndDoConversionAgain);
opt1.setMarginsAreaUsageMode(com.aspose.pdf.LoadOptions.MarginsAreaUsageModes.PutContentOnMarginAreaIfNecessary);
firstDoc = new com.aspose.pdf.Document("1.epub", opt1);
secondDoc = new com.aspose.pdf.Document("2.epub", opt1);

//3. add page from one document to another directly
for (com.aspose.pdf.Page page : firstDoc.getPages())
    outputDoc.getPages().add(page);
for (com.aspose.pdf.Page page : secondDoc.getPages())
    outputDoc.getPages().add(page);

//4. save result pdf to file
outputDoc.save("Merger_epub_pdf.pdf", com.aspose.pdf.SaveFormat.Pdf);

```