
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

# save xps document
# do not save transparent text to output file
opt1 = aspose.pdf.XpsSaveOptions()
opt1.save_transparent_texts = False
output_doc.save("Merger_pdf_xps.xps", opt1)
