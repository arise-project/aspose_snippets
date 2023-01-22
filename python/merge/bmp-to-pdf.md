```python
# 1. create empty pdf document
doc = aspose.pdf.Document()

# 2. add new page to pdf
# add image to new pdf page
for fs in ["1.bmp", "2.bmp"]:
    page = doc.pages.add()
    page.addImage(fs, aspose.pdf.Rectangle(0, 0, 700, 1000))

# 3. save result pdf to file
doc.save("Merger_bmp_pdf.pdf", aspose.pdf.SaveFormat.PDF)
```