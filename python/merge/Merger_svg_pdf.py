from Aspose.Pdf import SaveFormat
from Aspose.Pdf import SvgLoadOptions
from Aspose.Pdf import Document
import clr

aspose_pdf = clr.AddReference("../../lib/Aspose.PDF.dll")

class svg_to_pdf(object):
    def __init__(self, licence_path):
        self.dataDir = "../../TestData"
        if licence_path:
            self.licence_path = licence_path
            self.aspose_license = License()
            self.aspose_license.SetLicense(self.licence_path)

    def exec(self):
        pathSource1 = "../../TestData/test.svg"
        pathSource2 = "../../TestData/Second/test.svg"

        opt1 = SvgLoadOptions
        # Adust pdf page size to svg size
        opt1.AdjustPageSize = True

        # SVG files can be parsed and loaded as Aspose Document
        firstDoc = Document(pathSource1, opt1)

        opt2 = SvgLoadOptions
        # Use default pdf page size
        opt2.AdjustPageSize = False

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
