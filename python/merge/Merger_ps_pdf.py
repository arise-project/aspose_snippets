from aspose.pdf import (
    SaveFormat,
    PsLoadOptions,
    Document
)


def ps_to_pdf(self):
    pathSource1 = "../../TestData/test.ps"
    pathSource2 = "../../TestData/Second/test.ps"

    # PostScript files can be parsed and loaded as Aspose Document
    firstDoc = Document(pathSource1, PsLoadOptions)
    secondDoc = Document(pathSource2, PsLoadOptions)

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
