

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

# save content to text file
# create text absorber for extract text
text_absorber = aspose.pdf.text.TextAbsorber()
output_doc.pages.Accept(text_absorber)
extracted_text = text_absorber.Text
with open("Merger_pdf_text.txt", "w") as f:
	f.write(extracted_text)
