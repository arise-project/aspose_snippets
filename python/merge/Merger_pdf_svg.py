from aspose.pdf import (
    SvgSaveOptions,
    Document
)


def pdf_to_svg(self):
    pathSource1 = "../../TestData/test.pdf"
    pathSource2 = "../../TestData/Second/test.pdf"

    # read pdf file to Aspose Document
    firstDoc = Document(pathSource1)
    secondDoc = Document(pathSource2)

    # create empty pdf document
    outputDoc = Document()

    # set less memory usage with unload instead of fast performance
    outputDoc.enable_object_unload = True

    for page in firstDoc.Pages:
        # add page from one document to another directly
        outputDoc.Pages.Add(page)

    for page in secondDoc.Pages:
        # add page from one document to another directly
        outputDoc.Pages.Add(page)

    opt1 = SvgSaveOptions()
    # scale the output document from typographic points to pixels
    opt1.scale_to_pixels = True

    # save pdf to svg
    outputDoc.Save("test.svg", opt1)
