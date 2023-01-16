from aspose.pdf import (
    SaveFormat,
    SvgLoadOptions,
    Document
)


def svg_to_pdf():
    path_source1 = "../../TestData/test.svg"
    path_source2 = "../../TestData/Second/test.svg"

    opt1 = SvgLoadOptions()
    # Adust pdf page size to svg size
    opt1.adjust_page_size = True

    # SVG files can be parsed and loaded as Aspose Document
    first_doc = Document(path_source1, opt1)

    opt2 = SvgLoadOptions()
    # Use default pdf page size
    opt2.adjust_page_size = False

    second_doc = Document(path_source2, opt2)

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

    # save result pdf to file
    output_doc.save("Merger_svg_pdf.pdf", SaveFormat.PDF)
