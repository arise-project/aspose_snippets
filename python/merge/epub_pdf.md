
# create empty pdf document
output_doc = aspose.pdf.Document()

# epub files can be parsed and loaded as Aspose Document
# use algorithm to prevent content to be truncated
# usage of margins area during conversion
opt1 = aspose.pdf.EpubLoadOptions()
opt1.page_size_adjustment_mode = \
asposepdf.LoadOptions.PageSizeAdjustmentModes.ENLARGE_REQUIRED_VIEWPORT_WIDTH_AND_DO_CONVERSION_AGAIN
opt1.margins_area_usage_mode = \
asposepdf.LoadOptions.MarginsAreaUsageModes.PUT_CONTENT_ON_MARGIN_AREA_IF_NECESSARY
first_doc = aspose.pdf.Document("1.epub", opt1)
second_doc = aspose.pdf.Document("2.epub", opt1)

# add page from one document to another directly
for page in first_doc.pages:
	output_doc.pages.add(page)
for page in second_doc.pages:
	output_doc.pages.add(page)
	
# save result pdf to file
output_doc.save("Merger_epub_pdf.pdf", aspose.pdf.SaveFormat.PDF)
