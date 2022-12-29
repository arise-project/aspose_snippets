from aspose.pdf import (
    SaveFormat,
    PageSize,
    Rectangle,
    Document
)

from PIL import Image


def bmp_to_pdf():
    path_source1 = "../../TestData/test.bmp"
    path_source2 = "../../TestData/Second/test.bmp"

    # create empty pdf document
    doc = Document()

    # make list of files with images to merge
    images = [path_source1, path_source2]

    for fs in images:
        # add new page to pdf
        page = doc.pages.add()

        # setup page size to be A4
        page.SetPageSize(PageSize.a4.width, PageSize.a4.height)

        # load image from stream, it supports a lot of formats
        image = Image.open(fs)
        # read image dimensions to pdf page rectangle
        rect = Rectangle(0, 0, image.width - 1, image.height - 1)

        # add image to new pdf page
        page.addImage(fs, rect)

    # save result pdf to file
    doc.save("bmp_to_pdf.pdf", SaveFormat.PDF)

