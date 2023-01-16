from aspose.pdf import Document
from PIL import Image


def pdf_to_jpeg():
    path_source = "../../TestData/test.pdf"

    # read pdf file to Aspose Document
    doc = Document(path_source)

    # make list of path to temporary images
    images = []

    # pages in pdf counted from 1 to n
    for pageCount in range(1, doc.pages.Count):
        # setup default resolution to pdf documents 72dpi
        resolution = aspose.pdf.devices.Resolution(72)

        # create image device to save document as image with page dimensions and resolution
        image_device = aspose.pdf.devices.JpegDevice(
            doc.pages[pageCount].PageInfo.width, doc.pages[pageCount].PageInfo.height, resolution)

        out_path = "test_" + str(pageCount) + ".jpg"

        # process document page to image
        image_device.Process(doc.pages[pageCount], out_path)
        images.append(out_path)

    # make list pf parsed image sizes
    new_width = 0
    new_height = 0
    for path in images:
        # load image from file, it supports a lot of formats
        image = Image.open(path)
        new_width += image.width
        if new_height < image.height:
            new_height = image.height
        else:
            new_height = new_height

    new_image = Image.new('RGB', (new_width, new_height), (250, 250, 250))

    offset = 0
    for path in images:
        image = Image.open(path)
        new_image.paste(image, (offset, 0))
        offset = offset + image.width

    new_image.save("Merger_pdf_jpeg.jpg")

