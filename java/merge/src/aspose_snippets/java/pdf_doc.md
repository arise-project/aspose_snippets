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

//4. save result DOC to file
//use doc format
//This mode is fast and good for maximally preserving original look
opt1 = new com.aspose.pdf.DocSaveOptions();
opt1.setFormat(com.aspose.pdf.DocSaveOptions.DocFormat.Doc);
opt1.setMode(com.aspose.pdf.DocSaveOptions.RecognitionMode.Textbox);
outputDoc.save("Merger_pdf_doc.doc", opt1);

```