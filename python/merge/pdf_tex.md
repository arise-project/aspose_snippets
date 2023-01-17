
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

# save pdf to TeX document
# save parsed artifacts, for example images to a directory
opt1 = aspose.pdf.TeXSaveOptions()
opt1.out_directory_path = "./test"
output_doc.save("Merger_pdf_tex.tex", opt1)
