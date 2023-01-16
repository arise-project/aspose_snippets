
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

//4. save document as specific pdf standard PDFA 3Y
//delete objects that impossible to convert
outputDoc.convert(
        "Merger_pdf_pdfa.pdf",
        com.aspose.pdf.PdfFormat.PDF_A_3U,
        com.aspose.pdf.ConvertErrorAction.Delete);
