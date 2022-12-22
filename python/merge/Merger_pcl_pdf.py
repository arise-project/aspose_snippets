from Aspose.Pdf import SaveFormat
from Aspose.Pdf import PclLoadOptions
from Aspose.Pdf import Document
import clr

aspose_pdf = clr.AddReference("../../lib/Aspose.PDF.dll")

class pcl_to_pdf(object):
    def __init__(self, licence_path):
        self.dataDir = "../../TestData"
        if licence_path:
            self.licence_path = licence_path
            self.aspose_license = License()
            self.aspose_license.SetLicense(self.licence_path)

    def exec(self):
        pathSource1 = "../../TestData/test.pcl"
        pathSource2 = "../../TestData/Second/test.pcl"

        # suspend not critical errors
        opt1 = PclLoadOptions
        opt1.SupressErrors = True

        # pcl files can be parsed and loaded as Aspose Document
        firstDoc = Document(pathSource1, opt1)

        # suspend not critical errors
        opt2 = PclLoadOptions
        opt2.SupressErrors = True
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
