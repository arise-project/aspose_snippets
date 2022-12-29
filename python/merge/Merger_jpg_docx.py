from aspose.pdf import (
    SaveFormat,
    PageSize,
    Rectangle,
    Document
)

from PIL import Image


def jpg_to_docx():
    path_source1 = "../../TestData/test.jpg"
    path_source2 = "../../TestData/Second/test.jpg"

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
        page.SetPageSize(PageSize.a4.width, PageSize.a4.height)

        # load image from stream, it supports a lot of formats
        image = Image.open(fs)
        # read image dimensions to pdf page rectangle
        rect = Rectangle(0, 0, image.width - 1, image.height - 1)

        # add image to new pdf page
        page.addImage(fs, rect)

    doc.save("jpg_to_docx.docx", SaveFormat.DOC_X)
