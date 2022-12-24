from Aspose.Pdf import (
    SaveFormat,
    SvgLoadOptions,
    Document
)

def svg_to_pdf(self):
    pathSource1 = "../../TestData/test.svg"
    pathSource2 = "../../TestData/Second/test.svg"

    opt1 = SvgLoadOptions()
    # Adust pdf page size to svg size
    opt1.adjust_page_size = True

    # SVG files can be parsed and loaded as Aspose Document
    firstDoc = Document(pathSource1, opt1)

    opt2 = SvgLoadOptions()
    # Use default pdf page size
    opt2.adjust_page_size = False

    secondDoc = Document(pathSource2, opt2)

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

    # save result pdf to file
    outputDoc.Save("test.pdf", SaveFormat.Pdf)
