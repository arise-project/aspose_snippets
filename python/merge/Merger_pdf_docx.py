from aspose.pdf import Document

import aspose.pdf.DocSaveOptions as DocSaveOptions


def pdf_to_docx(self):
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

    opt1 = DocSaveOptions()
    # use docx format
    opt1.Format = DocSaveOptions.DocFormat.DOC_X,
    # make document editable flow and recognize of tables
    opt1.Mode = DocSaveOptions.RecognitionMode.ENHANCED_FLOW

    # save pdf to Microsoft Word docx format
    outputDoc.Save("test.docx", opt1)
