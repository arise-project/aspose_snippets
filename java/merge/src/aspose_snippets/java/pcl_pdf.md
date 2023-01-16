
//1. create empty pdf document
outputDoc = new com.aspose.pdf.Document();

//2. suspend not critical errors
//pcl files can be parsed and loaded as Aspose Document
opt1 = new com.aspose.pdf.PclLoadOptions();
opt1.setSupressErrors(true);
firstDoc = new com.aspose.pdf.Document("1.pcl", opt1);
secondDoc = new com.aspose.pdf.Document("2.pcl", opt1);

//3. add page from one document to another directly
for (com.aspose.pdf.Page page : firstDoc.getPages())
    outputDoc.getPages().add(page);
for (com.aspose.pdf.Page page : secondDoc.getPages())
    outputDoc.getPages().add(page);

//4. save result pdf to file
outputDoc.save("Merger_pcl_pdf.pdf", com.aspose.pdf.SaveFormat.Pdf);