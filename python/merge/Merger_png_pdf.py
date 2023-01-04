from aspose.pdf import (
    SaveFormat,
    PageSize,
    Rectangle,
    Document
)

from PIL import Image


def png_to_pdf():
    path_source1 = "../../TestData/test.png"
    path_source2 = "../../TestData/Second/test.png"

    # create empty pdf document
    doc = Document()

    # set less memory usage with unload instead of fast performance
    doc.enable_object_unload = True

    # make list of files with images to merge
    images = [path_source1, path_source2]

    for fs in images:
        # add new page to pdf
        page = doc.pages.add()

        # setup page size to be A4
        page.set_page_size(PageSize.a4.width, PageSize.a4.height)

        # load image from stream, it supports a lot of formats
        image = Image.open(fs)
        # read image dimensions to pdf page rectangle
        rect = Rectangle(0, 0, image.width - 1, image.height - 1, True)

        # add image to new pdf page
        page.add_image(fs, rect)

    # save result pdf to file
    doc.save("Merger_png_pdf.pdf", SaveFormat.PDF)
