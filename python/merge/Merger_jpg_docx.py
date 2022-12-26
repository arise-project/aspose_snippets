from aspose.pdf import (
    SaveFormat,
    PageSize,
    Rectangle,
    Document
)

from PIL import Image


def jpg_to_docx(self):
    pathSource1 = "../../TestData/test.jpg"
    pathSource2 = "../../TestData/Second/test.jpg"

    # create empty pdf document
    doc = Document

    # set less memory usage with unload instead of fast performance
    doc.enable_object_unload = True

    # make list of files with images to merge
    images = [pathSource1, pathSource2]

    for fs in images:
        # add new page to pdf
        page = doc.Pages.Add()

        # setup page size to be A4
        page.SetPageSize(PageSize.A4.Width, PageSize.A4.Height)

        rect = Rectangle

        # load image from stream, it supports a lot of formats
        image = Image.open(fs)
        # read image dimensions to pdf page rectangle
        image.rect = Rectangle(0, 0, image.Width - 1, image.Heigh - 1)

        # add image to new pdf page
        page.AddImage(fs, rect)

    doc.Save("test.docx", SaveFormat.DOC_X)
