```cs

var pdfEditor = new PdfFileEditor();
fs = new FileStream("1.pdf", FileMode.Open, FileAccess.Read);
doc = new Document(fs);
pdfEditor.Extract(pathSource, 1, doc.Pages.Count / 2, "pdf_half.pdf");

```