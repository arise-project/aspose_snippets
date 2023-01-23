```python

# 1. create empty pdf document
output_doc = aspose.pdf.Document

# 2. Read tiff file
multi_image1 = tifffile.imread("1.tiff")


# 3. iterate through tiff frames
# set active frame to work with
# add new page to document
# create new image into document
# set image source to memory stream
# add document image to specific page
for frame in range(0, multiImage.n_frames):
    multiImage.seek(frame)
    fp = io.BytesIO()
    format = Image.registered_extensions()['.' + "jpg"]
    multiImage.save(fp, format)
    page = output_doc.pages.add()
    image = PdfImage
    image.image_stream = fp
    page.Paragraphs.add(image)

# 4. save result pdf to file
output_doc.save("Merger_tiff_pdf.pdf", SaveFormat.Pdf)
```