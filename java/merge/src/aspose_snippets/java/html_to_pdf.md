```java

//1. create empty pdf document
outputDoc = new com.aspose.pdf.Document();

//2. html files can be parsed and loaded as Aspose Document
//set html encoding
//render all html to single large pdf page
com.aspose.pdf.HtmlLoadOptions opt1 = new com.aspose.pdf.HtmlLoadOptions();
opt1.setInputEncoding("UTF-8");
opt1.setRenderToSinglePage(true);
firstDoc = new com.aspose.pdf.Document("1.html", opt1);
secondDoc = new com.aspose.pdf.Document("2.html", opt1);

//3. add page from one document to another directly
for (com.aspose.pdf.Page page : firstDoc.getPages())
    outputDoc.getPages().add(page);
for (com.aspose.pdf.Page page : secondDoc.getPages())
    outputDoc.getPages().add(page);

//4. save result pdf to file
outputDoc.save("Merger_html_pdf.pdf", com.aspose.pdf.SaveFormat.Pdf);

```