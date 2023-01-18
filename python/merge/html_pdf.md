```python

# create empty pdf document
output_doc = aspose.pdf.Document()

# html files can be parsed and loaded as Aspose Document
# set html encoding
# render all html to single large pdf page
opt1 = aspose.pdf.HtmlLoadOptions()
opt1.input_encoding = "UTF-8",
opt1.is_render_to_single_page = True
first_doc = aspose.pdf.Document("1.html", opt1)
second_doc = aspose.pdf.Document("2.html", opt1)
    
# add page from one document to another directly
for page in first_doc.pages:
	output_doc.pages.add(page)
for page in second_doc.pages:
	output_doc.pages.add(page)

# save result pdf to file
output_doc.save("Merger_html_pdf.pdf", aspose.pdf.SaveFormat.PDF)

```