```python

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

# save pdf to html page
# embed css into a page
# embed images into a page
# enhance conversion of documents with backgrounds
# use fixed layout render
opt1 = aspose.pdf.HtmlSaveOptions()
opt1.parts_embeding_mode = aspose.pdf.HtmlSaveOptions.PartsEmbeddingModes.EMBED_ALL_INTO_HTML
opt1.raster_images_saving_mode = aspose.pdf.HtmlSaveOptions.RasterImagesSavingModes.AS_embedED_PARTS_OF_PNG_PAGE_BACKGROUND
opt1.antialiasing_processing = aspose.pdf.HtmlSaveOptions.AntialiasingProcessingType.TRY_CORRECT_RESULT_HTML
opt1.fixed_layout = True
output_doc.save("Merger_pdf_epub.html", opt1)

```