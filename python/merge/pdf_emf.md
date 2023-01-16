from aspose.pdf import (
    EpubSaveOptions,
    Document
)


def pdf_to_emf():
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

    opt1 = EpubSaveOptions()
    # keep the logical structure of transformed document
    opt1.content_recognition_mode = EpubSaveOptions.RecognitionMode.PDF_FLOW

    # save pdf to epub
    output_doc.save("Merger_pdf_emf.epub", opt1)
