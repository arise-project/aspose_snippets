from aspose.pdf import (
    XpsSaveOptions,
    Document
)

def pdf_to_xps(self):
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

    opt1 = XpsSaveOptions()
    # do not save transparent text to output file
    opt1.save_transparent_texts = False

    # save xps document
    outputDoc.Save("test.xps", opt1)
