```python

output_doc = aspose.pdf.Document()

# TeX files can be parsed and loaded as Aspose Document
# Cancels ligatures in all fonts
# Rasterize scientific formulas to images
# Print parsing steps details to console output
opt1 = aspose.pdf.TeXLoadOptions()
opt1.no_ligatures = False
opt1.rasterize_formulas = True
opt1.show_terminal_output = True
first_doc = aspose.pdf.Document("1.tex", opt1)
second_doc = aspose.pdf.Document("2.tex", opt1)

# add page from one document to another directly
for page in first_doc.pages:
	output_doc.pages.add(page)
for page in second_doc.pages:
	output_doc.pages.add(page)

# save result pdf to file
output_doc.save("Merger_tex_pdf.pdf", aspose.pdf.SaveFormat.PDF)

```