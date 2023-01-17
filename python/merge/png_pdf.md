
# create empty pdf document
doc = aspose.pdf.Document()

# add new page to pdf
# read image dimensions to pdf page rectangle
for fs in ["1.png", "2.png"]:
	page = doc.pages.add()
	# add image to new pdf page
 	page.addImage(fs, aspose.pdf.Rectangle(0, 0, 700, 1000))

# save result pdf to file
doc.save("Merger_png_pdf.pdf", aspose.pdf.SaveFormat.PDF)
