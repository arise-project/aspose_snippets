from aspose.pdf import (
    SvgSaveOptions,
    Document
)


def pdf_to_svg():
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

    opt1 = SvgSaveOptions()
    # scale the output document from typographic points to pixels
    opt1.scale_to_pixels = True

    # save pdf to svg
    output_doc.save("test.svg", opt1)
