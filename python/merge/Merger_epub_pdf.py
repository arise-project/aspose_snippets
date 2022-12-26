from aspose.pdf import (
    SaveFormat,
    EpubLoadOptions,
    Document
)

import aspose.pdf.LoadOptions as LoadOptions


def epub_to_pdf():
    path_source1 = "../../TestData/test.epub"
    path_source2 = "../../TestData/Second/test.epub"

    opt1 = EpubLoadOptions()
    # use algorithm to prevent content to be truncated
    opt1.page_size_adjustment_mode = \
        LoadOptions.pagesizeAdjustmentModes.ENLARGE_REQUIRED_VIEWPORT_WIDTH_AND_DO_CONVERSION_AGAIN
    # usage of margins area during conversion
    opt1.margins_area_usage_mode = \
        LoadOptions.MarginsAreaUsageModes.PUT_CONTENT_ON_MARGIN_AREA_IF_NECESSARY

    # epub files can be parsed and loaded as Aspose Document
    first_doc = Document(path_source1, opt1)

    opt2 = EpubLoadOptions
    # use algorithm to prevent content to be truncated
    opt1.page_size_adjustment_mode = \
        LoadOptions.pagesizeAdjustmentModes.ENLARGE_REQUIRED_VIEWPORT_WIDTH_AND_DO_CONVERSION_AGAIN
    # usage of margins area during conversion
    opt1.margins_area_usage_mode = \
        LoadOptions.MarginsAreaUsageModes.PUT_CONTENT_ON_MARGIN_AREA_IF_NECESSARY
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
    output_doc.save("test.pdf", SaveFormat.Pdf)
