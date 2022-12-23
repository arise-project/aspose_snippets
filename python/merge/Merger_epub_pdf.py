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
    opt1.PageSizeAdjustmentMode = PageSizeAdjustmentModes.EnlargeRequiredViewportWidthAndDoConversionAgain
    # usage of margins area during conversion
    opt1.MarginsAreaUsageMode = MarginsAreaUsageModes.PutContentOnMarginAreaIfNecessary

    # epub files can be parsed and loaded as Aspose Document
    firstDoc = Document(pathSource1, opt1)

    opt2 = EpubLoadOptions()
    # use algorithm to prevent content to be truncated
    opt1.PageSizeAdjustmentMode = PageSizeAdjustmentModes.EnlargeRequiredViewportWidthAndDoConversionAgain
    # usage of margins area during conversion
    opt1.MarginsAreaUsageMode = MarginsAreaUsageModes.PutContentOnMarginAreaIfNecessary
    secondDoc = Document(pathSource2, opt2)

    # create empty pdf document
    outputDoc = Document()

    # set less memory usage with unload instead of fast performance
    outputDoc.EnableObjectUnload = True

    for page in firstDoc.Pages:
        # add page from one document to another directly
        outputDoc.Pages.Add(page)

    for page in secondDoc.Pages:
        # add page from one document to another directly
        outputDoc.Pages.Add(page)

    # save result pdf to file
    outputDoc.Save("test.pdf", SaveFormat.Pdf)
