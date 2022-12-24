from aspose.pdf import (
    SaveFormat,
    CgmLoadOptions,
    Document
)

def cgm_to_pdf():
    pathSource1 = "../../TestData/test.cgm"
    pathSource2 = "../../TestData/Second/test.cgm"

    # /cgm files can be parsed and loaded as Aspose Document
    firstDoc = Document(pathSource1, CgmLoadOptions)
    secondDoc = Document(pathSource2, CgmLoadOptions)

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
