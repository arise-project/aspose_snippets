new_image = PIL.Image.new('RGB', (new_width, new_height), (250, 250, 250))

# read pdf file to Aspose Document
doc = aspose.pdf.Document(path_source)
offset = 0

# setup default resolution to pdf documents 72dpi 	
# create image device to save document as image with page dimensions and resolution
# process document page to image
for pageCount in range(1, doc.pages.Count):
	image_device = aspose.pdf.devices.JpegDevice(
 		doc.pages[pageCount].PageInfo.width, 
   		doc.pages[pageCount].PageInfo.height, 
     	aspose.pdf.devices.Resolution(72))

	out_path = "test_" + str(pageCount) + ".jpg"

	aspose.pdf.image_device.Process(doc.pages[pageCount], out_path)
 	image = PIL.Image.open(path)
 	new_image.paste(image, (offset, 0))
  	offset = offset + image.width
	
new_image.save("Merger_pdf_jpeg.jpg")

