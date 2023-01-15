
//1. read pdf file to Aspose Document
com.aspose.pdf.Document firstDoc = new com.aspose.pdf.Document("1.pdf");
com.aspose.pdf.Document secondDoc = new com.aspose.pdf.Document("2.pdf");

//2. create empty pdf document
com.aspose.pdf.Document outputDoc = new com.aspose.pdf.Document();

//3. set less memory usage with unload instead of fast performance
outputDoc.setEnableObjectUnload(true);

//4. add page from one document to another directly
for (com.aspose.pdf.Page page : firstDoc.getPages())
    outputDoc.getPages().add(page);
for (com.aspose.pdf.Page page : secondDoc.getPages())
    outputDoc.getPages().add(page);

//5. save xps document
//do not save transparent text to output file
com.aspose.pdf.XpsSaveOptions opt1 = new com.aspose.pdf.XpsSaveOptions();
opt1.setSaveTransparentTexts(false);
outputDoc.save("Merger_pdf_xps.xps", opt1);
