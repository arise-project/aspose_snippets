from aspose.pdf import (
    DocSaveOptions,
    Document
)

import aspose.pdf.DocSaveOptions as DocSaveOptions


def pdf_to_doc(self):
    path_source1 = "../../TestData/test.pdf"
    path_source2 = "../../TestData/Second/test.pdf"

    # read pdf file to Aspose Document
    first_doc = Document(path_source1)
    second_doc = Document(path_source2)

    # create empty pdf document
    output_doc = Document

    # set less memory usage with unload instead of fast performance
    output_doc.enable_object_unload = True

    for page in first_doc.pages:
        # add page from one document to another directly
        output_doc.pages.add(page)

    for page in second_doc.pages:
        # add page from one document to another directly
        output_doc.pages.add(page)

    opt1 = DocSaveOptions()
    # use doc format
    opt1.Format = DocSaveOptions.DocFormat.Doc,
    # This mode is fast and good for maximally preserving original look
    opt1.Mode = DocSaveOptions.RecognitionMode.Textbox

    # save pdf to Microsoft Word doc format
    output_doc.save("test.doc", opt1)
