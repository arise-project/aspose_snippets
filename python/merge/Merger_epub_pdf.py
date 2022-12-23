from Aspose.Pdf import SaveFormat
from Aspose.Pdf.LoadOptions import MarginsAreaUsageModes
from Aspose.Pdf.LoadOptions import PageSizeAdjustmentModes
from Aspose.Pdf import EpubLoadOptions
from Aspose.Pdf import Document
import clr

aspose_pdf = clr.AddReference("../../lib/Aspose.PDF.dll")

class epub_to_pdf(object):
    def __init__(self, licence_path):
        self.dataDir = "../../TestData"
        if licence_path:
            self.licence_path = licence_path
            self.aspose_license = License()
            self.aspose_license.SetLicense(self.licence_path)

    def exec(self):
        pathSource1 = "../../TestData/test.epub"
        pathSource2 = "../../TestData/Second/test.epub"

        opt1 = EpubLoadOptions
        # use algorithm to prevent content to be truncated
        opt1.PageSizeAdjustmentMode = PageSizeAdjustmentModes.EnlargeRequiredViewportWidthAndDoConversionAgain
        # usage of margins area during conversion
        opt1.MarginsAreaUsageMode = MarginsAreaUsageModes.PutContentOnMarginAreaIfNecessary

        # epub files can be parsed and loaded as Aspose Document
        firstDoc = Document(pathSource1, opt1)

        opt2 = EpubLoadOptions
        # use algorithm to prevent content to be truncated
        opt1.PageSizeAdjustmentMode = PageSizeAdjustmentModes.EnlargeRequiredViewportWidthAndDoConversionAgain
        # usage of margins area during conversion
        opt1.MarginsAreaUsageMode = MarginsAreaUsageModes.PutContentOnMarginAreaIfNecessary
        secondDoc = Document(pathSource2, opt2)

        # create empty pdf document
        outputDoc = Document

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
