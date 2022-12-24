from Aspose.Pdf import (
    SaveFormat,
    EpubLoadOptions,
    Document
)

from Aspose.Pdf.LoadOptions import (
    MarginsAreaUsageModes,
    PageSizeAdjustmentModes
)

def epub_to_pdf(self):
    pathSource1 = "../../TestData/test.epub"
    pathSource2 = "../../TestData/Second/test.epub"

    opt1 = EpubLoadOptions()
    # use algorithm to prevent content to be truncated
    opt1.page_size_adjustment_mode = PageSizeAdjustmentModes.ENLARGE_REQUIRED_VIEWPORT_WIDTH_AND_DO_CONVERSION_AGAIN
    # usage of margins area during conversion
    opt1.margins_area_usage_mode = MarginsAreaUsageModes.PUT_CONTENT_ON_MARGIN_AREA_IF_NECESSARY

    # epub files can be parsed and loaded as Aspose Document
    firstDoc = Document(pathSource1, opt1)

    opt2 = EpubLoadOptions()
    # use algorithm to prevent content to be truncated
    opt1.page_size_adjustment_mode = PageSizeAdjustmentModes.ENLARGE_REQUIRED_VIEWPORT_WIDTH_AND_DO_CONVERSION_AGAIN
    # usage of margins area during conversion
    opt1.margins_area_usage_mode = MarginsAreaUsageModes.PUT_CONTENT_ON_MARGIN_AREA_IF_NECESSARY
    secondDoc = Document(pathSource2, opt2)

    # create empty pdf document
    outputDoc = Document()

    # set less memory usage with unload instead of fast performance
    outputDoc.enable_object_unload = True

    for page in firstDoc.Pages:
        # add page from one document to another directly
        outputDoc.Pages.Add(page)

    for page in secondDoc.Pages:
        # add page from one document to another directly
        outputDoc.Pages.Add(page)

    # save result pdf to file
    outputDoc.Save("test.pdf", SaveFormat.Pdf)
