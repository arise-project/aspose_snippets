from aspose.pdf import (
    SaveFormat,
    MhtLoadOptions,
    Document
)


def mht_to_pdf(self):
    path_source1 = "../../TestData/test.mht"
    path_source2 = "../../TestData/Second/test.mht"

    # mht files can be parsed and loaded as Aspose Document
    first_doc = Document(path_source1, MhtLoadOptions)
    second_doc = Document(path_source2,  MhtLoadOptions)

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
    output_doc.save("test.pdf", SaveFormat.Pdf)
