from aspose.pdf import (
    PptxSaveOptions,
    Document
)


def pdf_to_pptx():
    path_source1 = "../../TestData/test.pdf"
    path_source2 = "../../TestData/Second/test.pdf"

    # read pdf file to Aspose Document
    first_doc = Document(path_source1)
    second_doc = Document(path_source2)

    output_doc = Document()
    # set less memory usage with unload instead of fast performance
    output_doc.enable_object_unload = True

    for page in first_doc.pages:
        # add page from one document to another directly
        output_doc.pages.add(page)

    for page in second_doc.pages:
        # add page from one document to another directly
        output_doc.pages.add(page)

    opt1 = PptxSaveOptions()
    # save all content on page as single image
    opt1.slides_as_images = True

    # save pdf to Microsoft PowerPoint
    output_doc.save("test.pptx", opt1)
