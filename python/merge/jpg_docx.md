
# create empty pdf document
doc = aspose.pdf.Document()

# add new page to pdf
# add image to new pdf page
for fs in ["1.jpg", "2.jpg"]:
	page = doc.pages.add()
	page.addImage(fs, aspose.pdf.Rectangle(0, 0, 700, 1000))

doc.save("Merger_jpg_docx.docx", aspose.pdf.SaveFormat.DOC_X)
