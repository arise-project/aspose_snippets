from Aspose.Pdf import (
    SaveFormat,
    PclLoadOptions,
    Document
)

def pcl_to_pdf(self):
    pathSource1 = "../../TestData/test.pcl"
    pathSource2 = "../../TestData/Second/test.pcl"

    # suspend not critical errors
    opt1 = PclLoadOptions()
    opt1.SupressErrors = True

    # pcl files can be parsed and loaded as Aspose Document
    firstDoc = Document(pathSource1, opt1)

    # suspend not critical errors
    opt2 = PclLoadOptions
    opt2.SupressErrors = True
    secondDoc = Document(pathSource2, opt2)

    # create empty pdf document
    outputDoc = Document()

    # set less memory usage with unload instead of fast performance
    outputDoc.EnableObjectUnload = True

    for page in firstDoc.Pages:
        # add page from one document to another directly
        outputDoc.Pages.Add(page)

    for page in secondDoc.Pages:
        # add page from one document to another directly
        outputDoc.Pages.Add(page)

    # save result pdf to file
    outputDoc.Save("test.pdf", SaveFormat.Pdf)
