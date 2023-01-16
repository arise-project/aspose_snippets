
//1. create empty pdf document
outputDoc = new com.aspose.pdf.Document();

//2. read pdf file to Aspose Document
firstDoc = new com.aspose.pdf.Document(pathSource1);
secondDoc = new com.aspose.pdf.Document(pathSource2);

//3. add page from one document to another directly
for (com.aspose.pdf.Page page : firstDoc.getPages())
    outputDoc.getPages().add(page);
for (com.aspose.pdf.Page page : secondDoc.getPages())
    outputDoc.getPages().add(page);

//4. save result SVG to file
//scale the output document from typographic points to pixels
opt1 = new com.aspose.pdf.SvgSaveOptions();
opt1.setScaleToPixels(true);
outputDoc.save("Merger_pdf_svg.svg", opt1);
