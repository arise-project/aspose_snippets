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

# save Excel document
# set Microsoft document type
opt1 = aspose.pdf.ExcelSaveOptions()
opt1.Format = aspose.pdf.ExcelSaveOptions.ExcelFormat.XMLSpreadSheet2003
output_doc.save("Merger_pdf_xls.xls", opt1)

```