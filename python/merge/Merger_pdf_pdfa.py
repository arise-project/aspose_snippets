from Aspose.Pdf import (
    ConvertErrorAction,
    PdfFormat,
    Document
)

def pdf_to_pdfa(self):
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

    # save document as specific pdf standard PDFA 3Y
    # delete objects that impossible to convert
    outputDoc.Convert("test.pdf", PdfFormat.PDF_A_3U, ConvertErrorAction.Delete)
