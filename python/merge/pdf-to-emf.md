```python

# create empty pdf document
output_doc = aspose.pdf.Document()

# read pdf file to Aspose Document
first_doc = aspose.pdf.Document("1.pdf")
second_doc = aspose.pdf.Document("2.pdf")

# add page from one document to another directly
for page in first_doc.pages:
	output_doc.pages.add(page)
for page in second_doc.pages:
	output_doc.pages.add(page)

# save pdf to epub
# keep the logical structure of transformed document
opt1 = aspose.pdf.EpubSaveOptions()
opt1.content_recognition_mode = aspose.pdf.EpubSaveOptions.RecognitionMode.PDF_FLOW
output_doc.save("Merger_pdf_emf.epub", opt1)

```