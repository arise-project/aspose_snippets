
doc = aspose.pdf.Document("test.pdf");

# save input html to pdf to file
doc = aspose.pdf.Document("1.html", HtmlLoadOptions);
doc.Save("test.pdf", SaveFormat.PDF);

# slit first page
pdf_editor = aspose.pdf.PdfFileEditor();
pdf_editor.SplitFromFirst("test.pdf", 1, "test.pdf");
doc.Save("html_first.html", SaveFormat.HTML);