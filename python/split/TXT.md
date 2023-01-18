```python

# save input text to pdf to file
doc = aspose.pdf.Document("1.txt", TxtLoadOptions())
doc.Save("test.pdf", SaveFormat.PDF)
index = 1

pages = pdf_editor.SplitToPages("test.pdf")
pdf_editor = aspose.pdf.PdfFileEditor()

for ms in pages:
	page = aspose.pdf.Document(ms)
 	text_absorber = aspose.pdf.TextAbsorber()
  	page.Pages.Accept(text_absorber)
   	extracted_text = text_absorber.Text
    file = open("text_"+str(index)+".txt", "w+")
    file.write(extracted_text)
    index = index + 1
```