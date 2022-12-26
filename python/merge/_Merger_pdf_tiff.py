from aspose.pdf import (
    Document
)

from PIL import Image
import tifffile
import numpy


def pdf_to_tiff():
    path_source1 = "../../TestData/test.pdf"

    # read pdf file to Aspose Document
    doc = Document(path_source1)

    # make list of Aspose images

    frames = []  # Empty list of frames
    first_size = None  # I am going to say that the first file is the right size

    # pdf document count pages from 1 to n
    for pageCount in range(1, doc.pages.Length):
        # setup default resolution to pdf documents 72dpi
        resolution = aspose.pdf.devices.Resolution(72)

        # create image device to save document as image with page dimensions and resolution
        image_device = aspose.pdf.devices.JpegDevice(
            doc.pages[pageCount].PageInfo.width, doc.pages[pageCount].PageInfo.height, resolution)

        out_path = "test_" + str(pageCount) + ".jpg"

        # process document page to image
        image_device.process(doc.pages[pageCount], out_path)

        img = Image.open(out_path)  # Read the image
        if first_size is None:  # Don't have a size
            first_size = img.size  # So use this one
        frames.append(img)  # Add it to our frames list

    with tifffile.TiffWriter("test.tiff") as tiff:
        for img in frames:
            tiff.write(numpy.array(img.getdata(), numpy.uint8).reshape(img.size[1], img.size[0], 3))
