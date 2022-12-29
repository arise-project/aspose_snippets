from aspose.pdf import (
    SaveFormat,
    MdLoadOptions,
    Document
)


def md_to_pdf():
    path_source1 = "../../TestData/test.md"
    path_source2 = "../../TestData/Second/test.md"

    # Markdown files can be parsed and loaded as Aspose Document
    first_doc = Document(path_source1, MdLoadOptions)
    second_doc = Document(path_source2, MdLoadOptions)

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
        output_doc.save("md_to_pdf.pdf", SaveFormat.PDF)
