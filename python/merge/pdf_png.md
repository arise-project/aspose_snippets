
new_image = PIL.Image.new('RGB', (new_width, new_height), (250, 250, 250))
offset = 0

# read pdf file to Aspose Document
doc = aspose.pdf.Document("1.pdf")

# setup default resolution to pdf documents 72dpi
# create image device to save document as image with page dimensions and resolution
# process document page to image
# make list pf parsed image sizes
for pageCount in range(1, doc.pages.Count):
	image_device = aspose.pdf.devices.PngDevice(
            doc.pages[pageCount].PageInfo.width, 
            doc.pages[pageCount].PageInfo.height, 
            aspose.pdf.devices.Resolution(72))

	out_path = "test_" + str(pageCount) + ".png"
	image_device.Process(doc.pages[pageCount], out_path)
 	images.append(out_path)
 	image = PIL.Image.open(path)
  	new_image.paste(image, (offset, 0))
   	offset = offset + image.width

new_image.save("Merger_pdf_png.png")

