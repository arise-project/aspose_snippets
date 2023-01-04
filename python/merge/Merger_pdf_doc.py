from aspose.pdf import (
    DocSaveOptions,
    Document
)


def pdf_to_doc():
    path_source1 = "../../TestData/test.pdf"
    path_source2 = "../../TestData/Second/test.pdf"

    # read pdf file to Aspose Document
    first_doc = Document(path_source1)
    second_doc = Document(path_source2)

    # create empty pdf document
    output_doc = Document()

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
    opt1.format = DocSaveOptions.DocFormat.DOC
    # This mode is fast and good for maximally preserving original look
    opt1.mode = DocSaveOptions.RecognitionMode.TEXTBOX

    # save pdf to Microsoft Word doc format
    output_doc.save("Merger_pdf_doc.doc", opt1)
