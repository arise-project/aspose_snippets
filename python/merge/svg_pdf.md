
# create empty pdf document
output_doc = aspose.pdf.Document()

# Adust pdf page size to svg size
# SVG files can be parsed and loaded as Aspose Document
opt1 = aspose.pdf.SvgLoadOptions()
opt1.adjust_page_size = True
first_doc = aspose.pdf.Document("1.svg", opt1)
second_doc = aspose.pdf.Document("2.svg", opt1)

# add page from one document to another directly
for page in first_doc.pages:
	output_doc.pages.add(page)
for page in second_doc.pages:
	output_doc.pages.add(page)

# save result pdf to file
output_doc.save("Merger_svg_pdf.pdf", aspose.pdf.SaveFormat.PDF)
