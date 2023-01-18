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

# save pdf to Microsoft Word docx format
# use docx format
# make document editable flow and recognize of tables
opt1 = DocSaveOptions
opt1.Format = DocSaveOptions.DocFormat.DOC_X,
opt1.Mode = DocSaveOptions.RecognitionMode.ENHANCED_FLOW
output_doc.save("Merger_pdf_docx.docx", opt1)

```