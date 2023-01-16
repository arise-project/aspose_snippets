
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

//4. save result DOCX to file
//use docx format
//make document editable flow and recognize of tables
opt1 = new com.aspose.pdf.DocSaveOptions();
opt1.setFormat(com.aspose.pdf.DocSaveOptions.DocFormat.DocX);
opt1.setMode(com.aspose.pdf.DocSaveOptions.RecognitionMode.EnhancedFlow);
outputDoc.save("Merger_pdf_docx.docx", opt1);
