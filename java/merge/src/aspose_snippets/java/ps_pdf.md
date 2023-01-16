
//1. create empty pdf document
outputDoc = new com.aspose.pdf.Document();

//2. PostScript files can be parsed and loaded as Aspose Document
firstDoc = new com.aspose.pdf.Document("1.ps", new com.aspose.pdf.PsLoadOptions());
secondDoc = new com.aspose.pdf.Document("2.ps", new com.aspose.pdf.PsLoadOptions());

//3. add page from one document to another directly
for (com.aspose.pdf.Page page : firstDoc.getPages())
    outputDoc.getPages().add(page);
for (com.aspose.pdf.Page page : secondDoc.getPages())
    outputDoc.getPages().add(page);

//4. save result pdf to file
outputDoc.save("Merger_ps_pdf.pdf", com.aspose.pdf.SaveFormat.Pdf);
