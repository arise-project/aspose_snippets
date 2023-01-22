```python

# create empty pdf document
doc = aspose.pdf.Document()

# add new page to pdf
# add image to new pdf page
for fs in ["1.jpg", "2.jpg"]:
	page = doc.pages.add()
	page.addImage(fs, aspose.pdf.Rectangle(0, 0, 700, 1000))

# save result pdf to file
doc.save("Merger_jpg_pdf.pdf", aspose.pdf.SaveFormat.PDF)

```