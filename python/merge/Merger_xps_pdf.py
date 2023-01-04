from aspose.pdf import (
    SaveFormat,
    XpsLoadOptions,
    Document
)


def xps_to_pdf():
    path_source1 = "../../TestData/test.xps"
    path_source2 = "../../TestData/Second/test.xps"

    # xps files can be parsed and loaded as Aspose Document
    first_doc = Document(path_source1, XpsLoadOptions())
    second_doc = Document(path_source2, XpsLoadOptions())

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
    output_doc.save("Merger_xps_pdf.pdf", SaveFormat.PDF)
