import clr

aspose_pdf = clr.AddReference("../../lib/Aspose.PDF.dll")

from System import TimeSpan
from Aspose.Pdf import Document

class pdf_to_bmp(object):
    def __init__(self,licence_path):
        self.dataDir = "../../TestData"
        if licence_path:
            self.licence_path = licence_path
            self.aspose_license = License()
            self.aspose_license.SetLicense(self.licence_path)

    def exec(self):

        