```python

# create empty pdf document
output_doc = aspose.pdf.Document()

# PostScript files can be parsed and loaded as Aspose Document
first_doc = aspose.pdf.Document("1.ps", aspose.pdf.PsLoadOptions)
second_doc = aspose.pdf.Document("2.ps", aspose.pdf.PsLoadOptions)

# add page from one document to another directly        
for page in first_doc.pages:
	output_doc.pages.add(page)
for page in second_doc.pages:
	output_doc.pages.add(page)

# save result pdf to file
output_doc.save("Merger_ps_pdf.pdf", aspose.pdf.SaveFormat.PDF)

```