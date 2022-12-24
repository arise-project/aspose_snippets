from aspose.pdf import (
    DocSaveOptions,
    Document
)

import aspose.pdf.DocSaveOptions as DocSaveOptions

def pdf_to_doc(self):
    pathSource1 = "../../TestData/test.pdf"
    pathSource2 = "../../TestData/Second/test.pdf"

    # read pdf file to Aspose Document
    firstDoc = Document(pathSource1)
    secondDoc = Document(pathSource2)

    # create empty pdf document
    outputDoc = Document

    # set less memory usage with unload instead of fast performance
    outputDoc.enable_object_unload = True

    for page in firstDoc.Pages:
        # add page from one document to another directly
        outputDoc.Pages.Add(page)

    for page in secondDoc.Pages:
        # add page from one document to another directly
        outputDoc.Pages.Add(page)

    opt1 = DocSaveOptions()
    # use doc format
    opt1.Format = DocSaveOptions.DocFormat.Doc,
    # This mode is fast and good for maximally preserving original look
    opt1.Mode = DocSaveOptions.RecognitionMode.Textbox

    # save pdf to Microsoft Word doc format
    outputDoc.Save("test.doc", opt1)
