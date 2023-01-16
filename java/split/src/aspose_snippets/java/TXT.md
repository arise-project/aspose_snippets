
//1. Read the source TXT file to Aspose Document
doc = new com.aspose.pdf.Document(pathSource, new com.aspose.pdf.TxtLoadOptions());

//2. Instantiate PdfFileEditor object
pdfEditor = new com.aspose.pdf.facades.PdfFileEditor();


//3. save input text to pdf to file
doc.save("test.pdf", com.aspose.pdf.SaveFormat.Pdf);

//4. split pdf to pages
ByteArrayInputStream[] pages = pdfEditor.splitToPages("test.pdf");
int index = 1;

//5. save each page to text file
//extract text from page
for(var ms : pages) {
    page = new com.aspose.pdf.Document(ms);
    textAbsorber = new com.aspose.pdf.TextAbsorber();
    page.getPages().accept(textAbsorber);
    String extractedText = textAbsorber.getText();
    Files.writeString(Path.of("text_"+ Integer.toString(index)+".txt"), extractedText);
    index++;
}
