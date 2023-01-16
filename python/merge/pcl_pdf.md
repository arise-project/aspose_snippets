from aspose.pdf import (
    SaveFormat,
    PclLoadOptions,
    Document
)


def pcl_to_pdf():
    path_source1 = "../../TestData/test.pcl"
    path_source2 = "../../TestData/Second/test.pcl"

    # suspend not critical errors
    opt1 = PclLoadOptions()
    opt1.supress_errors = True

    # pcl files can be parsed and loaded as Aspose Document
    first_doc = Document(path_source1, opt1)

    # suspend not critical errors
    opt2 = PclLoadOptions
    opt2.supress_errors = True
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
    output_doc.save("Merger_pcl_pdf.pdf", SaveFormat.PDF)
