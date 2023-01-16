
//save input html to pdf to file
doc = new Document("1.html", new HtmlLoadOptions());
doc.Save("test.pdf", SaveFormat.Pdf);

var pdfEditor = new PdfFileEditor();
pdfEditor.SplitFromFirst("test.pdf", 1, "test.pdf");
doc = new Document("test.pdf");
doc.Save("html_first.html", SaveFormat.Html);
