
//1. create empty pdf document
com.aspose.pdf.Document outputDoc = new com.aspose.pdf.Document();

//2. eps files can be parsed and loaded as Aspose Document
com.aspose.pdf.Document firstDoc = new com.aspose.pdf.Document("1.eps", new com.aspose.pdf.PsLoadOptions());
com.aspose.pdf.Document secondDoc = new com.aspose.pdf.Document("2.eps", new com.aspose.pdf.PsLoadOptions());

//3. add page from one document to another directly
for (com.aspose.pdf.Page page : firstDoc.getPages())
    outputDoc.getPages().add(page);
for (com.aspose.pdf.Page page : secondDoc.getPages())
    outputDoc.getPages().add(page);

//4. save result pdf to file
outputDoc.save("Merger_eps_pdf.pdf", SaveFormat.Pdf);
