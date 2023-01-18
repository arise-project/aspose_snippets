```python

output_doc = aspose.pdf.Document()

# read pdf file to Aspose Document
first_doc = aspose.pdf.Document("1.pdf")
second_doc = aspose.pdf.Document("2.pdf")

# add page from one document to another directly        
for page in first_doc.pages:
	output_doc.pages.add(page)
for page in second_doc.pages:
	output_doc.pages.add(page)

# save pdf to Microsoft PowerPoint
# save all content on page as single image
opt1 = PptxSaveOptions()
opt1.slides_as_images = True
output_doc.save("Merger_pdf_pptx.pptx", opt1)

```