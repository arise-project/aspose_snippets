
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

//4. save result TEX to file
//save parsed artifacts, for example images to a directory
opt1 = new com.aspose.pdf.TeXSaveOptions();
opt1.setOutDirectoryPath("./test");
outputDoc.save("Merger_pdf_tex.tex", opt1);
