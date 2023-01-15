
//1. Create output document
com.aspose.pdf.Document outputDoc = new com.aspose.pdf.Document();

//2. Read TeX files to Aspose Document
//Cancels ligatures in all fonts
//Rasterize scientific formulas to images
//Print parsing steps details to console output
com.aspose.pdf.TeXLoadOptions opt1 = new com.aspose.pdf.TeXLoadOptions();
opt1.setNoLigatures(false);
opt1.setRasterizeFormulas(true);
opt1.setShowTerminalOutput(true);
com.aspose.pdf.Document firstDoc = new com.aspose.pdf.Document("1.tex", opt1);
com.aspose.pdf.Document secondDoc = new com.aspose.pdf.Document("2.tex", opt1);

//3. add page from one document to another directly
for (com.aspose.pdf.Page page : firstDoc.getPages())
    outputDoc.getPages().add(page);
for (com.aspose.pdf.Page page : secondDoc.getPages())
    outputDoc.getPages().add(page);

//4. save result pdf to file
outputDoc.save("Merger_tex_pdf.pdf", com.aspose.pdf.SaveFormat.Pdf);
