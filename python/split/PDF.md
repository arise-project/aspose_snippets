```python

doc = aspose.pdf.Document("1.pdf")

pdf_editor = aspose.pdf.PdfFileEditor()
pdf_editor.Extract(path_source, 1, doc.Pages.Count / 2, "pdf_half.pdf")

```