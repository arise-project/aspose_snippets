```java

//1. Read the source HTML file
doc = new com.aspose.pdf.Document(pathSource, new com.aspose.pdf.HtmlLoadOptions());

//2. save input html to pdf to file
doc.save("test.pdf", com.aspose.pdf.SaveFormat.Pdf);

//3. Instantiate PdfFileEditor object  
pdfEditor = new com.aspose.pdf.facades.PdfFileEditor();

//4. slit first page
pdfEditor.splitFromFirst("test.pdf", 1, "test.pdf");

//5. Convert first pdf page to html
outputDoc = new com.aspose.pdf.Document("test.pdf");
outputDoc.save("first_page.html", com.aspose.pdf.SaveFormat.Html);

```