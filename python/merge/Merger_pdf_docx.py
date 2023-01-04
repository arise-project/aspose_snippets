from aspose.pdf import (
    DocSaveOptions,
    Document
)


def pdf_to_docx():
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
    # use docx format
    opt1.format = DocSaveOptions.DocFormat.DOC_X
    # make document editable flow and recognize of tables
    opt1.mode = DocSaveOptions.RecognitionMode.ENHANCED_FLOW

    # save pdf to Microsoft Word docx format
    output_doc.save("Merger_pdf_docx.docx", opt1)
