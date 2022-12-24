from aspose.pdf import (
    SaveFormat,
    MhtLoadOptions,
    Document
)

def mht_to_pdf(self):
    pathSource1 = "../../TestData/test.mht"
    pathSource2 = "../../TestData/Second/test.mht"

    # mht files can be parsed and loaded as Aspose Document
    firstDoc = Document(pathSource1, MhtLoadOptions)
    secondDoc = Document(pathSource2,  MhtLoadOptions)

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
