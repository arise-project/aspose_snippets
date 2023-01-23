```python

# 1. create tiff file to save result
tiff = tifffile.TiffWriter("Merger_pdf_tiff.tiff")

# 2. read pdf file to Aspose Document
doc = aspose.pdf.Document("1.pdf")

# 3. setup default resolution to pdf documents 72dpi
# create image device to save document as image with page dimensions and resolution
# process document page to image
for pageCount in range(1, doc.pages.Length):
    image_device = aspose.pdf.devices.JpegDevice(
        doc.pages[pageCount].PageInfo.width, doc.pages[pageCount].PageInfo.height, aspose.pdf.devices.Resolution(72))
    out_path = "test_" + str(pageCount) + ".jpg"
    image_device.process(doc.pages[pageCount], out_path)

    img = PIL.Image.open(out_path)  # Read the image
    tiff.write(numpy.array(img.getdata(), numpy.uint8).reshape(img.size[1], img.size[0], 3))
```