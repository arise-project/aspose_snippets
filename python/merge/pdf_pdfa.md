```python

# read pdf file to Aspose Document
first_doc = aspose.pdf.Document("1.pdf")
second_doc = aspose.pdf.Document("2.pdf")

# create empty pdf document
output_doc = aspose.pdf.Document()

# add page from one document to another directly
for page in first_doc.pages:
	output_doc.pages.add(page)
for page in second_doc.pages:
	output_doc.pages.add(page)

# save document as specific pdf standard PDFA 3Y
output_doc.convert("Merger_pdf_pdfa.pdf", aspose.pdf.PdfFormat.PDF_A_3U)

```