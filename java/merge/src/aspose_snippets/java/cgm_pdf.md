
//1. create empty pdf document
com.aspose.pdf.Document outputDoc = new com.aspose.pdf.Document();

//2. cgm files can be parsed and loaded as Aspose Document
com.aspose.pdf.Document firstDoc = new com.aspose.pdf.Document("1.cgm", new com.aspose.pdf.CgmLoadOptions());
com.aspose.pdf.Document secondDoc = new com.aspose.pdf.Document("2.cgm", new com.aspose.pdf.CgmLoadOptions());

//3. add page from one document to another directly
for (com.aspose.pdf.Page page : firstDoc.getPages())
    outputDoc.getPages().add(page);
for (com.aspose.pdf.Page page : secondDoc.getPages())
    outputDoc.getPages().add(page);

//4. save result pdf to file
outputDoc.save("Merger_cgm_pdf.pdf", com.aspose.pdf.SaveFormat.Pdf);
