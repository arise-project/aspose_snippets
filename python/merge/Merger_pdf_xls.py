import aspose.pdf.ExcelSaveOptions as ExcelSaveOptions
from aspose.pdf import (
    ExcelSaveOptions,
    Document
)

def pdf_to_xls(self):
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

    opt1 = ExcelSaveOptions()
    # set Microsoft document type
    opt1.Format = ExcelSaveOptions.ExcelFormat.XMLSpreadSheet2003

    # save Excel document
    outputDoc.Save("test.xls", opt1)
