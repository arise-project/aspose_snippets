
# create empty pdf document
output_doc = aspose.pdf.Document()

# read pdf file to Aspose Document
first_doc = aspose.pdf.Document(path_source1)
second_doc = aspose.pdf.Document(path_source2)

# add page from one document to another directly
for page in first_doc.pages:
	output_doc.pages.add(page)
for page in second_doc.pages:
	output_doc.pages.add(page)

# save pdf to svg
# scale the output document from typographic points to pixels
opt1 = aspose.pdf.SvgSaveOptions()
opt1.scale_to_pixels = True
output_doc.save("Merger_pdf_svg.svg", opt1)
