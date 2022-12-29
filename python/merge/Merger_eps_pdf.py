from aspose.pdf import (
    SaveFormat,
    PsLoadOptions,
    Document
)


def eps_to_pdf():
    path_source1 = "../../TestData/test.eps"
    path_source2 = "../../TestData/Second/test.eps"

    # eps files can be parsed and loaded as Aspose Document
    first_doc = Document(path_source1, PsLoadOptions)
    second_doc = Document(path_source2, PsLoadOptions)

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
    output_doc.save("eps_to_pdf.pdf", SaveFormat.PDF)
