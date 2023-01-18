```java

//1. create empty pdf document
outputDoc = new com.aspose.pdf.Document();

//2. read pdf file to Aspose Document
firstDoc = new com.aspose.pdf.Document("1.pdf");
secondDoc = new com.aspose.pdf.Document("2.pdf");

//3. add page from one document to another directly
for (com.aspose.pdf.Page page : firstDoc.getPages())
    outputDoc.getPages().add(page);
for (com.aspose.pdf.Page page : secondDoc.getPages())
    outputDoc.getPages().add(page);

//4. save result html to file
//embed css into a page
//embed images into a page
//enhance conversion of documents with backgrounds
//use fixed layout render
opt1 = new com.aspose.pdf.HtmlSaveOptions();
opt1.setPartsEmbeddingMode(com.aspose.pdf.HtmlSaveOptions.PartsEmbeddingModes.EmbedAllIntoHtml);
opt1.setRasterImagesSavingMode(com.aspose.pdf.HtmlSaveOptions.RasterImagesSavingModes.AsEmbeddedPartsOfPngPageBackground);
opt1.setAntialiasingProcessing(com.aspose.pdf.HtmlSaveOptions.AntialiasingProcessingType.TryCorrectResultHtml);
opt1.setFixedLayout(true);
outputDoc.save("Merger_pdf_html.html", opt1);
```