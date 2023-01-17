
# create empty pdf document
output_doc = aspose.pdf.Document()

# pcl files can be parsed and loaded as Aspose Document
# suspend not critical errors
opt1 = aspose.pdf.PclLoadOptions()
opt1.supress_errors = True
first_doc = aspose.pdf.Document("1.pcl", opt1)
second_doc = aspose.pdf.Document("2.pcl", opt1)

# add page from one document to another directly        
for page in first_doc.pages:
	output_doc.pages.add(page)
for page in second_doc.pages:
	output_doc.pages.add(page)

# save result pdf to file
output_doc.save("Merger_pcl_pdf.pdf", aspose.pdf.SaveFormat.PDF)
