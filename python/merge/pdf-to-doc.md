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

# save pdf to Microsoft Word doc format
# use doc format
# This mode is fast and good for maximally preserving original look
opt1 = DocSaveOptions
opt1.Format = DocSaveOptions.DocFormat.Doc,
opt1.Mode = aspose.pdf.DocSaveOptions.RecognitionMode.Textbox
output_doc.save("Merger_pdf_doc.doc", opt1)

```