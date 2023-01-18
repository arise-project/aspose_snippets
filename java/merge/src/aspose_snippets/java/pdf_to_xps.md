```java

//1. read pdf file to Aspose Document
firstDoc = new com.aspose.pdf.Document("1.pdf");
secondDoc = new com.aspose.pdf.Document("2.pdf");

//2. create empty pdf document
outputDoc = new com.aspose.pdf.Document();

//3. add page from one document to another directly
for (com.aspose.pdf.Page page : firstDoc.getPages())
    outputDoc.getPages().add(page);
for (com.aspose.pdf.Page page : secondDoc.getPages())
    outputDoc.getPages().add(page);

//4. save xps document
//do not save transparent text to output file
opt1 = new com.aspose.pdf.XpsSaveOptions();
opt1.setSaveTransparentTexts(false);
outputDoc.save("Merger_pdf_xps.xps", opt1);

```